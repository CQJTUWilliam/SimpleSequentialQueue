//
// Created by william on 20-1-15.
//

#ifndef SEQUENTIALQUEUE_SEQUENTIALQUEUE_H
#define SEQUENTIALQUEUE_SEQUENTIALQUEUE_H

#include <cstddef>
#include <cstdlib>

/*
 *非循环式顺序队列（无法解决数据不连续，内存无法有效利用问题)
 */
template <class T>
class SequentialQueue {
private:
    T* head;
    T* tail;

    T* data;

    size_t capacity;
    size_t  size;
public:
    T* dequeue();
    bool enqueue(T value);

public:
    explicit SequentialQueue(size_t capacity = 10);
};

//考虑入队时进行数据迁移(unimplemented)
template<class T>
T* SequentialQueue<T>::dequeue() { //覆盖式出列
    if(head == nullptr || head == tail){//there is no data
        return nullptr;
    }

    T* temp = nullptr;
    temp = head;
    head++;
    size--;
    return temp;

}

template<class T>
bool SequentialQueue<T>::enqueue(T value) {
    if(size == capacity-1){
        return false;
    }

    if(size == 0){
        head = data;
    }
    *tail++ = value;
    size++;
}


template<class T>
SequentialQueue<T>::SequentialQueue(size_t capacity) {
    data = new T[capacity];
    head = nullptr;
    tail = data;
    size = 0;
    this->capacity = capacity;
}



#endif //SEQUENTIALQUEUE_SEQUENTIALQUEUE_H
