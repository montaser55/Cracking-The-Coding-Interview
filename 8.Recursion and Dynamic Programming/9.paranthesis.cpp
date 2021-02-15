#include<bits/stdc++.h>
using namespace std;

void findParens(int count,int open,int close,string curr,vector<string> &result){
    if(close>open)return;
    if(open>count)return;
    if(curr.length()==2*count)result.push_back(curr);
    findParens(count,open+1,close,curr+"(",result);
    findParens(count,open,close+1,curr+")",result);
}

vector<string> findparensHelper(int count){
    vector<string> result;
    findParens(count,0,0,"",result);
    return result;
}

int main(){
    vector<string> result=findparensHelper(3);
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<endl;
    }
}