#pragma once
#include <stdexcept>

template <typename T>
class LinkedList {

    struct Node {
        T data;
        Node* next;

        explicit Node(const T& data) : data(data), next(nullptr) {}
    };

    Node *head;
    Node *tail;
    int size;

public:
    LinkedList() : head(nullptr), tail(nullptr), size(0) {}

    LinkedList(T* items, int const count) : head(nullptr), tail(nullptr) {
        if (count < 0) {
            throw std::invalid_argument("count must be positive");
        }
        size = 0;
        for (int i = 0; i < count; i++) {
            Append(items[i]);
        }
    }

    LinkedList(const LinkedList& other) : head(nullptr), tail(nullptr), size(0) {
        Node* current = other.head;
        while (current) {
            Append(current->data);
            current = current->next;
        }
    }

    ~LinkedList() {
        Clear();
    }

    void Clear() {
        Node* current = head;
        while (current) {
            Node *prev = current;
            current = current->next;
            delete prev;
        }

        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    void Append(T item) {
        Node* new_node = new Node(item);
        if (!head) {
            head = new_node;
            tail = new_node;
        } else {
            tail->next = new_node;
            tail = tail->next;
        }
        ++size;
    }

    void Prepend(T item) {
        Node* new_node = new Node(item);
        if (!head) {
            head = new_node;
            tail = new_node;
        } else {
            new_node->next = head;
            head = new_node;
        }
        ++size;
    }

    T GetFirst() {
        if (!head) {
            throw std::out_of_range("list is empty");
        }
        return head->data;
    }

    T GetLast() {
        if (!tail) {
            throw std::out_of_range("list is empty");
        }
        return tail->data;
    }

    T Get(int index) {
        if (index < 0 || index >= size) {
            throw std::out_of_range("index out of range");
        }

        Node* node = head;
        for (int i = 0; i < index; i++) {
            node = node->next;
        }

        return node->data;
    }

    void InsertAt(T item, const int index) {
        if (index < 0 || index > size) {
            throw std::out_of_range("index out of range");
        }

        if (index == 0) {
            Prepend(item);
            return;
        }

        if (index == size) {
            Append(item);
            return;
        }

        Node* new_node = new Node(item);
        Node* current = head;
        for (int i = 0; i < index-1; i++) {
            current = current->next;
        }

        new_node->next = current->next;
        current->next = new_node;
        ++size;
    }

    LinkedList* GetSubList(int startindex, int endindex) {
        if (startindex < 0 || startindex >= size || endindex < 0 || endindex >= size) {
            throw std::out_of_range("index out of range");
        }
        if (endindex < startindex) {
            throw std::invalid_argument("startindex should be less or equal to endindex");
        }
        auto SubList = new LinkedList();
        for (int i = startindex; i <= endindex; i++) {
            SubList->Append(Get(i));
        }
        return SubList;
    }

    LinkedList* Concat(LinkedList *other) {
        auto ConcatList = new LinkedList(*this);

        for (int i = 0; i < other->size; i++) {
            ConcatList->Append(other->Get(i));
        }

        return ConcatList;
    }

    int GetLength() {
        return size;
    }
};
