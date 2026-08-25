module;
#include <PxPhysicsAPI.h>
#include <imgui.h>
import Struct;
import Engine;
export module PhysX3;
import dma;
import Offsets_PhysX3;
import Struct_PhysX3;
import PhNpSenceArray;
import std;
import PhPxRigidDynamic;
import PhPxRigidStatic;
import PhNpShape;
import <cstdint>;
import physxEngine;
import physxLocal;


export using::physx::PxRigidActor;
export using::physx::PxShape;
export using::physx::PxGeometryType;
export using::physx::PxTriangleMeshGeometry;
export using::physx::PxBoxGeometry;

export using::physx::PxTriangleMeshFlag;
export using::physx::PxU32;
export using::physx::PxVec3;
export using::physx::PxVec2;
export using::physx::PxMat44;
export using::physx::PxActorTypeFlag;
export using::physx::PxActorTypeFlags;
export using::physx::PxActor;


namespace std {
/*
	template<>
	struct hash<physx::PxVec3> 
	{
		std::size_t operator()(const physx::PxVec3& k) const noexcept{
			int x = k.x;
			int y = k.x;
			int z = k.x;

			std::size_t h1 = std::hash<int>{}(x);
			std::size_t h2 = std::hash<int>{}(y);
			std::size_t h3 = std::hash<int>{}(z);
			
			return h1 ^ (h2 + 0x9e3779b9 + (h1 << 6) + (h1 >> 2) + h3);
		}


	};
*/

}


export class PhysX3 {
public:
	PhysX3() = default;

	static bool init() ;

	static PhNpSenceArray GetNpSencePArray();


	static void runPhysx(const char* filename);

	static void loadPhysx(const char* filename);

	static void clearPhysx();

private:
	static inline int64_t ptr = 0;

	static inline std::unordered_set<int64_t> gLoadSet{};

};

bool PhysX3::init() 
{
	int64_t addr = dma::ProcessGetModuleBaseU(Offsets_PhysX3::Base::Physicsdll);
	ptr = dma::Read<int64_t>(addr + Offsets_PhysX3::Base::Physics);

	if (!ptr) { return false; }


	if (!physxEngine::InitPhysx()) { return false; }

	return true;

}

PhNpSenceArray PhysX3::GetNpSencePArray()
{
	return PhNpSenceArray(ptr + Offsets_PhysX3::Phystcs::NpScenePArray);
}



