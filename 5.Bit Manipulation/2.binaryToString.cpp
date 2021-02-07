#include<bits/stdc++.h>
using namespace std;


string binaryToString(double n){
    if(n>1||n<0)return "Error";
    else if(n==0)return "0";
    else if(n==1)return "1";
    string result="0.";
    while(n!=0){
        if(result.length()>=34)return result;
        n=n*2;
        if(n>=1){result+="1";n-=1;}
        else{result+="0";}
    }
    return result;
}
int main(){
    double num=.75;
    cout<<binaryToString(num)<<endl;
}