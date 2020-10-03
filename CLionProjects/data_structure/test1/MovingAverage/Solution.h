//
// Created by rain on 2019/11/1.
//

#ifndef MOVINGAVERAGE_SOLUTION_H
#define MOVINGAVERAGE_SOLUTION_H

#include <queue>
using namespace std;
class MovingAverage {
public:
    MovingAverage(int n) {
        size=n;
    }

    double next(int val) {
        sum=0;

        if (q.size()>=size) {
            q.pop();
        }
        q.push(val);
        int len=q.size();
        if (len<size){
            for (int i=0;i<len;i++){
                int x=q.front();
                sum+=q.front();
                q.pop();
                q.push(x);
            }
            return sum/len;
        }
        else {
            for (int i=0;i<size;i++){
                int x=q.front();
                sum+=q.front();
                q.pop();
                q.push(x);
            }
            return sum/size;
        }
    }

private:
    queue<int> q;
    int size;
    double sum;
};



#endif //MOVINGAVERAGE_SOLUTION_H
