#pragma once
#include "MutableArraySequence.h"

template <typename T>
class Queue {
    MutableArraySequence<T>* data;
public:
    Queue() {
        data = new MutableArraySequence<T>();
    }

    ~Queue() {
        delete data;
    }

    void Enqueue(T value) {
        data->Append(value);
    }

    T Dequeue() {
        T value = data->GetFirst();
        data->RemoveFirst();
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

    void Clear() {
        while (!IsEmpty()) {
            data->RemoveLast();
        }
    }
};
