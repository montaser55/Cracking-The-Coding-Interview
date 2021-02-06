#include<bits/stdc++.h>
using namespace std;

class animal{
    queue<int> cat,dog;
    int animalNo=1;
    public:
    void enqueue(string a){
        if(a=="cat"){
            cat.push(animalNo);
            animalNo++;
        }
        else if(a=="dog"){
            dog.push(animalNo);
            animalNo++;
        }
    }

    int anydequeue(){
        if(dog.empty() && cat.empty())
        {
            cout << "No cats or dogs available" << endl;
            return INT_MIN;
        }
        int temp;
        if (dog.front() < cat.front())
        {
            temp = dog.front();
            dog.pop();
        }
        else
        {
            temp = cat.front();
            cat.pop();
        }
        return temp;
        }

    int dequecat(){
        if(cat.empty()){
            cout<<"No cats available"<<endl;
            return INT_MIN;
        }
        int temp=cat.front();
        cat.pop();
        return temp;

    }

    int dequedog()
    {
        if (dog.empty())
        {
            cout << "No dogs available" << endl;
            return INT_MIN;
        }
        int temp = dog.front();
        dog.pop();
        return temp;
    }
};



int main(){
    animal a;
    a.enqueue("cat");
    a.enqueue("cat");
    a.enqueue("dog");
    cout<<a.anydequeue()<<endl;
    cout<<a.dequedog()<<endl;
    cout << a.dequecat() << endl;
}