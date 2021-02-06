#include<bits/stdc++.h>
using namespace std;
class myQueue{
    stack<int> s1,s2;
    public:
    void enqueue(int v){
        s1.push(v);
    }

    int dequeue(){
        if(s2.empty() && s1.empty())return INT_MIN;
        else if (s2.empty()){
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
        }
        int temp= s2.top();
        s2.pop();
        return temp;
    }

    int size(){
        return s1.size()+s2.size();
    }

};

int main(){
    myQueue q;
    for(int i=1;i<=10;i++){
        q.enqueue(i);
    }
    for (int i = 1; i <= 10; i++)
    {
        cout<<q.dequeue()<<endl;
    }
}