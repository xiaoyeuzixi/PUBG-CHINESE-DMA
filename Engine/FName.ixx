export module FName;
import Offsets;
import dma;
import std;
import <cstdint>;

export class FName {
public:
	uint32_t ComparisonIndex{};
    int32_t Number;

	std::string  ToString();


    static inline uint64_t m_GNames{};

private:
    static inline std::unordered_map<int, std::string> g_nameCache{};
    static inline std::shared_mutex g_nameCacheMutex{};


};

std::string FName::ToString()
{
    g_nameCache.find(ComparisonIndex);
    {
        std::shared_lock lock(g_nameCacheMutex);
        if (auto it = g_nameCache.find(ComparisonIndex); it != g_nameCache.end()) {
            return it->second;
        }
    }
    uint64_t fNamePtr = dma::Read<uint64_t>(m_GNames + ((int(ComparisonIndex / 16384)) * 8));
    uint64_t fName = dma::Read<uint64_t>(fNamePtr + ((int(ComparisonIndex % 16384)) * 8));
    char names_c[258]{};
    dma::Read(fName + 0xC, names_c, sizeof(names_c) - 2);
    names_c[257] = '\0';
    std::string name = std::string(names_c);

    if (name == "") {
        name = "fail";
    }

    {
        std::unique_lock lock(g_nameCacheMutex);
        auto [it, inserted] = g_nameCache.emplace(ComparisonIndex, name);
        if (!inserted) {
            return it->second;
        }
    }
    return name;
    
}
