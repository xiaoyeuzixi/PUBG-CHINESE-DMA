export module TArray;
import <cstdint>;
import dma;
import std;

export template<typename T>
class TArray {

public:
    uint64_t Data;
    uint32_t NumElements;
    uint32_t MaxElements;

public:

    auto get_vector();

    auto operator[](size_t index);




};


template<typename T>
auto TArray<T>::get_vector()
{


    if constexpr (std::is_pointer_v<T>) {
        using ElementType = typename std::remove_pointer<T>::type;

        std::vector<uint64_t> pointer_array(NumElements);
        dma::Read(Data, pointer_array.data(), NumElements * sizeof(uint64_t));

        std::vector<ElementType> result;
        result.reserve(NumElements);

        for (auto ptr : pointer_array) {

            result.push_back(ElementType(ptr, true));
        }
        return result;

    }
    else {
        // T 是普通类型
        std::vector<T> result(NumElements);
        dma::Read(Data, result.data(), NumElements * sizeof(T));
        return result;
    }
};


template<typename T>
auto TArray<T>::operator[](size_t index)
{
    if (index >= static_cast<size_t>(NumElements)) {
        throw std::out_of_range("TArray index out of range");
    }



    if constexpr (std::is_pointer_v<T>) {
        // T 是指针类型
        using ElementType = typename std::remove_pointer<T>::type;

        uint64_t ptr;
        dma::Read(Data + index * sizeof(uint64_t), &ptr, sizeof(uint64_t));

        return std::make_shared<ElementType>(ptr, true);
    }
    else {
        T element;
        dma::Read(Data + index * sizeof(T), &element, sizeof(T));
        return element;

    }


};