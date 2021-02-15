#include<bits/stdc++.h>
using namespace std;

class Graph{
    int V;
    vector<int> *adj;
    public:
    Graph(int ver){
        V=ver;
        adj=new vector<int>[V];
    }

    void addEdge(int x,int y){
        adj[x].push_back(y);
    }

    bool isRoute(int x,int y){
        vector<bool> visited(V,false);
        queue<int> q;

        q.push(x);
        while(!q.empty()){
            int curr=q.front();
            if (curr == y)
                return true;
            q.pop();
            visited[curr]=true;
            for(int i=0;i<adj[curr].size();i++){
                int temp=adj[curr][i];
                if(!visited[temp]){
                    q.push(temp);
                }
            }
        }
        return false;
    }

};   


int main(){
    Graph g(6);
    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);
    cout <<boolalpha<< g.isRoute(5, 4) << endl; 
    cout <<boolalpha<< g.isRoute(5, 1) << endl; 

    return 0;
}