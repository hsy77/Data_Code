#include <iostream>
#include <map>
using namespace std;
int main() {
    struct pair{
        int a[2];
    };
    map<int,pair> hash;
    cout<<"how much number do you want to enter:";
    int n;
    cin>>n;
    int array[n+1];
    for (int i=1;i<=n;i++){
        int m;
        cin>>m;
        array[i]=m;
    }
    int sum_count=n*(n-1)/2;
    for (int i=1;i<n;i++){
        for(int j=i+1;j<=n;j++){
            int sum=array[i]+array[j];
            pair a={i,j};
            hash[sum]=a;
        }
    }
    int target;
    cout<<"enter target:";
    cin>>target;
    int found[2];
    found[0]=hash[target].a[0];
    found[1]=hash.find(target)->second.a[1];
    cout<<'['<<found[0]<<','<<found[1]<<']'<<endl;
    return 0;
}
//4
//2 7 11 15