//
// Created by rain on 2019/9/27.
//

#ifndef MAZE_MAZE_H
#define MAZE_MAZE_H

//#include <CirQueue>


enum  Error_code{underflow, overflow, success};
const int maxqueue = 20; //  small value for testing
template<class Queue_entry>
class MyQueue{
public:
    MyQueue();
    bool empty() const;
    Error_code serve();
    Error_code append(const Queue_entry &item);
    Error_code retrieve(Queue_entry &item) const;
    bool full() const;
    int size() const;
    void clear();
    Error_code serve_and_retrieve(Queue_entry &item);
private:
    int count;
    int front, rear;
    Queue_entry entry[maxqueue];
};

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
{
    if (count <= 0) return underflow;
    item = entry[front];
    count--;
    front++;
    return success;;
}

const int maxcolrow=8;

struct point{
    int row;
    int col;
};

class Maze {
public:
    Maze();
    void initMaze(int *p_maze,int n_colrow_);
    void PrintBfsPath();
    void printMaze();

private:
    point cur,next;
    bool cango_(int row,int col);
    int matrix_[maxcolrow+2][maxcolrow+2];
    int visitedBFS_[maxcolrow+2][maxcolrow+2];
    point PathBFS_[maxcolrow+2][maxcolrow+2];//存放结构
    point pstart;
    point pend;
    int n_colrow;
    MyQueue<point> maxqueue_;
};
#endif //MAZE_MAZE_H
