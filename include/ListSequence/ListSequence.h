#pragma once
#include "LinkedList.h"
#include "SequenceInterface/Sequence.h"

template <typename T>
class ListSequence : public Sequence<T> {

    LinkedList<T>* data;

protected:
    Sequence<T>* Instance() override {
        return this;
    }

    Sequence<T>* AppendInternal(T item) override {
        data->Append(item);
        return this;
    }

    Sequence<T>* PrependInternal(T item) override {
        data->Prepend(item);
        return this;
    }

    Sequence<T>* InsertAtInternal(int index, T item) override {
        data->InsertAt(index, item);
        return this;
    }

    Sequence<T>* Clone() override {
        return new ListSequence<T>(*this);
    }

    // simple plug methods to compile it
    Sequence<T>* RemoveLastInternal() override {
        return this;
    }
    Sequence<T>* RemoveFirstInternal() override {
        return this;
    }
    Sequence<T>* RemoveLast() override {
        return this;
    }
    Sequence<T>* RemoveFirst() override {
        return this;
    }
    // end of plugs

    void ReplaceData(LinkedList<T>* newList) {
        delete data;
        data = newList;
    }


public:
    ListSequence() {
        data = new LinkedList<T>();
    }

    ListSequence(T* items, int count) {
        data = new LinkedList<T>(items, count);
    }

    ListSequence(const ListSequence<T>& other) {
        data = new LinkedList<T>(*other.data);
    }

    ~ListSequence() override {
        delete data;
    }

    T Get(int index) const override {
        return data->Get(index);
    }

    T GetLast() const override {
        return data->GetLast();
    }

    T GetFirst() const override {
        return data->GetFirst();
    }

    int GetLength() const override {
        return data->GetLength();
    }

    Sequence<T>* Append(T item) override {
        return Instance()->AppendInternal(item);
    }

    Sequence<T>* Prepend(T item) override {
        return Instance()->PrependInternal(item);
    }

    Sequence<T>* InsertAt(T index, T item) override {
        return Instance()->InsertAtInternal(index, item);
    }

    Sequence<T>* GetSubsequence(int startindex, int endindex) override {
        auto* seq = new ListSequence<T>();
        seq->ReplaceData(this->data->GetSubList(startindex, endindex));
        return seq;
    }

    Sequence<T>* Concat(Sequence<T>* other) override {
        auto* seq = new ListSequence<T>(*this);
        auto* otherList = dynamic_cast<ListSequence<T>*>(other);
        seq->ReplaceData(this->data->Concat(otherList->data));
        return seq;
    }

};
