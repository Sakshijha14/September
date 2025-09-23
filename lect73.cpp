#include<iostream>
#include<vector>


#include<queue>
using namespace std;

vector<int>topo(int V,vector<int>adj[]){
    queue<int>q;
    vector<int>indegree(V,0);
    for(int i=0;i<V;i++){
       for(auto it:adj[i]){
        indegree[it]++;
       }
    }
    for(int i=0;i<V;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }
    vector<int>output;
    while(!q.empty()){
        int node=q.front();
        q.pop();
        output.push_back(node);
        for(auto it:adj[node]){
            indegree[it]--;
            if(indegree[it]==0){
                q.push(it);
            }
        }
    }
    return output;

}


int main(){
    vector<int>adj[6];
    adj[5].push_back(2);
    adj[5].push_back(0);
    adj[4].push_back(0);
    adj[4].push_back(1);
    adj[3].push_back(1);
    adj[2].push_back(3);

    vector<int>output=topo(6,adj);
    for(auto it:output){
        cout<<it<<" ";
    }
    cout<<endl;

    return 0;
}