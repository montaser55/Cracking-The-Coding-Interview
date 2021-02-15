#include<bits/stdc++.h>
using namespace std;

int towerofhanoi(int n,int fromRod,int toRod,int auxRod){
    if(n==1){
        cout<<"Disk 1 moved from rod "<<fromRod<<" to rod "<<toRod<<endl;
        return 1;
    }
    int before=towerofhanoi(n-1,fromRod,auxRod,toRod);
    cout<<"Disk "<<n<<" moved from rod "<<fromRod<<" to rod "<<toRod<<endl;
    int after=towerofhanoi(n-1,auxRod,toRod,fromRod);
    return before+after+1;
}

int main(){
    int totalDisk=8;
    int fromRod=1;
    int toRod=3;
    int auxRod=2;
    cout<<towerofhanoi(totalDisk,fromRod,toRod,auxRod)<<endl;
}