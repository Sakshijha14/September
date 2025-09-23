#include<iostream>
#include<vector>
using namespace std;
bool dfs(int node,int col,int color[],vector<int>adj[]){
    color[node]=col;
    for(auto it:adj[node]){
        if(color[it]==-1){
            if(dfs(it,!col,color,adj)==false)
            return false;
        }
        else if(color[it]==col){
            return false;
        }
    }
    return true;
}

bool ispartiton(int V,vector<int>adj[]){
    int color[V];
    for(int i=0;i<V;i++){
        color[i]=-1;
    }
    for(int i=0;i<V;i++){
        if(color[i]==-1){
            if(dfs(i,0,color,adj)==false)
            return false;
        }
    }
    return true;
}

void addedge(vector<int>adj[],int u,int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

int main(){
    vector<int>adj[4];
    addedge(adj,0,2);
    addedge(adj,0,3);
    addedge(adj,2,3);
    addedge(adj,3,1);

    bool output=ispartiton(4,adj);
    if(output){
        cout<<"1\n";
    }
    else{
        cout<<"0\n";
    }

    return 0;
}