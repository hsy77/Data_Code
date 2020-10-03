//
// Created by rain on 2019/9/28.
//

#include "myQueue.h"
template<class Queue_entry>
MyQueue<Queue_entry>::MyQueue()
/*
Post: The Queue is initialized to be empty.
*/
{
    count = 0;
    rear = -1;
    front = 0;
}

template<class Queue_entry>
bool MyQueue<Queue_entry>::empty() const
/*
Post: Return true if the Queue is empty, otherwise return false.
*/
{
    return count == 0;
}

template<class Queue_entry>
Error_code MyQueue<Queue_entry>::append(const Queue_entry &item)
/*
Post: item is added to the rear of the Queue. If the Queue is full
return an Error_code of overflow and leave the Queue unchanged.
*/
{
//队尾下标已经到达数组的末尾。则溢出
    if (rear >= maxqueue-1) return overflow;
    count++;
    rear++; //队尾下标往后移
    entry[rear] = item; //新的元素入队
    return success;
}

template<class Queue_entry>
Error_code MyQueue<Queue_entry>::serve()
/*
Post: The front of the Queue is removed. If the Queue
is empty return an Error_code of underflow.
*/
{
    if (count <= 0) return underflow;
    count--;
    front++;// 队首下标直接往后移
    return success;
}

template<class Queue_entry>
Error_code
MyQueue <Queue_entry>::retrieve(Queue_entry &item) const
/*
Post: The front of the Queue retrieved to the output
      parameter item. If the Queue is empty return an Error_code of underflow.
*/
{
    if (count <= 0) return underflow;
    item = entry[front]; //读取队首下标位置的值
    return success;
}

template<class Queue_entry>
int MyQueue<Queue_entry>::size() const
/*
Post:   Return the number of entries in the Queue.
*/
{
    return count;
}

template<class Queue_entry>
bool MyQueue<Queue_entry>::full() const
/*
Post:   Return true if the Queue is full, otherwise return false.
*/
{
    return(rear==maxqueue-1);
}

template<class Queue_entry>
void MyQueue<Queue_entry>::clear()
/*
Post:   Return an empty Queue.
*/
{
    count = 0;
    rear = -1 ;
    front = 0;
}

template<class Queue_entry>
Error_code MyQueue<Queue_entry>::serve_and_retrieve(Queue_entry &item)
/*
Post: The front of the Queue retrieved to the output
      parameter item. And also the front of the Queue is removed. If the Queue
      is empty return an Error_code of underflow.
*/
{
    if (count <= 0) return underflow;
    item = entry[front];
    count--;
    front++;
    return success;;
}