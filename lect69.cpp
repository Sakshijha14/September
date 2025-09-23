#include<iostream>

#include<vector>
using namespace std;

void dfs(int node,vector<int>adj[],int visited[],vector<int>&path){
    visited[node]=1;
    path.push_back(node);
    for(auto it:adj[node]){
        if(!visited[it]){
            dfs(it,adj,visited,path);
        }
    }
}
vector<int>dfsgr(int V,vector<int>adj[]){
    int visited[V]={0};
    int start=0;
    vector<int>path;
    dfs(start,adj,visited,path);
    return path;
}

void addedge(vector<int>adj[],int u,int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}


void print(vector<int>&output){
    for(int i=0;i<output.size();i++){
        cout<<output[i]<<" ";
    }
}

int main(){
    vector<int>adj[5];
    addedge(adj,0,2);
    addedge(adj,2,4);
    addedge(adj,0,1);
    addedge(adj,0,3);

    vector<int>output=dfsgr(5,adj);

    print(output);

    return 0;


}