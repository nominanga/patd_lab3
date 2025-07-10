#pragma once
#include "MutableArraySequence.h"

template <typename T>
class Deque {
    MutableArraySequence<T>* data;
public:
    Deque() {
        data = new MutableArraySequence<T>();
    }

    ~Deque() {
        delete data;
    }

    void PushFront(T value) {
        data->Prepend(value);
    }

    void PushBack(T value) {
        data->Append(value);
    }

    T PopFront() {
        T value = data->GetFirst();
        data->RemoveFirst();
        return value;
    }

    T PopBack() {
        T value = data->GetLast();
        data->RemoveLast();
        return value;
    }

    bool IsEmpty() const {
        return data->GetLength() == 0;
    }

    int Size() const {
        return data->GetLength();
    }

    T Front() const {
        return data->GetFirst();
    }

    T Back() const {
        return data->GetLast();
    }
};
