#pragma once
#include "DynamicArray.h"
#include "SequenceInterface/Sequence.h"
#include <functional>

template <typename T>
class ArraySequence : public Sequence<T> {

    DynamicArray<T>* data;

protected:
    Sequence<T>* Instance() override {
        return this;
    }

    Sequence<T>* AppendInternal(T item) override {
        InsertAtInternal(item, data->GetSize());
        return this;
    }

    // реализовать монады
    // решить задачу, список студентов, дисциплин, тройка(студент, дисциплина, оценка)
    // определить топ 5 студентов с наивысш ср баллом
    // топ 5 студентов со срденим баллом ниже ср арифм среди студентов сдавшиз все дисциплины матан и физика на 4 и выше

    Sequence<T>* PrependInternal(T item) override {
        return InsertAtInternal(item, 0);
    }

    Sequence<T>* InsertAtInternal(T item, int index) override {
        int size = data->GetSize();
        if (index < 0 || index > size) {
            throw std::out_of_range("index out of bounds");
        }
        data->Resize(size + 1);

        for (int i = size; i > index; --i) {
            data->Set(i, data->Get(i - 1));
        }
        data->Set(index, item);

        return this;
    }

    Sequence<T>* RemoveLastInternal() override {
        int size = data->GetSize();
        if (size == 0) {
            throw std::out_of_range("Sequence is empty");
        }
        data->Resize(size - 1);
        return this;
    }

    Sequence<T>* RemoveFirstInternal() override {
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

    Sequence<T>* RemoveLast() override {
        return Instance()->RemoveLastInternal();
    }

    Sequence<T>* RemoveFirst() override {
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

    template <typename U>
    ArraySequence<U>* Map(std::function<U(T)> func)  {
        auto seq = new ArraySequence<U>();
        for (int i = 0; i < data->GetSize(); i++) {
            seq->Append(func(data->Get(i)));
        }
        return seq;
    }

    template<typename U>
    ArraySequence<U>* FlatMap(std::function<ArraySequence(T)> func)  {
        auto result = new ArraySequence<U>();
        for (int i = 0; i < data->GetSize(); i++) {
            auto subSequence = func(data->Get(i));
            for (int j = 0; j < subSequence->GetLength(); j++) {
                result->Append(subSequence->Get(j));
            }
            delete subSequence;
        }
        return result;
    }

    ArraySequence<T>* Where(std::function<bool(T)> func)  {
        auto seq = new ArraySequence<T>();
        for (int i = 0; i < data->GetSize(); i++) {
            if (T value = data->Get(i); func(value)) {
                seq->Append(value);
            }
        }
        return seq;
    }

    template<typename U>
    U Reduce(std::function<U(U, T)> func, U initial) {
        for (int i = 0; i < data->GetSize(); i++) {
            initial = func(initial, data->Get(i));
        }
        return initial;
    }

    void Sort(std::function<bool(T, T)> comparator) {
        int n = data->GetSize();
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (comparator(data->Get(i), data->Get(j))) {
                    T tmp = data->Get(i);
                    data->Set(i, data->Get(j));
                    data->Set(j, tmp);
                }
            }
        }
    }

    static Sequence<T>* From(T* data, int count) {
        return new ArraySequence<T>(data, count);
    }
};
