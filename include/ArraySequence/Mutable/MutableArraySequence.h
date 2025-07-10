#pragma once
#include "ArraySequence/ArraySequence.h"

template <typename T>
class MutableArraySequence final : public ArraySequence<T> {
protected:
    Sequence<T>* Instance() override {
        return this;
    }
    Sequence<T>* Clone() override {
        return new MutableArraySequence<T>(*this);
    }
public:
    MutableArraySequence() : ArraySequence<T>() {}
    MutableArraySequence(T* items, int count) : ArraySequence<T>(items, count) {}
    MutableArraySequence(const MutableArraySequence<T>& other) : ArraySequence<T>(other) {}
};
