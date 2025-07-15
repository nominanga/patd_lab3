#pragma once
#include<algorithm>
#include<stdexcept>

template <typename T>
class DynamicArray
{
    T*data;
    int size;
    int capacity;

public:
    DynamicArray(int size) : size(size) {
        if (size < 0)
            throw std::invalid_argument("size must be positive");
        capacity = size == 0 ? 1 : size * 2;
        data = new T[capacity];
    }

    DynamicArray(T* input, int count) : size(count) {
        if (count < 0)
            throw std::invalid_argument("size must be positive");
        capacity = count == 0 ? 1 : count * 2;
        data = new T[capacity];
        std::copy(input, input + count, data);
    }

    DynamicArray(const DynamicArray& other) : size(other.size) {
        capacity = other.capacity;
        data = new T[capacity];
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

        if (new_size < capacity) {
            size = new_size;
            return;
        }
        if (new_size >= capacity) {
            capacity = new_size * 2;
            T* new_data = new T[capacity];
            std::copy(data, data + size, new_data);
            delete[] data;
            data = new_data;
            size = new_size;
        }
    }
};
