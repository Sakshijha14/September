#include<iostream>
#include<vector>

#include<map>
using namespace std;

int majorityelement(vector<int>&arr){

    int n=arr.size();

    map<int,int>mp;

    for(int i=0;i<n;i++){
        mp[arr[i]]++;
    }
    for(auto it:mp){
        if(it.second>(n/2)){
            return it.first;
        }
    }
    return -1;
}

int main(){
    
    vector<int>arr={2,2,1,1,1,2,2};
    int output=majorityelement(arr);
    cout<<"the majority element is: "<<output<<endl;

    return 0;
}