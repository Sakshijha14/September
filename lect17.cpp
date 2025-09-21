#include<iostream>
#include<vector>
#include<map>
using namespace std;

vector<int>sum(int n,vector<int>&arr,int target){
    map<int,int>mp;
    for(int i=0;i<n;i++){
        int first=arr[i];
        int need=target-first;
        if(mp.find(need)!=mp.end()){
            return {mp[need],i};
        }
        mp[first]=i;
    }
    return {-1,-1};
}

int main(){
    int n=5;
    vector<int>arr={2,6,5,8,11};
    int target=14;
    vector<int>output=sum(n,arr,target);
    cout<<"this is the output "<<output[0]<<","<<output[1]<<endl;

    return 0;
}