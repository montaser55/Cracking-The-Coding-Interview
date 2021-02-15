#include<bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    Node* left;
    Node* right;
    Node(int v){
        val=v;
        left=NULL;
        right=NULL;
    }
};

void preOrder(Node *root){
    if (root==NULL){
        return;
    }
    cout<<root->val<<" ";
    preOrder(root->left);
    preOrder(root->right);
}
Node* createminimalBST(vector<int> a,int low,int high){
    if(low>high)return NULL;
    int mid=(low+high)/2;
    Node *root=new Node(a[mid]);
    root->left=createminimalBST(a,low,mid-1);
    root->right=createminimalBST(a,mid+1,high);
    return root;
}
Node* minimalBST(vector<int> a){
    return createminimalBST(a,0,a.size()-1);
}


int main(){
    vector<int> a={1,2,3,4,5,6,7};
    Node* root=minimalBST(a);
    preOrder(root);
}