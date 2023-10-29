//
//  CircularBuffer.h
//  Periscope
//
//  Created by Brian Williams on 29/10/2023.
//

#ifndef CircularBuffer_h
#define CircularBuffer_h

#include <vector>
#include <stdexcept>

template<typename T>
class CircularBuffer {
private:
    std::vector<T> buffer;
    int capacity;
    int size;
    int head;
    int tail;

public:
    CircularBuffer(int capacity)
        : buffer(capacity), capacity(capacity), size(0), head(0), tail(0) {}

    bool empty() const {
        return size == 0;
    }

    bool full() const {
        return size == capacity;
    }

    int getCapacity() const {
        return capacity;
    }

    int getSize() const {
        return size;
    }

    void push(const T& value) {
        buffer[tail] = value;
        tail = (tail + 1) % capacity;
        if (size < capacity) {
            size++;
        } else {
            head = (head + 1) % capacity; // If buffer is full, head moves to the next element.
        }
    }

    T pop() {
        if (empty()) {
            throw std::runtime_error("Buffer is empty");
        }

        T value = buffer[head];
        head = (head + 1) % capacity;
        size--;
        return value;
    }

    T& front() {
        if (empty()) {
            throw std::runtime_error("Buffer is empty");
        }

        return buffer[head];
    }

    T& back() {
        if (empty()) {
            throw std::runtime_error("Buffer is empty");
        }

        return buffer[(tail - 1 + capacity) % capacity];
    }
};

#endif /* CircularBuffer_h */
