#ifndef LINKED_QUEUE
#define LINKED_QUEUE

#include "queue.h"
#include "node.h"

template<class T>
class LinkedQueue : public QueueInterface<T> {
private:
    Node<T>* frontPtr;
    Node<T>* backPtr;
public:
    LinkedQueue();

    bool isEmpty() const;
    bool enqueue(const T& newEntry);
    bool dequeue();
    T peekFront() const;

    ~LinkedQueue();

};
#include "linkedQueue.cpp"
#endif