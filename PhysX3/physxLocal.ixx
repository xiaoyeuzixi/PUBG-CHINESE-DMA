module;
#include <PxPhysicsAPI.h>
export module physxLocal;
import <cstdint>;
import std;

export struct ConvexMeshInfo {
    int16_t mType;
    physx::PxTransform GlobalPos{};
    physx::PxTransform localpos{};
    physx::PxMeshScale scale{};
    physx::PxU8 mNbHullVertices{};  // 顶点数量
    physx::PxVec3* VertexBuffer{}; // 顶点数据

    void serialize(std::string filepath) const {

        std::ofstream outFile(filepath, std::ios::binary | std::ios::in | std::ios::app);
        if (outFile.is_open() == false) {
            return;
        }
        outFile.write((char*)&mType, 2);
        outFile.write((char*)&GlobalPos, sizeof(GlobalPos));
        outFile.write((char*)&localpos, sizeof(localpos));
        outFile.write((char*)&scale, sizeof(scale));
        outFile.write((char*)&mNbHullVertices, sizeof(mNbHullVertices));
        outFile.write((char*)VertexBuffer, sizeof(physx::PxVec3) * mNbHullVertices);
        outFile.close();
    }
    void deserialize(char* buf, uint32_t& pos) {

        memcpy(&mType, buf + pos, 2);
        pos +=2;
        memcpy(&GlobalPos, buf + pos, sizeof(GlobalPos));
        pos +=sizeof(GlobalPos);
        memcpy(&localpos, buf + pos, sizeof(localpos));
        pos +=sizeof(localpos);
        memcpy(&scale, buf + pos, sizeof(scale));
        pos +=sizeof(scale);
        memcpy(&mNbHullVertices, buf + pos, sizeof(mNbHullVertices));
        pos +=sizeof(mNbHullVertices);

        VertexBuffer = new physx::PxVec3[mNbHullVertices];
        memcpy(VertexBuffer, buf + pos, sizeof(physx::PxVec3) * mNbHullVertices);
        pos +=sizeof(physx::PxVec3) * mNbHullVertices;

    }



};

export struct HeightFieldInfo {
    int16_t mType;
    physx::PxTransform GlobalPos{};
    physx::PxTransform localpos{};

    physx::PxReal scale_row{};
    physx::PxReal scale_column{};
    physx::PxReal scale_height{};

    physx::PxU32 nbRows{};
    physx::PxU32 nbCols{};

    uint32_t sampleSize{};
    void* sampleData{};


    void serialize(std::string filepath) const {

        std::ofstream outFile(filepath, std::ios::binary | std::ios::in | std::ios::app);
        if (outFile.is_open() == false) {
            return;
        }
        outFile.write((char*)&mType, 2);
        outFile.write((char*)&GlobalPos, sizeof(GlobalPos));
        outFile.write((char*)&localpos, sizeof(localpos));

        outFile.write((char*)&scale_row, sizeof(scale_row));
        outFile.write((char*)&scale_column, sizeof(scale_column));
        outFile.write((char*)&scale_height, sizeof(scale_height));

        outFile.write((char*)&nbRows, sizeof(nbRows));
        outFile.write((char*)&nbCols, sizeof(nbCols));
        outFile.write((char*)&sampleSize, sizeof(sampleSize));
        outFile.write((char*)sampleData, sampleSize);
        outFile.close();

    }


    void deserialize(char* buf, uint32_t& pos) {

        memcpy(&mType, buf + pos, 2);
        pos +=2;
        memcpy(&GlobalPos, buf + pos, sizeof(GlobalPos));
        pos +=sizeof(GlobalPos);
        memcpy(&localpos, buf + pos, sizeof(localpos));
        pos +=sizeof(localpos);
        memcpy(&scale_row, buf + pos, sizeof(scale_row));
        pos +=sizeof(scale_row);
        memcpy(&scale_column, buf + pos, sizeof(scale_column));
        pos +=sizeof(scale_column);
        memcpy(&scale_height, buf + pos, sizeof(scale_height));
        pos +=sizeof(scale_height);
        memcpy(&nbRows, buf + pos, sizeof(nbRows));
        pos +=sizeof(nbRows);
        memcpy(&nbCols, buf + pos, sizeof(nbCols));
        pos +=sizeof(nbCols);
        memcpy(&sampleSize, buf + pos, sizeof(sampleSize));
        pos +=sizeof(sampleSize);
        sampleData = new char[sampleSize] {};
        memcpy(sampleData, buf + pos, sampleSize);  
        pos += sampleSize;



    }



};


export struct TriangleMeshInfo {
    int16_t mType{};
    physx::PxTransform GlobalPos{};
    physx::PxTransform localpos{};
    physx::PxMeshScale scale{};
    uint32_t CookIngSize{};
    physx::PxU8* CookIngData{};

    void serialize(std::string filepath) const {

        std::ofstream outFile(filepath, std::ios::binary | std::ios::in | std::ios::app);
        if (outFile.is_open() == false) {
            return;
        }
        outFile.write((char*)&mType, 2);
        outFile.write((char*)&GlobalPos, sizeof(GlobalPos));
        outFile.write((char*)&localpos, sizeof(localpos));
        outFile.write((char*)&scale, sizeof(scale));
        outFile.write((char*)&CookIngSize, sizeof(CookIngSize));
        outFile.write((char*)CookIngData, CookIngSize);
        outFile.close();

    }



    void deserialize(char* buf, uint32_t& pos) {

        memcpy(&mType, buf + pos, 2);
        pos += 2;
        memcpy(&GlobalPos, buf + pos, sizeof(GlobalPos));
        pos +=sizeof(GlobalPos);
        memcpy(&localpos, buf + pos, sizeof(localpos));
        pos +=sizeof(localpos);
        memcpy(&scale, buf + pos, sizeof(scale));
        pos +=sizeof(scale);
        memcpy(&CookIngSize, buf + pos, sizeof(CookIngSize));
        pos +=sizeof(CookIngSize);

        CookIngData = new physx::PxU8[CookIngSize] {};
        memcpy(CookIngData, buf + pos, CookIngSize);
        pos +=CookIngSize;

    }

};


export struct BoxInfo {
    int16_t mType;
    physx::PxTransform GlobalPos{};
    physx::PxTransform localpos{};
    physx::PxVec3 halfExtents{};

    void serialize(std::string filepath) const {
        
        std::ofstream outFile(filepath , std::ios::binary | std::ios::in | std::ios::app);
        if (outFile.is_open() == false) {
            return;
        }
        outFile.write((char*)& mType , 2);
        outFile.write((char*)& GlobalPos, sizeof(GlobalPos));
        outFile.write((char*)& localpos, sizeof(localpos));
        outFile.write((char*)& halfExtents, sizeof(halfExtents));
        outFile.close();
    }

    void deserialize(char* buf , uint32_t& pos) {

        memcpy(&mType , buf + pos, 2);
        pos +=2;
        memcpy(&GlobalPos, buf + pos, sizeof(GlobalPos));
        pos += sizeof(GlobalPos);
        memcpy(&localpos, buf + pos, sizeof(localpos));
        pos += sizeof(localpos);
        memcpy(&halfExtents, buf + pos, sizeof(halfExtents));
        pos +=sizeof(halfExtents);
    }

};
