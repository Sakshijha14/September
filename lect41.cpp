#include<iostream>
#include<vector>

#include<algorithm>
using namespace std;

void setfunct(int index,int target,vector<int>&arr,vector<int>&ds,vector<vector<int>>&output){
    if(target==0){
        output.push_back(ds);
        return ;
    }
    int n=arr.size();
    for(int i=index;i<n;i++){
        if(i!=index && arr[i]==arr[i-1])
        continue;

        if(arr[i]<=target){
            ds.push_back(arr[i]);
            setfunct(i,target-arr[i],arr,ds,output);
            ds.pop_back();
        }
    }
}

    vector<vector<int>>set2(vector<int>&arr,int target){
        sort(arr.begin(),arr.end());
        vector<int>ds;
        vector<vector<int>>output;
        setfunct(0,target,arr,ds,output);
        return output;
    }


int main(){
    vector<int>nums={10,1,2,7,6,1,5};
    int target=8;
    vector<vector<int>>output=set2(nums,target);
    cout<<"[";
    for(int i=0;i<output.size();i++){
        cout<<"[";
        for(int j=0;j<output[i].size();j++){
            cout<<output[i][j]<<" ";
        }
        cout<<"]";
    }
    cout<<"]";

    return 0;
    
}