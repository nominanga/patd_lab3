#pragma once

template <typename T>
class Sequence {

public:
    virtual ~Sequence() = default;

    virtual T Get(int index) const = 0;
    virtual T GetFirst() const = 0;
    virtual T GetLast() const = 0;
    virtual int GetLength() const = 0;

    virtual Sequence<T>* Append(T item) = 0;
    virtual Sequence<T>* Prepend(T item) = 0;
    virtual Sequence<T>* InsertAt(T item, int index) = 0;

    virtual Sequence<T>* GetSubsequence(int startindex, int endindex) = 0;
    virtual Sequence<T>* Concat(Sequence<T>* other) = 0;

    virtual Sequence<T>* Instance() = 0;
    virtual Sequence<T>* AppendInternal(T item) = 0;
    virtual Sequence<T>* PrependInternal(T item) = 0;
    virtual Sequence<T>* InsertAtInternal(T item, int index) = 0;
    virtual Sequence<T>* Clone() = 0;
};