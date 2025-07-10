#pragma once
#include "ListSequence/ListSequence.h"

template <typename T>
class MutableListSequence : public ListSequence<T> {
protected:
    Sequence<T>* Instance() override {
        return this;
    }

    Sequence<T>* Clone() override {
        return new MutableListSequence<T>(*this);
    }
public:
    MutableListSequence() : ListSequence<T>() {}
    MutableListSequence(T* items, int count) : ListSequence<T>(items, count) {}
    MutableListSequence(const MutableListSequence<T>& other) : ListSequence<T>(other) {}
};
