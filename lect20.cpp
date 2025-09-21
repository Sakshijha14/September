#include<iostream>
#include<vector>
#include<map>
using namespace std;

int longestsum(vector<int>&arr){

    int n=arr.size();

    map<int,int>mp;
    int sum=0;
    int output=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];

        if(sum==0){
            output=i+1;
        }
        else if(mp.find(sum)!=mp.end()){
            output=max(output,i-mp[sum]);
        }
        else{
            mp[sum]=i;
        }
    }
    return output;
}



int main(){
    vector<int>arr={9,-3,3,-1,6,-5};
    cout<<longestsum(arr)<<endl;
}