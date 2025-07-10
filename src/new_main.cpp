#include <iostream>
#include "Stack.h"
#include "Queue.h"
#include "Deque.h"

int main() {
    Stack<int> stack;

    std::cout << "Pushing 10, 20, 30 onto the stack...\n";
    stack.Push(10);
    stack.Push(20);
    stack.Push(30);

    std::cout << "Current size: " << stack.Size() << "\n";
    std::cout << "Top element: " << stack.Peek() << "\n";

    std::cout << "Popping elements:\n";
    while (!stack.IsEmpty()) {
        std::cout << "Pop: " << stack.Pop() << "\n";
    }

    std::cout << "Is stack empty? " << (stack.IsEmpty() ? "Yes" : "No") << "\n";

    std::cout << "Pushing 42 and clearing...\n";
    stack.Push(42);
    stack.Clear();

    std::cout << "Size after Clear: " << stack.Size() << "\n";
    std::cout << "Is stack empty? " << (stack.IsEmpty() ? "Yes" : "No") << "\n";

    Queue<int> queue;

    std::cout << "Enqueuing 10, 20, 30 into the queue...\n";
    queue.Enqueue(10);
    queue.Enqueue(20);
    queue.Enqueue(30);

    std::cout << "Current size: " << queue.Size() << "\n";
    std::cout << "Front element: " << queue.Front() << "\n";

    std::cout << "Dequeuing elements:\n";
    while (!queue.IsEmpty()) {
        std::cout << "Dequeue: " << queue.Dequeue() << "\n";
    }

    std::cout << "Is queue empty? " << (queue.IsEmpty() ? "Yes" : "No") << "\n";

    std::cout << "Enqueuing 42...\n";
    queue.Enqueue(42);

    std::cout << "Front after enqueueing 42: " << queue.Front() << "\n";
    std::cout << "Size after enqueue: " << queue.Size() << "\n";

    Deque<int> deque;

    std::cout << "Pushing 10, 20, 30 to back...\n";
    deque.PushBack(10);
    deque.PushBack(20);
    deque.PushBack(30);

    std::cout << "Front: " << deque.Front() << "\n"; // 10
    std::cout << "Back: " << deque.Back() << "\n";   // 30
    std::cout << "Size: " << deque.Size() << "\n";   // 3

    std::cout << "Pushing 5, 0 to front...\n";
    deque.PushFront(5);
    deque.PushFront(0);

    std::cout << "Front: " << deque.Front() << "\n"; // 0
    std::cout << "Back: " << deque.Back() << "\n";   // 30
    std::cout << "Size: " << deque.Size() << "\n";   // 5

    std::cout << "Popping from front: " << deque.PopFront() << "\n"; // 0
    std::cout << "Popping from back: " << deque.PopBack() << "\n";   // 30

    std::cout << "Final state:\n";
    std::cout << "Front: " << deque.Front() << "\n"; // 5
    std::cout << "Back: " << deque.Back() << "\n";   // 20
    std::cout << "Size: " << deque.Size() << "\n";   // 3

    std::cout << "Dequeuing all:\n";
    while (!deque.IsEmpty()) {
        std::cout << deque.PopFront() << " ";
    }
    std::cout << "\nIs empty? " << (deque.IsEmpty() ? "Yes" : "No") << "\n";


    return 0;
}
