module;
#include <PxPhysicsAPI.h>
#include <fstream>
export module physxEngine;
import Struct;
import std;
import physxLocal;

using namespace physx;

export class physxEngine {
public:

	inline static std::shared_mutex sceneMutex;

	static bool InitPhysx();

	static void ReleasePhysx();


	static PxConvexMesh* createBVConvexMesh(PxU32 numVerts, const PxVec3* verts);

	static PxTriangleMesh* createBV34TriangleMesh(PxU32 numVertices, const PxVec3* vertices, PxU32 numTriangles, const PxU32* indices,
		bool skipMeshCleanup, bool skipEdgeData, bool inserted, const PxU32 numTrisPerLeaf , TriangleMeshInfo* triangleMeshInfo = nullptr);

	static void setupCommonCookingParams(PxCookingParams& params, bool skipMeshCleanup, bool skipEdgeData);

	static PxRaycastBuffer LineTraceSingle(FVector3D orgin, FVector3D dest);

	static PxRaycastBuffer LineTraceSingle1(FVector3D orgin, FVector3D dir);

	static bool SaveScene(const char* filename);

	static bool LoadScene(const char* filename);

public:


	inline static PxFoundation* gFoundarion = nullptr;
	inline static PxPhysics* gPhysics = nullptr;
	inline static PxDefaultCpuDispatcher* gCpuDispatcher = nullptr;
	inline static PxCudaContextManager* gcudaContext = nullptr;
	inline static PxScene* gScene = nullptr;
	inline static PxMaterial* gMaterial = nullptr;


	inline static PxDefaultAllocator gAllocator{};
	inline static PxDefaultErrorCallback gErrorCallback{};

	inline static PxCooking* gCooking{};




};



bool physxEngine::InitPhysx()
{

	gFoundarion = PxCreateFoundation(PX_PHYSICS_VERSION, gAllocator, gErrorCallback);

	if (gFoundarion == nullptr) {
		return false;
	}

	gPhysics = PxCreatePhysics(PX_PHYSICS_VERSION, *gFoundarion, PxTolerancesScale());


	if (gPhysics == nullptr) {
		return false;
	}

	PxSceneDesc sceneDesc(gPhysics->getTolerancesScale());
	sceneDesc.gravity = PxVec3(0, -9.81f, 0);

	gCpuDispatcher = PxDefaultCpuDispatcherCreate(4);

	sceneDesc.cpuDispatcher = gCpuDispatcher;
	sceneDesc.flags |= PxSceneFlag::eENABLE_GPU_DYNAMICS;
	sceneDesc.flags |= PxSceneFlag::eENABLE_PCM;
	sceneDesc.flags |= PxSceneFlag::eENABLE_STABILIZATION;
	sceneDesc.broadPhaseType = PxBroadPhaseType::eGPU;
	sceneDesc.filterShader = PxDefaultSimulationFilterShader;

	sceneDesc.gpuMaxNumPartitions = 8;

	gScene = gPhysics->createScene(sceneDesc);

	if (gScene == nullptr) {
		return false;
	}


	gMaterial = gPhysics->createMaterial(0.5f, 0.5f, 0.2f);

	if (gMaterial == nullptr) {
		return false;
	}


	gCooking = PxCreateCooking(PX_PHYSICS_VERSION, *gFoundarion, PxCookingParams(PxTolerancesScale()));

	if (gCooking == nullptr) {
		return false;
	
	}

	return true;
}


void physxEngine::ReleasePhysx()
{
	// 1️⃣ 释放场景
	if (gScene) {
		gScene->release();
		gScene = nullptr;
	}

	// 2️⃣ 释放 CPU Dispatcher
	if (gCpuDispatcher) {
		gCpuDispatcher->release();
		gCpuDispatcher = nullptr;
	}

	// 3️⃣ 释放材质
	if (gMaterial) {
		gMaterial->release();
		gMaterial = nullptr;
	}

	// 4️⃣ 释放 Cooking
	if (gCooking) {
		gCooking->release();
		gCooking = nullptr;
	}

	// 5️⃣ 释放 Physics
	if (gPhysics) {
		gPhysics->release();
		gPhysics = nullptr;
	}

	// 6️⃣ 释放 Foundation（最后一个）
	if (gFoundarion) {
		gFoundarion->release();
		gFoundarion = nullptr;
	}
}




