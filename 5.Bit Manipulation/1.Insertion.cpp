#include<bits/stdc++.h>
using namespace std;
void dectoBin(int n){
    for(int i=31;i>=0;i--){
        int k=n>>i;
        if(k & 1)cout<<"1";
        else cout<<"0";
    }
    cout<<endl;
}

int insertion(int a,int b,int i,int j){
    int w=j-i;
    if(w<=0)return a;
    int mask=(~0<<(j+1)|(1<<i)-1);
    dectoBin(mask);
    return (a & mask)|(b<<i);
}
int main(){
    int result=insertion(0b11111111111111,0b10111,2,6);
    dectoBin(result);
}