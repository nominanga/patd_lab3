#include <iostream>
#include "Queue.h"
#include "Stack.h"
#include "Deque.h"

void dequeMenu() {
    std::cout << "Deque:" << std::endl;
    std::cout << "0. Exit" << std::endl;
    std::cout << "1. PushFront" << std::endl;
    std::cout << "2. Front" << std::endl;
    std::cout << "3. PopFront" << std::endl;
    std::cout << "4. PushBack" << std::endl;
    std::cout << "5. Back" << std::endl;
    std::cout << "6. PopBack" << std::endl;
    std::cout << "7. Clear" << std::endl;
    std::cout << "8. Size" << std::endl;
}

void queueMenu() {
    std::cout << "Queue:" << std::endl;
    std::cout << "0. Exit" << std::endl;
    std::cout << "1. Enqueue" << std::endl;
    std::cout << "2. Front" << std::endl;
    std::cout << "3. Dequeue" << std::endl;
    std::cout << "4. Clear" << std::endl;
    std::cout << "5. Size" << std::endl;

}

void stackMenu() {
    std::cout << "Stack:" << std::endl;
    std::cout << "0. Exit" << std::endl;
    std::cout << "1. Push" << std::endl;
    std::cout << "2. Peek" << std::endl;
    std::cout << "3. Pop" << std::endl;
    std::cout << "4. Clear" << std::endl;
    std::cout << "5. Size" << std::endl;
}

void dequeRun() {
    Deque<int> deque;
    dequeMenu();
    int choice;
    while (std::cin >> choice && choice != 0) {
        int value;
        switch (choice) {
            case 1:
                std::cout << "Enter an integer: ";
                std::cin >> value;
                deque.PushFront(value);
                break;
            case 2:
                std::cout << "Front: " << deque.Front() << std::endl;
                break;
            case 3:
                std::cout << "PopFront: " << deque.PopFront() << std::endl;
                break;
            case 4:
                std::cout << "Enter an integer: ";
                std::cin >> value;
                deque.PushBack(value);
                break;
            case 5:
                std::cout << "Back: " << deque.Back() << std::endl;
                break;
            case 6:
                std::cout << "PopBack: " << deque.PopBack() << std::endl;
                break;
            case 7:
                std::cout << "Clearing\n";
                deque.Clear();
                break;
            case 8:
                std::cout << "Size: " << deque.Size() << std::endl;
                break;
            default:
                std::cout << "Invalid choice" << std::endl;
        }
        dequeMenu();
    }
}

void queueRun() {
    Queue<int> queue;
    queueMenu();
    int choice;
    while (std::cin >> choice && choice != 0) {
        int value;
        switch (choice) {
            case 1:
                std::cout << "Enter an integer: ";
                std::cin >> value;
                queue.Enqueue(value);
                break;
            case 2:
                std::cout << "Front: " << queue.Front() << std::endl;
                break;
            case 3:
                std::cout << "Dequeue: " << queue.Dequeue() << std::endl;
                break;
            case 4:
                std::cout << "Clearing\n" << std::endl;
                queue.Clear();
                break;
            case 5:
                std::cout << "Size: " << queue.Size() << std::endl;
                break;
            default:
                std::cout << "Invalid choice" << std::endl;
        }
        queueMenu();
    }
}

void stackRun() {
    Stack<int> stack;
    stackMenu();
    int choice;
    while (std::cin >> choice && choice != 0) {
        int value;
        switch (choice) {
            case 1:
                std::cout << "Enter an integer: ";
                std::cin >> value;
                stack.Push(value);
                break;
            case 2:
                std::cout << "Peek: " << stack.Peek() << std::endl;
                break;
            case 3:
                std::cout << "Pop: " << stack.Pop() << std::endl;
                break;
            case 4:
                std::cout << "Clearing\n";
                stack.Clear();
                break;
            case 5:
                std::cout << "Size: " << stack.Size() << std::endl;
                break;
            default:
                std::cout << "Invalid choice" << std::endl;
        }
        stackMenu();
    }
}




int main() {
    std::cout << "Choose structure: " << std::endl;
    std::cout << "1. Queue" << std::endl;
    std::cout << "2. Stack" << std::endl;
    std::cout << "3. Deque" << std::endl;

    int choice;
    std::cin >> choice;

    switch (choice) {
        case 1:
            queueRun();
            break;
        case 2:
            stackRun();
            break;
        case 3:
            dequeRun();
            break;
        default:
            std::cout << "Invalid Choice." << std::endl;
    }


    return 0;
}
