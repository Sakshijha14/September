#include<iostream>
#include<vector>
using namespace std;

class Solution{

    public:
    void nc(int i,int target,vector<int>&ds,vector<int>&arr,vector<vector<int>>&output){
        if(i==arr.size()){
            if(target==0){
                output.push_back(ds);
            }
            return ;
        }
        if(arr[i]<=target){
            ds.push_back(arr[i]);
            nc(i,target-arr[i],ds,arr,output);
            ds.pop_back();
        }
        nc(i+1,target,ds,arr,output);
    }

    vector<vector<int>>combine(vector<int>&arr,int target){
        vector<int>ds;
        vector<vector<int>>output;
        nc(0,target,ds,arr,output);
        return output;
    }

};

int main(){
    Solution obj;
    vector<int>arr{2,3,6,7};
    int target=7;

    vector<vector<int>>output=obj.combine(arr,target);
    cout<<"combination is: "<<endl;
    for(int i=0;i<output.size();i++){
        for(int j=0;j<output[i].size();j++){
            cout<<output[i][j]<<" ";
        }
        cout<<"\n";
    }
}