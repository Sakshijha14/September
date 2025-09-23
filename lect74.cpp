#include<iostream>
#include<vector>

#include<queue>
using namespace std;

bool iscyclic(int V,vector<int>adj[]){
    int indegree[V]={0};
    for(int i=0;i<V;i++){
        for(auto it:adj[i]){
            indegree[it]++;
        }
    }
    queue<int>q;
    for(int i=0;i<V;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }
    int counting=0;
    while(!q.empty()){
        int node=q.front();
        q.pop();
        counting++;

        for(auto it:adj[node]){
            indegree[it]--;
            if(indegree[it]==0)
            q.push(it);
        }
    }
    if(counting==V){
        return false;
    }
    return true;
    
}
int main(){
    int V=6;
    vector<int>adj[6]={{},{2},{3},{4,5},{2},{}};
    bool output=iscyclic(V,adj);
    if(output){
        cout<<"true";
    }
    else{
        cout<<"false";
    }
    return 0;

}