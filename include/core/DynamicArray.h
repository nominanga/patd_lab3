#pragma once
#include<algorithm>
#include<stdexcept>

template <typename T>
class DynamicArray
{
    T*data;
    int size;

public:
    DynamicArray(int size) : size(size) {
        if (size < 0)
            throw std::invalid_argument("size must be positive");
        data = new T[size];
    }

    DynamicArray(T* input, int count) : size(count) {
        if (count < 0)
            throw std::invalid_argument("size must be positive");
        data = new T[count];
        std::copy(input, input + count, data);
    }

    DynamicArray(const DynamicArray& other) : size(other.size) {
        data = new T[size];
        std::copy(other.data, other.data + size, data);
    }

    ~DynamicArray() {
        delete[] data;
    }

    T Get(int index) {
        if (index < 0 || index >= size) {
            throw std::out_of_range("index out of range");
        }

        return data[index];
    }

    void Set(int index, T value) {
        if (index < 0 || index >= size) {
            throw std::out_of_range("index out of range");
        }

        data[index] = value;
    }

    int GetSize() const {
        return size;
    }

    void Resize(const int new_size) {
        if (new_size < 0) {
            throw std::invalid_argument("size must be positive");
        }

        T* new_data = new T[new_size];
        int elements_to_copy = std::min(size, new_size);
        std::copy(data, data + elements_to_copy, new_data);
        delete[] data;
        data = new_data;
        size = new_size;
    }
};
