#include <iostream>
#include <cassert>
#include "Queue.h"
#include "Stack.h"
#include "Deque.h"


void TestStack() {
    Stack<int> stack;
    try {
        stack.Pop();
        assert(false);
    } catch (const std::out_of_range& e) {
        std::cout << "Caught expected error: " << e.what() << "\n";
    }
    stack.Push(10);
    stack.Push(20);
    stack.Push(30);

    assert(stack.Size() == 3);
    assert(stack.Pop() == 30);
    assert(stack.Size() == 2);
    assert(stack.Peek() == 20);

    stack.Push(30);
    while (!stack.IsEmpty()) {
        std::cout << stack.Pop() << " ";
    }
    std::cout << std::endl;
    assert(stack.IsEmpty());
    stack.Push(10);
    stack.Clear();
    assert(stack.IsEmpty());
}

void TestQueue() {
    Queue<int> queue;
    try {
        queue.Dequeue();
        assert(false);
    } catch (const std::out_of_range& e) {
        std::cout << "Caught expected error: " << e.what() << "\n";
    }
    queue.Enqueue(10);
    queue.Enqueue(20);
    queue.Enqueue(30);

    assert(queue.Size() == 3);
    assert(queue.Front() == 10);

    while (!queue.IsEmpty()) {
        std::cout << queue.Dequeue() << " ";
    }
    std::cout << std::endl;

    int value = 42;
    queue.Enqueue(value);
    assert(queue.Dequeue() == value);

    assert(queue.IsEmpty());
    queue.Enqueue(value);
    queue.Clear();
    assert(queue.IsEmpty());
}

void TestDeque() {
    Deque<int> deque;
    try {
        deque.PopBack();
        assert(false);
    } catch (const std::out_of_range& e) {
        std::cout << "Caught expected error: " << e.what() << "\n";
    }

    try {
        deque.PopFront();
        assert(false);
    } catch (const std::out_of_range& e) {
        std::cout << "Caught expected error: " << e.what() << "\n";
    }

    deque.PushBack(10);
    deque.PushBack(20);
    deque.PushBack(30);

    assert(deque.Size() == 3);
    assert(deque.Front() == 10);
    assert(deque.Back() == 30);

    deque.PushFront(5);
    deque.PushFront(0);

    assert(deque.Size() == 5);
    assert(deque.Front() == 0);

    while (!deque.IsEmpty()) {
        std::cout << deque.PopFront() << " ";
    }
    std::cout << std::endl;

    deque.PushBack(10);
    deque.PushBack(20);
    deque.PushBack(30);
    deque.PushFront(5);
    deque.PushFront(0);

    assert(deque.PopBack() == 30);
    assert(deque.PopFront() == 0);
    assert(deque.Size() == 3);

    deque.Clear();
    assert(deque.IsEmpty());

}


int main() {
    TestStack();
    std::cout << "Stack passed all tests" << std::endl;
    TestQueue();
    std::cout << "Queue passed all tests" << std::endl;
    TestDeque();
    std::cout << "Deque passed all tests" << std::endl;
}