bool physxEngine::SaveScene(const char* filename)
{
	if (!gScene || !gPhysics || !gCooking)
		return false;

	// 创建序列化注册表
	PxSerializationRegistry* registry = PxSerialization::createSerializationRegistry(*gPhysics);
	if (!registry)
		return false;

	// 创建集合
	PxCollection* collection = PxCreateCollection();

	// 1. 首先保存所有材质（重要！）
	PxU32 nbMaterials = gPhysics->getNbMaterials();
	std::vector<PxMaterial*> materials(nbMaterials);
	gPhysics->getMaterials(materials.data(), nbMaterials);
	for (PxU32 i = 0; i < nbMaterials; i++)
	{
		collection->add(*materials[i]);
	}

	// 2. 保存所有刚体和形状
	PxU32 nbActors = gScene->getNbActors(PxActorTypeFlag::eRIGID_DYNAMIC | PxActorTypeFlag::eRIGID_STATIC);
	std::vector<PxActor*> actors(nbActors);
	gScene->getActors(PxActorTypeFlag::eRIGID_DYNAMIC | PxActorTypeFlag::eRIGID_STATIC, actors.data(), nbActors);

	for (PxU32 i = 0; i < nbActors; i++)
	{
		if (PxRigidActor* rigid = actors[i]->is<PxRigidActor>())
		{
			collection->add(*rigid);

			// 遍历刚体的所有形状
			PxU32 nbShapes = rigid->getNbShapes();
			std::vector<PxShape*> shapes(nbShapes);
			rigid->getShapes(shapes.data(), nbShapes);
			for (PxU32 j = 0; j < nbShapes; j++)
			{
				collection->add(*shapes[j]);
			}
		}
	}

	// 3. 使用complete自动添加其他依赖项
	PxSerialization::complete(*collection, *registry);

	// 4. 序列化
	PxDefaultMemoryOutputStream outStream;
	bool success = PxSerialization::serializeCollectionToBinary(outStream, *collection, *registry);

	if (success && outStream.getSize() > 0)
	{
		std::ofstream file(filename, std::ios::binary);
		if (file.is_open())
		{
			file.write(reinterpret_cast<const char*>(outStream.getData()), outStream.getSize());
			file.close();
			std::cout << "Scene saved with " << nbActors << " actors and "
				<< nbMaterials << " materials" << std::endl;
		}
		else
		{
			success = false;
		}
	}

	collection->release();
	registry->release();

	return success;
}

bool physxEngine::LoadScene(const char* filename)
{
	if (!gPhysics || !gCooking || !gScene)
		return false;


	// 读取文件到内存
	std::ifstream file(filename, std::ios::binary | std::ios::ate);
	if (!file.is_open())
	{
		std::cerr << "Failed to open file: " << filename << std::endl;
		return false;
	}

	std::streamsize size = file.tellg();
	file.seekg(0, std::ios::beg);

	// 确保内存对齐 - 使用PxU8数组
	std::vector<PxU8> buffer(size);
	if (!file.read(reinterpret_cast<char*>(buffer.data()), size))
	{
		std::cerr << "Failed to read file: " << filename << std::endl;
		file.close();
		return false;
	}
	file.close();

	// 创建序列化注册表
	PxSerializationRegistry* registry = PxSerialization::createSerializationRegistry(*gPhysics);
	if (!registry)
	{
		std::cerr << "Failed to create serialization registry" << std::endl;
		return false;
	}

	// 使用正确的参数：void* memBlock
	PxCollection* collection = PxSerialization::createCollectionFromBinary(
		buffer.data(),  // void* memBlock
		*registry,      // PxSerializationRegistry& sr
		nullptr         // const PxCollection* externalRefs = NULL
	);

	if (!collection)
	{
		std::cerr << "Failed to create collection from binary data" << std::endl;
		registry->release();
		return false;
	}

	// 添加对象到场景
	PxU32 nbObjects = collection->getNbObjects();
	std::cout << "Loading " << nbObjects << " objects" << std::endl;

	// 先添加静态物体
	for (PxU32 i = 0; i < nbObjects; i++)
	{
		PxBase* obj = &collection->getObject(i);
		if (obj->is<PxRigidStatic>())
		{
			PxRigidStatic* actor = static_cast<PxRigidStatic*>(obj);
			gScene->addActor(*actor);
		}
	}

	// 再添加动态物体
	for (PxU32 i = 0; i < nbObjects; i++)
	{
		PxBase* obj = &collection->getObject(i);
		if (obj->is<PxRigidDynamic>())
		{
			PxRigidDynamic* actor = static_cast<PxRigidDynamic*>(obj);
			gScene->addActor(*actor);

			// 确保动态物体被唤醒
			actor->wakeUp();
		}
	}

	// 验证加载结果
	PxU32 sceneActorCount = gScene->getNbActors(PxActorTypeFlag::eRIGID_DYNAMIC | PxActorTypeFlag::eRIGID_STATIC);
	std::cout << "Scene now has " << sceneActorCount << " actors" << std::endl;

	// 注意：不要释放collection中的对象，因为它们现在由场景管理
	collection->release();
	registry->release();

	return true;
}

PxConvexMesh* physxEngine::createBVConvexMesh(PxU32 numVerts, const PxVec3* verts) {

	PxCookingParams params = gCooking->getParams();

	params.convexMeshCookingType = PxConvexMeshCookingType::eQUICKHULL;
	params.gaussMapLimit = 256;
	gCooking->setParams(params);
	PxConvexMeshDesc desc;

	desc.points.data = verts;
	desc.points.count = numVerts;
	desc.points.stride = sizeof(PxVec3);
	desc.flags = PxConvexFlag::eCOMPUTE_CONVEX;
	PxU32 meshSize = 0;
	PxConvexMesh* convex = NULL;

	convex = gCooking->createConvexMesh(desc, gPhysics->getPhysicsInsertionCallback());
	PX_ASSERT(convex);
	return convex;

}

