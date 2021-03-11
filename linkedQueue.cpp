#include "linkedQueue.h"

template<class T>
LinkedQueue<T>::LinkedQueue(){
    frontPtr = nullptr;
    backPtr = nullptr;
}


template<class T>
bool LinkedQueue<T>::isEmpty() const{
    return frontPtr == nullptr;
}

template<class T>
bool LinkedQueue<T>::enqueue(const T& newEntry){
    Node<T>* newNodePtr = new Node<T>(newEntry);

    if(isEmpty()){
        frontPtr = newNodePtr;
        backPtr = newNodePtr;
    }else if(newNodePtr->getItem() < frontPtr->getItem()){
        newNodePtr->setNext(frontPtr);
        backPtr = frontPtr;
        frontPtr = newNodePtr;
    }else{
        Node<T>* tracker = frontPtr;
        while(tracker->getNext() != nullptr && !(newNodePtr->getItem() < tracker->getNext()->getItem())){
            tracker = tracker->getNext();
        }
        if(tracker->getNext() != nullptr){
            newNodePtr->setNext(tracker->getNext());
            tracker->setNext(newNodePtr);
            newNodePtr = nullptr;
        }else{
            newNodePtr->setNext(tracker->getNext());
            tracker->setNext(newNodePtr);
            backPtr = newNodePtr;
            tracker = nullptr;
            newNodePtr = nullptr;
        }
    }

    return true;
}

template<class T>
bool LinkedQueue<T>::dequeue(){
    bool canDQ = !isEmpty();

    if(canDQ){
        Node<T>* nodeToDeletePtr = frontPtr;

        frontPtr = frontPtr->getNext();

        nodeToDeletePtr->setNext(nullptr);
        delete nodeToDeletePtr;

        nodeToDeletePtr = nullptr;
    }

    return canDQ;
}

template<class T>
T LinkedQueue<T>::peekFront() const{
    bool canPeek = !isEmpty();

    if(canPeek){
        return frontPtr->getItem();
    }else{
        throw "Empty queue";
    }
}

template<class T>
LinkedQueue<T>::~LinkedQueue(){
    while(dequeue());
}