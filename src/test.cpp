#include <iostream>
#include <cassert>
#include "../include/ArraySequence/Immutable/ImmutableArraySequence.h"
#include "../include/ArraySequence/Mutable/MutableArraySequence.h"
#include "../include/ListSequence/Immutable/ImmutableListSequence.h"
#include "../include/ListSequence/Mutable/MutableListSequence.h"

template<typename T>
void printSequence(const Sequence<T>* seq) {
    for (int i = 0; i < seq->GetLength(); ++i) {
        std::cout << seq->Get(i) << " ";
    }
    std::cout << "\n";
}

void TestMutableArraySequence() {
    int numbers[5] = {1, 2, 3, 4, 5};
    auto* seq = new MutableArraySequence<int>(numbers, 5);
    printSequence(seq);
    assert(seq->GetLength() == 5);
    assert(seq->GetFirst() == 1);
    assert(seq->GetLast() == 5);
    assert(seq->Get(2) == 3);

    try {
        seq->Get(1000);
        assert(false);
    } catch (const std::out_of_range& e) {
        std::cout << "Caught expected exception: " << e.what() << std::endl;
    }

    seq->Append(6);
    assert(seq->GetLength() == 6);
    assert(seq->GetLast() == 6);

    seq->Prepend(0);
    assert(seq->GetLength() == 7);
    assert(seq->GetFirst() == 0);

    seq->InsertAt(999, 4);
    assert(seq->GetLength() == 8);
    assert(seq->Get(4) == 999);

    try {
        seq->InsertAt(1000, 1000);
        assert(false);
    } catch (const std::out_of_range& e) {
        std::cout << "Caught expected exception: " << e.what() << std::endl;
    }

    auto* subSeq = seq->GetSubsequence(0, 1);
    assert(subSeq->GetLength() == 2);
    assert(subSeq->GetFirst() == seq->GetFirst());
    assert(subSeq->GetLast() == seq->Get(1));

    try {
        seq->GetSubsequence(1000, 1000);
        assert(false);
    } catch (const std::out_of_range& e) {
        std::cout << "Caught expected exception: " << e.what() << std::endl;
    }

    auto* concatSeq = seq->Concat(subSeq);
    assert(concatSeq->GetLength() == subSeq->GetLength() + seq->GetLength());
    assert(concatSeq->GetFirst() == seq->GetFirst());
    assert(concatSeq->GetLast() == subSeq->GetLast());

    delete seq;
    delete subSeq;
    delete concatSeq;
}

void TestImmutableListSequence() {
    int numbers[5] = {1, 2, 3, 4, 5};
    auto* seq = new ImmutableListSequence<int>(numbers, 5);
    printSequence(seq);


    assert(seq->GetLength() == 5);
    assert(seq->GetFirst() == 1);
    assert(seq->GetLast() == 5);
    assert(seq->Get(2) == 3);

    try {
        seq->Get(1000);
        assert(false);
    } catch (const std::out_of_range& e) {
        std::cout << "Caught expected exception: " << e.what() << std::endl;
    }

    auto* appended = seq->Append(6);
    assert(appended->GetLength() == 6);
    assert(appended->GetLast() == 6);

    auto* prepended = appended->Prepend(0);
    assert(prepended->GetLength() == 7);
    assert(prepended->GetFirst() == 0);

    auto* inserted = prepended->InsertAt(999, 4);
    assert(inserted->GetLength() == 8);
    assert(inserted->Get(4) == 999);

    try {
        seq->InsertAt(1000, 1000);
        assert(false);
    } catch (const std::out_of_range& e) {
        std::cout << "Caught expected exception: " << e.what() << std::endl;
    }

    auto* subSeq = inserted->GetSubsequence(0, 1);
    assert(subSeq->GetLength() == 2);
    assert(subSeq->GetFirst() == inserted->GetFirst());
    assert(subSeq->GetLast() == inserted->Get(1));

    try {
        seq->GetSubsequence(1000, 1000);
        assert(false);
    } catch (const std::out_of_range& e) {
        std::cout << "Caught expected exception: " << e.what() << std::endl;
    }

    auto* concatSeq = inserted->Concat(subSeq);
    assert(concatSeq->GetLength() == inserted->GetLength() + subSeq->GetLength());
    assert(concatSeq->GetFirst() == inserted->GetFirst());
    assert(concatSeq->GetLast() == subSeq->GetLast());

    delete seq;
    delete subSeq;
    delete concatSeq;
}

int main() {
    TestMutableArraySequence();
    std::cout << "Passed all tests for MutableArraySequence" << "\n\n";
    TestImmutableListSequence();
    std::cout << "Passed all tests for ImmutableListSequence" << std::endl;
}