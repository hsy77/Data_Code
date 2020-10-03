//
// Created by rain on 2019/9/13.
//

#ifndef CIRQUEUE_CIRQUEUE_H
#define CIRQUEUE_CIRQUEUE_H
enum error_code{overflow,underflow,success};
const int maxqueue = 20;

template <class queue_entry>
class CirQueue {
public:
    CirQueue();
    bool empty() const ;
    error_code serve();
    error_code append(const queue_entry &item);
    error_code retrieve(queue_entry &item) const ;
    bool full() const ;
    int size() const ;
    void clear();
    error_code serve_and_retrieve(queue_entry &item);

private:
    int count;
    int front,rear;
    queue_entry array[maxqueue];
};


#endif //CIRQUEUE_CIRQUEUE_H

template <class queue_entry>
CirQueue<queue_entry>::CirQueue(){
    count=0;
    front=0;
    rear=maxqueue-1;
}

template <class queue_entry>
bool CirQueue<queue_entry>::empty() const {
    return count==0;
}

template <class queue_entry>
error_code CirQueue<queue_entry>:: serve(){
    if (count<=0) return underflow;
    front=(front+1) % maxqueue;
    count--;
    return success;
}

template <class queue_entry>
error_code CirQueue<queue_entry>:: append(const queue_entry &item){
    if (count>=maxqueue) return overflow;
    rear=(rear+1) % maxqueue;
    array[rear]=item;
    count++;
    return success;
}

template <class queue_entry>
error_code CirQueue<queue_entry>:: retrieve(queue_entry &item) const {
    if (count<=0) return underflow;
    item=array[front];
    return success;
}

template <class queue_entry>
bool CirQueue<queue_entry>:: full() const{
    return count==maxqueue;
}

template <class queue_entry>
int CirQueue<queue_entry>::size() const{
    return count;
}

template <class queue_entry>
void CirQueue<queue_entry>::clear(){
    count=0;
    front=0;
    rear=maxqueue-1;
}

template <class queue_entry>
error_code CirQueue<queue_entry>:: serve_and_retrieve(queue_entry &item){
    if (count<=0) return underflow;
    item=array[front];
    front=(front+1) % maxqueue;
    count--;
    return success;
}