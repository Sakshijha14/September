#include<iostream>
#include<vector>
using namespace std;

bool dfs(int node,int parent,int visited[],vector<int>adj[]){
    visited[node]=1;
    for(auto it:adj[node]){
        if(!visited[it]){
            if(dfs(it,node,visited,adj)==true){
                return true;
            }
        }
        else if(it!=parent){
            return true;
        }
    }
    return false;
}

bool detecting(int V,vector<int>adj[]){
    int visited[V]={0};
    for(int i=0;i<V;i++){
        if(!visited){
            if(dfs(i,-1,visited,adj)==true){
                return true;
            }
        }
    }
    return false;
}

int main(){
    vector<int>adj[4]={{},{2},{1,3},{2}};
    bool output=detecting(4,adj);
    if(output){
        cout<<"1\n";
    }
    else{
        cout<<"0\n";
    }

    return 0;
}