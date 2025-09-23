#include<iostream>
#include<queue>
#include<vector>
using namespace std;
vector<int>bfsgr(int V,vector<int>adj[]){
    int visited[V]={0};
    visited[0]=1;
    queue<int>q;
    q.push(0);
    vector<int>bf;
    while(!q.empty()){
        int node=q.front();
        q.pop();
        bf.push_back(node);
        for(auto it:adj[node]){
            if(!visited[it]){
                visited[it]=1;
                q.push(it);
            }
        }
    }
    return bf;
}

void addedges(vector<int>adj[],int u,int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void print(vector<int>&output){
    for(int i=0;i<output.size();i++){
        cout<<output[i]<<" ";
    }
}

int main(){

    vector<int>adj[6];
    addedges(adj,0,1);
    addedges(adj,1,2);
    addedges(adj,1,3);
    addedges(adj,0,4);

    vector<int>output=bfsgr(5,adj);
    print(output);

    return 0;
}