PxTriangleMesh* physxEngine::createBV34TriangleMesh(PxU32 numVertices, const PxVec3* vertices, PxU32 numTriangles, const PxU32* indices,
	bool skipMeshCleanup, bool skipEdgeData, bool inserted, const PxU32 numTrisPerLeaf , TriangleMeshInfo* triangleMeshInfo)
{


	PxTriangleMeshDesc meshDesc;
	meshDesc.points.count = numVertices;
	meshDesc.points.data = vertices;
	meshDesc.points.stride = sizeof(PxVec3);
	meshDesc.triangles.count = numTriangles;
	meshDesc.triangles.data = indices;
	meshDesc.triangles.stride = 3 * sizeof(PxU32);

	PxCookingParams params = gCooking->getParams();


	params.midphaseDesc = PxMeshMidPhase::eBVH34;


	setupCommonCookingParams(params, skipMeshCleanup, skipEdgeData);

	params.midphaseDesc.mBVH34Desc.numPrimsPerLeaf = numTrisPerLeaf;

	gCooking->setParams(params);

#if defined(PX_CHECKED) || defined(PX_DEBUG)

	if (skipMeshCleanup)
	{
		PX_ASSERT(gCooking->validateTriangleMesh(meshDesc));
	}
#endif // DEBUG


	PxTriangleMesh* triMesh = NULL;

	if (inserted)
	{
		triMesh = gCooking->createTriangleMesh(meshDesc, gPhysics->getPhysicsInsertionCallback());
	}
	else
	{

		PxDefaultMemoryOutputStream outBuffer;
		gCooking->cookTriangleMesh(meshDesc, outBuffer);

		if (triangleMeshInfo != nullptr) {
			triangleMeshInfo->CookIngSize = outBuffer.getSize();
			if (triangleMeshInfo->CookIngSize > 0) {
				triangleMeshInfo->CookIngData = new physx::PxU8[triangleMeshInfo->CookIngSize];
				std::memcpy(triangleMeshInfo->CookIngData, outBuffer.getData(), triangleMeshInfo->CookIngSize);
			}
		}


		PxDefaultMemoryInputData stream(outBuffer.getData(), outBuffer.getSize());
		triMesh = gPhysics->createTriangleMesh(stream);



	}

	return triMesh;
	//triMesh->release();
}




void physxEngine::setupCommonCookingParams(PxCookingParams& params, bool skipMeshCleanup, bool skipEdgeData)
{

	params.suppressTriangleMeshRemapTable = true;

	if (!skipMeshCleanup)
		params.meshPreprocessParams &= ~static_cast<PxMeshPreprocessingFlags>(PxMeshPreprocessingFlag::eDISABLE_CLEAN_MESH);
	else
		params.meshPreprocessParams |= PxMeshPreprocessingFlag::eDISABLE_CLEAN_MESH;


	if (!skipEdgeData)
		params.meshPreprocessParams &= ~static_cast<PxMeshPreprocessingFlags>(PxMeshPreprocessingFlag::eDISABLE_ACTIVE_EDGES_PRECOMPUTE);
	else
		params.meshPreprocessParams |= PxMeshPreprocessingFlag::eDISABLE_ACTIVE_EDGES_PRECOMPUTE;
}

PxRaycastBuffer physxEngine::LineTraceSingle(FVector3D orgin, FVector3D dest)
{
	PxVec3 ori{ orgin.X , orgin.Y , orgin.Z };
	PxVec3 des{ dest.X , dest.Y , dest.Z };
	PxVec3 dir = des - ori;
	PxReal length = dir.magnitude();
	dir /= length;
	PxRaycastBuffer hit{};
	std::shared_lock<std::shared_mutex> lock(sceneMutex);
	if (gScene) {
		gScene->raycast(ori, dir, length, hit);
	}

	// Log raycast result
	//if (hit.hasAnyHits()) {
	//	std::cout << "Raycast hit: " << hit.getNbAnyHits() << " objects" << std::endl;
	//}
	//else {
	//	std::cout << "Raycast miss" << std::endl;
	//}

	return hit;
}


PxRaycastBuffer physxEngine::LineTraceSingle1(FVector3D orgin, FVector3D dir)
{
	PxVec3 ori{ orgin.X , orgin.Y , orgin.Z };
	PxVec3 dir1{ dir.X , dir.Y , dir.Z };

	PxRaycastBuffer hit{};
	std::shared_lock<std::shared_mutex> lock(sceneMutex);
	if (gScene) {
		gScene->raycast(ori, dir1, 30000, hit);
	}

	return hit;
}