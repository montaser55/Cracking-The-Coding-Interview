#include<bits/stdc++.h>
using namespace std;

void findPermutation(string s,string curr,vector<string> &result){
    int n=s.length();
    if(n==0){
        result.push_back(curr);
        return;
    }
    for(int i=0;i<n;i++){
        string first=curr+s.substr(i,1);
        string rem=s.substr(0,i)+s.substr(i+1,n-i-1);
        findPermutation(rem,first,result);
    }
}

vector<string> permutationhelper(string a){
    vector<string> result;
    findPermutation(a,"",result);
    return result;
}

int main(){
    string a="abcd";
    vector<string> result=permutationhelper(a);
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<endl;
    }
}