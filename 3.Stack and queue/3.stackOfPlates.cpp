#include<bits/stdc++.h>
using namespace std;

class StackofPlates{
    vector<stack<int>> stacks;
    int currStack=0;
    int threshold=0;
    public:
    StackofPlates(int t){
        stack<int> s;
        stacks.push_back(s);
        threshold=t;
    }

    void push(int d){
        if(stacks[currStack].size()>=threshold){
            stack<int> s;
            stacks.push_back(s);
            currStack++;
            stacks[currStack].push(d);

        }
        else{
            stacks[currStack].push(d);
        }
    }

    void pop(){
        if(stacks[currStack].size()>0){
            stacks[currStack].pop();
        }
        else{
            if(currStack==0)cout<<"Stack Empty"<<endl;
            else {
                stacks.pop_back();
                currStack--;
                stacks[currStack].pop();
            }
        }
    }

    int top(){
        if (stacks[currStack].size() > 0)
        {
            return stacks[currStack].top();
        }
        else {
            if(currStack==0){
                return INT_MIN;
            }
            else
                return stacks[currStack-1].top();
        }
    }

    void popAt(int indx){
        if(indx<stacks.size()){
            if(stacks[indx-1].size()==0){cout<<"Stack "<<indx<<" is Empty"<<endl;return;}
            else stacks[indx-1].pop();
        }
        else {
            cout << "Stack " << indx << " does not exists." << endl;
            return;
        }
    }

    int topAt(int indx)
    {
        if (indx < stacks.size())
        {
            if (stacks[indx - 1].size() == 0)
            {
                //cout << "Stack " << indx << " is Empty" << endl;
                return INT_MIN;
            }
            else
                return stacks[indx - 1].top();
        }
        else
        {
            //cout << "Stack " << indx << " does not exists." << endl;
            return INT_MIN;
        }
    }
};


int main(){
    StackofPlates s(6);
    for(int i=0;i<30;i++){
        s.push(i);
    }
    s.popAt(2);
    for (int i = 0; i < 30; i++)
    {
        cout<<s.top()<<endl;
        s.pop();
    }
}