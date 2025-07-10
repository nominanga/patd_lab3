#pragma once
#include "MutableArraySequence.h"

template <typename T>
class Stack {
    MutableArraySequence<T>* data;
public:
    Stack() {
        data = new MutableArraySequence<T>();
    }

    ~Stack() {
        delete data;
    }

    void Push(T value) {
        data->Append(value);
    }

    T Pop() {
        T value = data->GetLast();
        data->RemoveLast();
        return value;
    }

    void Clear() {
        while (data->GetLength() > 0) {
            data->RemoveLast();
        }
    }

    bool IsEmpty() const {
        return data->GetLength() == 0;
    }

    int Size() const {
        return data->GetLength();
    }

    T Peek() const {
        return data->GetLast();
    }
};
