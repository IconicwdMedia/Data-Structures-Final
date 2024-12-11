#ifndef STACKQUEUE_H
#define STACKQUEUE_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
using namespace std;

class StackQueue {
private:
    vector<int> stack;  // Stack for stack-based operations
    vector<int> queue;  // Queue for queue-based operations

public:
    StackQueue() {}

    // Stack Operations
    void push(int value) {
        stack.push_back(value); // Push to the stack
    }

    void pop() {
        if (!stack.empty()) {
            stack.pop_back(); // Pop from the stack
        }
    }

    int top() const {
        if (!stack.empty()) {
            return stack.back(); // Get the top element of the stack
        }
        return -1; // Indicating empty stack
    }

    bool isStackEmpty() const {
        return stack.empty(); // Check if the stack is empty
    }

    // Queue Operations
    void enqueue(int value) {
        queue.push_back(value); // Enqueue to the queue
    }

    void dequeue() {
        if (!queue.empty()) {
            queue.erase(queue.begin()); // Dequeue from the front
        }
    }

    int front() const {
        if (!queue.empty()) {
            return queue.front(); // Get the front element of the queue
        }
        return -1; // Indicating empty queue
    }

    bool isQueueEmpty() const {
        return queue.empty(); // Check if the queue is empty
    }

    // Visualize stack and queue
    void visualize(sf::RenderWindow& window, sf::Font& font);
};

#endif
