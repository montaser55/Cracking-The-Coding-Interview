#include<bits/stdc++.h>
using namespace std;

int flipone(int n){
    int result=1;
    int leftLength=0;
    int rightLength=0;

    while(n!=0){
        if(n & 1){
            leftLength++;
        }
        else{
            rightLength=leftLength;
            leftLength=0;
        }
        result = max(leftLength + rightLength + 1, result);
        n=n>>1;
    }
    return result;
}

int main(){
    cout<<flipone(0b111111011101)<<endl;
    cout << flipone(0b111101011101) << endl;
}