void PhysX3::runPhysx(const char* filename) {

	if (!std::filesystem::exists("model/")) {
		std::filesystem::create_directory("model");
	}

	auto filePath = "model/" + std::string(filename);

	auto npSencePArray = GetNpSencePArray();


	for (int iii = 0; iii < npSencePArray.NumElements; iii++)
	{
		auto npSence = npSencePArray[iii];
		auto phPxActors = npSence.GetPxActorsPArray();


		std::vector<int64_t> ActorsPtrArr(phPxActors.NumElements);
		dma::Read(phPxActors.Data, ActorsPtrArr.data(), phPxActors.NumElements * sizeof(int64_t));

		for (auto& actorPtr : ActorsPtrArr) {

			if (gLoadSet.count(actorPtr)) {
				continue;
			}

			PhPxActor pxActor(actorPtr, true);
			auto ConcreteType = pxActor.GetmConcreteType();
			Physx3::PhNpShapeManager shapeManager{};
			physx::PxTransform GlobalPos{};

			physx::PxRigidActor* tmpActor{};

			if (ConcreteType == 6) {
				//std::println("PhysX3 动态刚体");
				PhPxRigidDynamic dynamicActor(pxActor.GetPrt(), true);
				auto body2Actor = dynamicActor.Getbody2Actor();
				auto body2World = dynamicActor.GetmBufferedBody2World();
				GlobalPos = body2World * body2Actor.getInverse();


				if (!GlobalPos.isValid()) {
					//std::println("PhysX3 动态刚体 坐标无效");
					continue;
				}

				shapeManager = dynamicActor.GetmShapeManager();
				tmpActor = physxEngine::gPhysics->createRigidDynamic(GlobalPos);
			}
			else if (ConcreteType == 7) {
				//std::println("PhysX3 静态刚体");
				PhPxRigidStatic staticActor(pxActor.GetPrt(), true);
				GlobalPos = staticActor.GetBody2World();

				if (!GlobalPos.isValid()) {
					//std::println("PhysX3 静态刚体 坐标无效");
					continue;
				}

				shapeManager = staticActor.GetmShapeManager();
				tmpActor = physxEngine::gPhysics->createRigidStatic(GlobalPos);
			}
			else {
				if (tmpActor) {
					tmpActor->release();
				}

				continue;
			}

			if (GlobalPos.p.x == 0 || GlobalPos.p.y == 0) {
				// std::println("PhysX3 坐标为0");
				tmpActor->release();
				continue;
			}
			
			/*
			if (gLoadSet.count(GlobalPos.p)) {
				//std::println("PhysX3 坐标重复");
				tmpActor->release();
				continue;
			}
			*/



			std::vector<int64_t> shapePtrArr(shapeManager.mShapes.mCount);

			if (shapeManager.mShapes.mCount == 1) {
				shapePtrArr.push_back(shapeManager.mShapes.mSingle);
			}
			else {
				dma::Read(shapeManager.mShapes.mSingle, shapePtrArr.data(), shapeManager.mShapes.mCount * sizeof(int64_t));
			}

			for (auto& shapePtr : shapePtrArr) {

				PhNpShape shape(shapePtr, true);
				auto filterData = shape.GetmFilterData();

				/*if (filterData == physx::PxFilterData()) {
					std::println("PhysX3 过滤数据为空");
					continue;
				}*/


				if (filterData.word3 != 19) {
					auto geometry = shape.GetmPxGeometry();
					if (geometry.type != physx::PxGeometryType::eHEIGHTFIELD) {
						continue;
					}
				}

	

				auto localpos = shape.GetmLocalpos();
			

				Physx3::PhPxGeometry geometry = shape.GetmPxGeometry();
				switch (geometry.type)
				{
				case physx::PxGeometryType::eBOX: {
					break;
					auto geometryBox = shape.GetmPxBoxGeometry();

					physx::PxBoxGeometry boxGeometry(geometryBox.halfExtents);
					physx::PxShape* boxShape = physxEngine::gPhysics->createShape(boxGeometry, *physxEngine::gMaterial);

					if (boxShape == nullptr) {
						break;
					}
					boxShape->setQueryFilterData(filterData);
					boxShape->setLocalPose(localpos);
					tmpActor->attachShape( *boxShape);
					
					if (ConcreteType == 7) {
						BoxInfo boxinfo{ geometry.type, GlobalPos, localpos, geometryBox.halfExtents };
						boxinfo.serialize(filePath);
					}


					boxShape->release();

					//gLoadSet.insert(GlobalPos.p);
					break;
				}
				case physx::PxGeometryType::eHEIGHTFIELD: {
					std::println("PhysX3 高度场 Pos: {}, {}, {}", GlobalPos.p.x, GlobalPos.p.y, GlobalPos.p.z);

					auto geometryHeight = shape.GetmPxHeightFieldGeometry();
					auto PhHeightField = geometryHeight.GetHeightField();
			

					uint32_t nbCols = PhHeightField.mData.columns;
					uint32_t nbRows = PhHeightField.mData.rows;
					uint32_t nbVerts = nbRows * nbCols;
					if (nbCols >= 1000000) {
						break;
					}

					auto sampleBuf = std::make_unique<physx::PxHeightFieldSample[]>(nbVerts);
					dma::Read(PhHeightField.mData.samples, sampleBuf.get(), nbVerts * sizeof(physx::PxHeightFieldSample));



					physx::PxHeightFieldDesc hfDesc;
					hfDesc.format = physx::PxHeightFieldFormat::eS16_TM;

					hfDesc.nbColumns = nbCols;
					hfDesc.nbRows = nbRows;
					hfDesc.samples.data = sampleBuf.get();
					hfDesc.samples.stride = sizeof(physx::PxHeightFieldSample);

					auto heightField = physxEngine::gCooking->createHeightField(hfDesc, physxEngine::gPhysics->getPhysicsInsertionCallback());
					if (heightField == nullptr) {
						break;
					}

					if (ConcreteType == 7) {

						HeightFieldInfo heightFieldInfo{
							geometry.type ,
							GlobalPos ,
							localpos ,
							geometryHeight.rowScale ,
							geometryHeight.columnScale ,
							geometryHeight.heightScale ,
							nbRows ,
							nbCols ,
							nbVerts * sizeof(physx::PxHeightFieldSample),
							const_cast<void*>(hfDesc.samples.data)
						};
						heightFieldInfo.serialize(filePath);
					}


					physx::PxHeightFieldGeometry hfGeom(heightField, physx::PxMeshGeometryFlags(), geometryHeight.heightScale, geometryHeight.rowScale, geometryHeight.columnScale);
					auto HeightShape = physxEngine::gPhysics->createShape(hfGeom, *physxEngine::gMaterial);
					HeightShape->setQueryFilterData(filterData);
					HeightShape->setLocalPose(localpos);
					tmpActor->attachShape(*HeightShape);

					heightField->release();
					HeightShape->release();

					//gLoadSet.insert(GlobalPos.p);

					break;
				}
				case physx::PxGeometryType::eTRIANGLEMESH: {
					// std::println("PhysX3 三角 Pos: {}, {}, {}", GlobalPos.p.x, GlobalPos.p.y, GlobalPos.p.z);

					auto geometryTriangleMesh = shape.GetmPxTriangleMeshGeometry();
					auto tiangleMesh = geometryTriangleMesh.GetTriangleMesh();

					const auto nbVerts = tiangleMesh.mNbVertices;
					const int64_t verts = tiangleMesh.mVertices;
					const auto nbTris = tiangleMesh.mNbTriangles;
					const int64_t tris = tiangleMesh.mTriangles;

					if (nbTris > 1000000 || nbTris <= 0) {
						break;
					}
					if (nbVerts > 1000000 || nbTris <= 0) {
						break;
					}

					bool has16bit = (tiangleMesh.mFlags & 2) ? true : false;
					auto TrisSize = has16bit ? nbTris * sizeof(short) * 3 : nbTris * sizeof(int) * 3;

					auto TirsBuf = std::make_unique<char[]>(TrisSize);
					auto VerBuf = std::make_unique<physx::PxVec3[]>(nbVerts);

					dma::Read(tris, TirsBuf.get(), TrisSize);
					dma::Read(verts, VerBuf.get(), nbVerts * sizeof(physx::PxVec3));

					//physx::PxVec3 tmpVc3[3]{};
					std::vector<physx::PxU32> trisv{};

					uint32_t indexCount{};
					for (int jjj{}; jjj < nbTris; jjj++) {
						uint32_t index[3]{};
						if (has16bit) {
							uint16_t* temp16bitBuf = (uint16_t*)TirsBuf.get();
							index[0] = temp16bitBuf[indexCount++];
							index[1] = temp16bitBuf[indexCount++];
							index[2] = temp16bitBuf[indexCount++];
						}
						else {
							uint32_t* temp32bitBuf = (uint32_t*)TirsBuf.get();
							index[0] = temp32bitBuf[indexCount++];
							index[1] = temp32bitBuf[indexCount++];
							index[2] = temp32bitBuf[indexCount++];
						}



						if (index[0] >= nbVerts || index[1] >= nbVerts || index[2] >= nbVerts) {
							continue;
						}

						trisv.push_back(index[0]);
						trisv.push_back(index[1]);
						trisv.push_back(index[2]);
					}

					physx::PxTriangleMesh* TriMesh;
					TriangleMeshInfo* triangleMeshInfo = nullptr;
					if (ConcreteType == 7) {
						triangleMeshInfo = new  TriangleMeshInfo { geometry.type  ,GlobalPos , localpos ,geometryTriangleMesh.scale };

					}

					TriMesh = physxEngine::createBV34TriangleMesh(nbVerts, VerBuf.get(), trisv.size() / 3, (physx::PxU32*)trisv.data(), false, false, false, 15, triangleMeshInfo);
					if (TriMesh == nullptr) {
						break;
					}
					if (triangleMeshInfo != nullptr) {
						triangleMeshInfo->serialize(filePath);
					}

	

					physx::PxTriangleMeshGeometry Trigeom(TriMesh, geometryTriangleMesh.scale);
					auto TriShape = physxEngine::gPhysics->createShape(Trigeom, *physxEngine::gMaterial);

					if (TriShape == nullptr) {
						TriMesh->release();
						break;
					}

					TriShape->setQueryFilterData(filterData);
					TriShape->setLocalPose(localpos);
					tmpActor->attachShape(*TriShape);

					TriMesh->release();
					TriShape->release();

					//gLoadSet.insert(GlobalPos.p);
					break;
				}
				case physx::PxGeometryType::eCONVEXMESH: {
					std::println("PhysX3 凹凸 Pos: {}, {}, {}", GlobalPos.p.x, GlobalPos.p.y, GlobalPos.p.z);
					auto geometryConvexMesh = shape.GetmPxConvexMeshGeometry();
					auto ConvexMesh = geometryConvexMesh.GetConvexMesh();

					const physx::PxVec3* vertexBuffer = ConvexMesh.mHullData.getHullVertices();

					// 使用智能指针自动管理内存
					auto tempVertexBuffer = std::make_unique<physx::PxVec3[]>(ConvexMesh.mHullData.mNbHullVertices);

					dma::Read((uintptr_t)vertexBuffer, tempVertexBuffer.get(), ConvexMesh.mHullData.mNbHullVertices * sizeof(physx::PxVec3));

					if (ConcreteType == 7) {
						ConvexMeshInfo convexMeshInfo{ geometry.type  ,GlobalPos , localpos ,geometryConvexMesh.scale ,ConvexMesh.mHullData.mNbHullVertices ,tempVertexBuffer.get() };
						convexMeshInfo.serialize(filePath);
					}


					auto convMesh = physxEngine::createBVConvexMesh(ConvexMesh.mHullData.mNbHullVertices , tempVertexBuffer.get());
					if (convMesh == nullptr) {
						break;
					}
					physx::PxConvexMeshGeometry convGeom(convMesh, geometryConvexMesh.scale);
					auto convShape = physxEngine::gPhysics->createShape(convGeom, *physxEngine::gMaterial);

					if (convShape == nullptr) {
						convMesh->release();
						break;
					}

					convShape->setQueryFilterData(filterData);
					convShape->setLocalPose(localpos);
					tmpActor->attachShape(*convShape);

					convShape->release();
					convMesh->release();
					//gLoadSet.insert(GlobalPos.p);
					break;
				}
				default: {
					auto a = geometry.type;
					break;
				}

				}

			}

			if (tmpActor != nullptr   ) {
				if (tmpActor->getNbShapes() > 0) {
					std::unique_lock<std::shared_mutex> lock(physxEngine::sceneMutex);
					if (physxEngine::gScene) {
						physxEngine::gScene->addActor(*tmpActor);
						gLoadSet.insert(actorPtr);
					} else {
						tmpActor->release();
					}
				}
				else {
					tmpActor->release();
				}
				
			}
		}


	}

	auto nbdy = physxEngine::gScene->getNbActors(physx::PxActorTypeFlag::eRIGID_DYNAMIC);
	auto nbst = physxEngine::gScene->getNbActors(physx::PxActorTypeFlag::eRIGID_STATIC);
}

