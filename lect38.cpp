#include<iostream>
#include<vector>

#include<algorithm>
using namespace std;

class Solution{

    public:
    void subsetsum(int index,vector<int>&arr,int n,vector<int>&output,int sum){
        if(index==n){
            output.push_back(sum);
            return ;
        }

        subsetsum(index+1,arr,n,output,sum+arr[index]);

        subsetsum(index+1,arr,n,output,sum);

    }

    vector<int>subset(vector<int>arr,int n){
        vector<int>input;
        subsetsum(0,arr,n,input,0);
        sort(input.begin(),input.end());
        return input;
    }
};

int main(){
    int n=3;
    vector<int>arr{3,1,2};
    Solution obj;
    vector<int>output=obj.subset(arr,n);
    //sort(output.begin(),output.end());
    cout<<"the sum of subset "<<endl;
    for(int i=0;i<output.size();i++){
        cout<<output[i]<<" ";
    }
    
    return 0;
}