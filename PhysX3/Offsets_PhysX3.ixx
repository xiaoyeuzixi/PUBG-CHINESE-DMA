export module Offsets_PhysX3;


import std;
import <cstdint>;


export struct Offsets_PhysX3
{

    struct Base {
        static constexpr int64_t Physics = 0x1DF698;
        
        static constexpr const char* Physicsdll = "PhysX3_x64.dll";
    };

    struct Phystcs {
        static constexpr int64_t NpScenePArray = 0x8;//类TArray  0
    };

    struct NpScene {
        static constexpr int64_t PxActors = 0x2590; //Ayrray  [PxActor]
    };

    struct PxBase
    {
        static constexpr int64_t mConcreteType = 0x8;			// uint16_t 6  7 concrete type identifier - see PxConcreteType.
        static constexpr int64_t mBaseFlags = 0x10;			    // uint16_t internal flags
  		  
    };

    struct PxActors:PxBase{
        static constexpr int64_t mShapeManager = 0x28; //class struct NpShapeManager
        static constexpr int64_t mActorFlags = 0x40; //unt8_t
        static constexpr int64_t mStreamPtr = 0x70;
    };


    struct NpRigidDynamic {

        static constexpr int64_t mBodyBufferFlags = 0x17C; //   & 0x200  mStreamPtr + 0xE0
        static constexpr int64_t body2Actor = 0xB0; //  
        static constexpr int64_t mBufferedBody2World = 0x140; //  

    };

    struct NpRigidStatic {

        static constexpr int64_t mControlState = 0x68; //  & 0x40 mStreamPtr + 0xB0
        static constexpr int64_t Body2World = 0x90;

    };


    struct NpShape {

		static constexpr int64_t mControlState = 0x38; //& 1 ; Shape.mControlState
		static constexpr int64_t mStreamPtr = 0x40; // if mControlState & 1 == 0 { mGeometry = mStreamPtr + 0x38}
		static constexpr int64_t mFilterData = 0x50; //
		static constexpr int64_t mLocalpos = 0x70; // 
		static constexpr int64_t mFlags = 0x90; // uint8_t
        
		static constexpr int64_t mGeometry = 0x98; //PxGeometry;
    
    };


};


/*



void runPhys() {

    bool Pret = mPhysX3.init();

    auto npSencePArray = mPhysX3.GetNpSencePArray();
    auto npSence = npSencePArray[0];

    while (g_running)
    {


        auto PxActors = npSence.GetPxActorsPArray();



        auto newBox = std::make_shared<std::vector<xBox>>();

        for (int i{}; i < PxActors.NumElements; i++) {
            auto PxActor = PxActors[i];

            auto ConcreteType = PxActor.GetmConcreteType();
            NpShapeManager shapeManager{};
            PxTransform GlobalPos{};
            if (ConcreteType == 6) {
                //std::println("PhysX3 动态刚体");
                PxRigidDynamic dynamicActor(PxActor.GetPrt(), true);
                auto body2Actor = dynamicActor.Getbody2Actor();
                auto body2World = dynamicActor.GetmBufferedBody2World();

                GlobalPos = body2World * body2Actor.getInverse();

                shapeManager = dynamicActor.GetmShapeManager();

            }
            else if (ConcreteType == 7) {
                //std::println("PhysX3 静态刚体");
                PxRigidStatic staticActor(PxActor.GetPrt(), true);
                GlobalPos = staticActor.GetBody2World();
                shapeManager = staticActor.GetmShapeManager();

            }
            else
            {
                continue;
            }



            for (int s{}; s < shapeManager.mShapes.mCount; s++) {

                PxGeometry geometry;
                int64_t shapePtr = 0;
                if (shapeManager.mShapes.mCount == 1) {
                    shapePtr = shapeManager.mShapes.mSingle;
                }
                else {
                    shapePtr = dma::Read<int64_t>( shapeManager.mShapes.mSingle + s * 8 );
                }

                NpShape shape(shapePtr,true);



                auto filterData = shape.GetmFilterData();
                if (filterData == PxFilterData()) {
                    continue;
                }


                geometry = shape.GetmPxGeometry();
                switch (geometry.type)
                {
                case PxGeometryType::eBOX: {

                    auto pos = shape.GetmLocalpos();
                    auto pxbox = shape.GetmPxBoxGeometry();

                    auto gpos = pos * GlobalPos;

                    PxMat44 boxMat(gpos);

                    auto boxpos = pxbox.GetBox(boxMat);

                    newBox->push_back(boxpos);

                    break;
                }
                case PxGeometryType::eCONVEXMESH: {
                    //std::println("PhysX3 凹凸");
                    break;
                }
                case PxGeometryType::eHEIGHTFIELD: {
                    //std::println("PhysX3 高度场");
                    break;
                }
                case PxGeometryType::eTRIANGLEMESH: {
                    //std::println("PhysX3 三角");
                    break;
                }
                default: {
                    break;
                }

                }


            }


        }


        g_box.store(newBox, std::memory_order_release);

    }


}





void drawBox1(FCameraCacheEntry& CameraCacheEntry, ImDrawList* drawList) {
    const PxU8 indices[] = {
        0,1, 1,2, 2,3, 3,0,
        7,6, 6,5, 5,4, 4,7,
        1,5, 6,2, 3,7, 4,0

    };

    auto boxes = g_box.load(std::memory_order_acquire);
    if (!boxes)
    {
        return;
    }
    for (const auto& box : *boxes) {

        FVector3D pos1{ box.box[0].x , box.box[0].y , box.box[0].z };
        auto dis = CameraCacheEntry.POV.Location.GetDistanceToInMeters(pos1);
        if (dis > 10) {
            continue;
        }


        for (int i = 0; i < 12; i++) {
            pos1 = { box.box[indices[i * 2]].x , box.box[indices[i * 2]].y , box.box[indices[i * 2]].z };
            FVector3D pos2 = { box.box[indices[i * 2 + 1]].x , box.box[indices[i * 2 + 1]].y , box.box[indices[i * 2 + 1]].z };

            FVector2D out1{};
            auto ret1 = mEngine.WorldToScreen1(pos1, CameraCacheEntry, out1);

            FVector2D out2{};
            auto ret2 = mEngine.WorldToScreen1(pos2, CameraCacheEntry, out2);

            if (ret1 && ret2) {
                drawList->AddLine(ImVec2(out1.X, out1.Y), ImVec2(out2.X, out2.Y), imguiColor::Red, 1.5f);
            }



        }

    }


}
*/