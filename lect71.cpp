#include<iostream>
#include<vector>
#include<queue>
using namespace std;

bool detect(int source,vector<int>adj[],int visited[]){
    visited[source]=1;
    queue<pair<int,int>>q;
    q.push({source,-1});
    while(!q.empty()){
        int node=q.front().first;
        int parent=q.front().second;
        q.pop();


        for(auto it:adj[node]){
            if(!visited[it]){
                visited[it]=1;
                q.push({it,node});
            }
            else if(parent!=it){
                return true;
            }
        }
    }
    return false;
}
bool iscyle(int V,vector<int>adj[]){
    int visited[V]={0};
    for(int i=0;i<V;i++){
        if(!visited[i]){
            if(detect(i,adj,visited))
            return true;
        }
    }
    return false;
}

int main(){
    vector<int>adj[4]={{},{2},{1,3},{2}};
    bool output=iscyle(4,adj);
    if(output){
        cout<<"1\n";
    }
    else{
        cout<<"0\n";
    }

    return 0;
}