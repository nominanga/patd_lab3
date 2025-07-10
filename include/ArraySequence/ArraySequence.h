#pragma once
#include "DynamicArray.h"
#include "SequenceInterface/Sequence.h"

template <typename T>
class ArraySequence : public Sequence<T> {

    DynamicArray<T>* data;

protected:
    Sequence<T>* Instance() override {
        return this;
    }

    Sequence<T>* AppendInternal(T item) override {
        int size = data->GetSize();
        data->Resize(size + 1);
        data->Set(size, item);
        return this;
    }

    Sequence<T>* PrependInternal(T item) override {
        InsertAtInternal(0, item);
        return this;
    }

    Sequence<T>* InsertAtInternal(T item, int index) override {
        int size = data->GetSize();
        data->Resize(++size);

        T prev = data->Get(index);
        for (int i = index + 1; i < size; i++) {
            T tmp = prev;
            prev = data->Get(i);
            data->Set(i, tmp);
        }

        data->Set(index, item);
        return this;
    }

    Sequence<T>* RemoveLastInternal() {
        int size = data->GetSize();
        if (size == 0) {
            throw std::out_of_range("Sequence is empty");
        }
        data->Resize(size - 1);
        return this;
    }

    Sequence<T>* RemoveFirstInternal() {
        int size = data->GetSize();
        if (size == 0) {
            throw std::out_of_range("Sequence is empty");
        }
        for (int i = 1; i < size; i++) {
            T next = data->Get(i);
            data->Set(i - 1, next);
        }
        data->Resize(size - 1);
        return this;
    }

    Sequence<T>* Clone() override {
        return new ArraySequence<T>(*this);
    }

public:
    ArraySequence() {
        data = new DynamicArray<T>(0);
    }

    ArraySequence(T* items, int count) {
        data = new DynamicArray<T>(items, count);
    }

    ArraySequence(const ArraySequence<T>& other) {
        data = new DynamicArray<T>(*other.data);
    }

    ~ArraySequence() override {
        delete data;
    }

    T Get(int index) const override {
        return data->Get(index);
    }

    T GetFirst() const override {
        return data->Get(0);
    }

    T GetLast() const override {
        return data->Get(data->GetSize() - 1);
    }

    int GetLength() const override {
        return data->GetSize();
    }

    Sequence<T>* Append(T item) override {
        return Instance()->AppendInternal(item);
    }

    Sequence<T>* RemoveLast() {
        return Instance()->RemoveLastInternal();
    }

    Sequence<T>* RemoveFirst() {
        return Instance()->RemoveFirstInternal();
    }

    Sequence<T>* Prepend(T item) override {
        return Instance()->PrependInternal(item);
    }

    Sequence<T>* InsertAt(T item, int index) override {
        return Instance()->InsertAtInternal(item, index);
    }

    Sequence<T>* GetSubsequence(int startindex, int endindex) override {
        auto seq = new ArraySequence<T>();

        for (int i = startindex; i <= endindex; i++) {
            seq->AppendInternal(data->Get(i));
        }

        return seq;
    }

    Sequence<T>* Concat(Sequence<T>* other) override {
        auto seq = Clone();
        for (int i = 0; i < other->GetLength(); i++) {
            seq->AppendInternal(other->Get(i));
        }

        return seq;
    }
};