void PhysX3::loadPhysx(const char* filename)
{
	if (std::filesystem::exists("model/") == false) {
		return;
	}

	std::ifstream inFile("model/" + std::string(filename), std::ios::binary | std::ios::ate);
	if (!inFile.is_open()) {
		return;
	}

	size_t filesize = inFile.tellg();
	inFile.seekg(0, std::ios::beg);
	auto buf = new char[filesize];

	inFile.read(buf, filesize);

	uint32_t pos = 0;
	while (pos < filesize) {
		// 先读取类型判断形状种类
		int16_t mType{};
		memcpy(&mType , buf + pos , 2);

		switch (mType) {
		case physx::PxGeometryType::eBOX: { // BOX
			BoxInfo boxInfo;
			boxInfo.deserialize(buf, pos);

			auto tmpActor = physxEngine::gPhysics->createRigidStatic(boxInfo.GlobalPos);

			physx::PxBoxGeometry boxGeometry(boxInfo.halfExtents);
			physx::PxShape* boxShape = physxEngine::gPhysics->createShape(boxGeometry, *physxEngine::gMaterial);

			if (boxShape == nullptr) {
				break;
			}


			boxShape->setLocalPose(boxInfo.localpos);
			tmpActor->attachShape(*boxShape);

			boxShape->release();
	
			{
				std::unique_lock<std::shared_mutex> lock(physxEngine::sceneMutex);
				if (physxEngine::gScene) physxEngine::gScene->addActor(*tmpActor);
			}

			//gLoadSet.insert(boxInfo.GlobalPos.p);

			break;
		}
		case physx::PxGeometryType::eTRIANGLEMESH: { // TRIANGLE_MESH
			TriangleMeshInfo meshInfo;
			meshInfo.deserialize(buf, pos);
			auto tmpActor = physxEngine::gPhysics->createRigidStatic(meshInfo.GlobalPos);
			auto stream = physx::PxDefaultMemoryInputData(meshInfo.CookIngData, meshInfo.CookIngSize);
			auto triMesh = physxEngine::gPhysics->createTriangleMesh(stream );
			auto triGemo = physx::PxTriangleMeshGeometry(triMesh , meshInfo.scale);
			physx::PxShape* TriShape = physxEngine::gPhysics->createShape(triGemo, *physxEngine::gMaterial);


			TriShape->setFlag(physx::PxShapeFlag::eSCENE_QUERY_SHAPE, true);
			TriShape->setLocalPose(meshInfo.localpos);
			tmpActor->attachShape(*TriShape);

			{
				std::unique_lock<std::shared_mutex> lock(physxEngine::sceneMutex);
				if (physxEngine::gScene) physxEngine::gScene->addActor(*tmpActor);
			}

			TriShape->release();
			if (meshInfo.CookIngData) {
				delete[] meshInfo.CookIngData;
			}
			//gLoadSet.insert(meshInfo.GlobalPos.p);
			break;
		}
		case physx::PxGeometryType::eHEIGHTFIELD: { // HEIGHT_FIELD
			HeightFieldInfo heightFieldInfo;

			heightFieldInfo.deserialize(buf ,pos);
			auto tmpActor = physxEngine::gPhysics->createRigidStatic(heightFieldInfo.GlobalPos);

			physx::PxHeightFieldDesc hfDesc;
			hfDesc.format = physx::PxHeightFieldFormat::eS16_TM;
			hfDesc.nbColumns = heightFieldInfo.nbCols;
			hfDesc.nbRows = heightFieldInfo.nbRows;
			hfDesc.samples.data = heightFieldInfo.sampleData;
			hfDesc.samples.stride = sizeof(physx::PxHeightFieldSample);

			auto heightField = physxEngine::gCooking->createHeightField(hfDesc, physxEngine::gPhysics->getPhysicsInsertionCallback());
			auto hfGeom = physx::PxHeightFieldGeometry (heightField, physx::PxMeshGeometryFlags(), heightFieldInfo.scale_height, heightFieldInfo.scale_row, heightFieldInfo.scale_column);

			auto HeightShape = physxEngine::gPhysics->createShape(hfGeom, *physxEngine::gMaterial);



			HeightShape->setFlag(physx::PxShapeFlag::eSCENE_QUERY_SHAPE, true);
			HeightShape->setLocalPose(heightFieldInfo.localpos);

			tmpActor->attachShape(*HeightShape);

			heightField->release();
			HeightShape->release();

			{
				std::unique_lock<std::shared_mutex> lock(physxEngine::sceneMutex);
				if (physxEngine::gScene) physxEngine::gScene->addActor(*tmpActor);
			}

			if (heightFieldInfo.sampleData) {
				delete[] static_cast<const char*>(heightFieldInfo.sampleData);
			}
			//gLoadSet.insert(heightFieldInfo.GlobalPos.p);
			break;
		}
		case physx::PxGeometryType::eCONVEXMESH: {
			ConvexMeshInfo convexMeshInfo;
	
			convexMeshInfo.deserialize(buf, pos);

			auto tmpActor = physxEngine::gPhysics->createRigidStatic(convexMeshInfo.GlobalPos);

			auto convMesh = physxEngine::createBVConvexMesh(convexMeshInfo.mNbHullVertices, convexMeshInfo.VertexBuffer);
			if (convMesh == nullptr) {
				break;
			}
			physx::PxConvexMeshGeometry convGeom(convMesh, convexMeshInfo.scale);
			auto convShape = physxEngine::gPhysics->createShape(convGeom, *physxEngine::gMaterial);

			if (convShape == nullptr) {
				convMesh->release();
				break;
			}

			convShape->setLocalPose(convexMeshInfo.localpos);
			tmpActor->attachShape(*convShape);

			{
				std::unique_lock<std::shared_mutex> lock(physxEngine::sceneMutex);
				if (physxEngine::gScene) physxEngine::gScene->addActor(*tmpActor);
			}

			convShape->release();
			convMesh->release();

			if (convexMeshInfo.VertexBuffer) {
				delete[] convexMeshInfo.VertexBuffer;
			}

			//gLoadSet.insert(convexMeshInfo.GlobalPos.p);
			break;
		}
		}

	}
	delete[] buf;
	inFile.close();
	std::cout << "所有形状数据加载完成" << std::endl;
}


void PhysX3::clearPhysx()
{
	std::unique_lock<std::shared_mutex> lock(physxEngine::sceneMutex);
	if (!physxEngine::gScene) return;

	PxU32 nbActors = physxEngine::gScene->getNbActors(physx::PxActorTypeFlag::eRIGID_DYNAMIC | physx::PxActorTypeFlag::eRIGID_STATIC);
	if (nbActors > 0) {
		std::vector<physx::PxActor*> actors(nbActors);
		physxEngine::gScene->getActors(physx::PxActorTypeFlag::eRIGID_DYNAMIC | physx::PxActorTypeFlag::eRIGID_STATIC, actors.data(), nbActors);
		for (PxU32 i = 0; i < nbActors; i++) {
			physxEngine::gScene->removeActor(*actors[i]);
			actors[i]->release();
		}
	}
	gLoadSet.clear();
}
