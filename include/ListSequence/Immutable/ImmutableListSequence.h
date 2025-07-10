#pragma once
#include "ListSequence/ListSequence.h"

template <typename T>
class ImmutableListSequence : public ListSequence<T> {
protected:
    Sequence<T>* Instance() override {
        return this->Clone();
    }

    Sequence<T>* Clone() override {
        return new ImmutableListSequence<T>(*this);
    }
public:
    ImmutableListSequence() : ListSequence<T>() {}
    ImmutableListSequence(T* items, int count) : ListSequence<T>(items, count) {}
    ImmutableListSequence(const ImmutableListSequence<T>& other) : ListSequence<T>(other) {}
};
