#include <iostream>
#include "../include/ArraySequence/Immutable/ImmutableArraySequence.h"
#include "../include/ArraySequence/Mutable/MutableArraySequence.h"
#include "../include/ListSequence/Immutable/ImmutableListSequence.h"
#include "../include/ListSequence/Mutable/MutableListSequence.h"


void printSequence(const Sequence<int>* seq) {
    for (int i = 0; i < seq->GetLength(); ++i) {
        std::cout << seq->Get(i) << " ";
    }
    std::cout << "\n";
}

void append(Sequence<int>* seq, int value, bool isMutable) {
    if (isMutable) {
        seq->Append(value);
        printSequence(seq);
    }
    else {
        auto* newSeq = seq->Append(value);
        printSequence(newSeq);
        delete newSeq;
    }
}

void prepend(Sequence<int>* seq, int value, bool isMutable) {
    if (isMutable) {
        seq->Prepend(value);
        printSequence(seq);
    }
    else {
        auto* newSeq = seq->Prepend(value);
        printSequence(newSeq);
        delete newSeq;
    }
}

void insert(Sequence<int>* seq, int value, int index, bool isMutable) {
    if (isMutable) {
        seq->InsertAt(value, index);
        printSequence(seq);
    }
    else {
        auto* newSeq = seq->InsertAt(value, index);
        printSequence(newSeq);
        delete newSeq;
    }
}

void get(Sequence<int>* seq, int index) {
    std::cout << seq->Get(index) << "\n";
}

void getSub(Sequence<int>* seq, int start, int end) {
    auto* subbed = seq->GetSubsequence(start, end);
    printSequence(subbed);
    delete subbed;
}

void concat(Sequence<int>* seq1, Sequence<int>* seq2) {
    auto* concated = seq1->Concat(seq2);
    printSequence(concated);
    delete concated;
}

void printSequenceActions() {
    std::cout << "1. Append" << std::endl;
    std::cout << "2. Prepend" << std::endl;
    std::cout << "3. Insert" << std::endl;
    std::cout << "4. Get" << std::endl;
    std::cout << "5. GetSubSequence" << std::endl;
    std::cout << "6. Concat with 1,2,3" << std::endl;
    std::cout << "7. Output" << std::endl;
    std::cout << "8. Exit" << std::endl;
}

void printSequenceChoices() {
    std::cout << "Choose sequence to create:" << std::endl;
    std::cout << "1. Mutable array" << std::endl;
    std::cout << "2. Immutable array" << std::endl;
    std::cout << "3. Mutable list" << std::endl;
    std::cout << "4. Immutable list" << std::endl;
}


int main() {
    int seqChoice;
    Sequence<int>* seq = nullptr;
    Sequence<int>* seqForConcat = nullptr;
    int values[3] = {1, 2, 3};
    bool isMutable;
    printSequenceChoices();
    std::cin >> seqChoice;
    switch (seqChoice) {
        case 1:
            seq = new MutableArraySequence<int>();
            seqForConcat = new MutableArraySequence<int>(values, 3);
            isMutable = true;
            break;
        case 2:
            seq = new ImmutableArraySequence<int>();
            seqForConcat = new ImmutableArraySequence<int>(values, 3);
            isMutable = false;
            break;
        case 3:
            seq = new MutableListSequence<int>();
            seqForConcat = new MutableListSequence<int>(values, 3);
            isMutable = true;
            break;
        case 4:
            seq = new ImmutableListSequence<int>();
            seqForConcat = new ImmutableListSequence<int>(values, 3);
            isMutable = false;
            break;
        default:
            return 1;

    }
    int choice;
    printSequenceActions();
    while (std::cin >> choice && choice != 8) {
        int value;
        int index;
        int end;
        switch (choice) {
            case 1:
                std::cout << "Enter value to append: ";
                std::cin >> value;
                append(seq, value, isMutable);
                break;
            case 2:
                std::cout << "Enter value to prepend: ";
                std::cin >> value;
                prepend(seq, value, isMutable);
                break;
            case 3:
                std::cout << "Enter pair index/value to insert: ";
                std::cin >> index >> value;
                insert(seq, value, index, isMutable);
                break;
            case 4:
                std::cout << "Enter index to get: ";
                std::cin >> index;
                get(seq, index);
                break;
            case 5:
                std::cout << "Enter start, end indexes to getSubsequence: ";
                std::cin >> index >> end;
                getSub(seq, index, end);
                break;
            case 6:
                concat(seq, seqForConcat);
                break;
            case 7:
                printSequence(seq);
                break;
            default:
                std::cout << "Unknown choice." << std::endl;

        }
        printSequenceActions();
    }

    delete seq;
    delete seqForConcat;
    return 0;
}
