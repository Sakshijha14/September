#include<iostream>
#include<vector>

#include<algorithm>
using namespace std;

void printanswer(vector<vector<int>>&output){
    cout<<"the unique subset is: "<<endl;
    cout<<"[";
    for(int i=0;i<output.size();i++){
        cout<<"[";
        for(int j=0;j<output[i].size();j++){
            cout<<output[i][j]<<" ";
        }
        cout<<"]";
    }
    cout<<"]";
}


class Solution{

    public:
    void sumsubet(int index,vector<int>&arr,vector<int>&datastructure,int n,vector<vector<int>>&output){
        
            output.push_back(datastructure);
        
        for(int i=index;i<n;i++){
            if(i!=index && arr[i]==arr[i-1])
            continue;

            datastructure.push_back(arr[i]);

            sumsubet(i+1,arr,datastructure,n,output);
            datastructure.pop_back();
        }
    }

        vector<vector<int>>subset(vector<int>&arr,int n){
            vector<vector<int>>output;
            vector<int>datastructure;
            sort(arr.begin(),arr.end());
            sumsubet(0,arr,datastructure,n,output);

            return output;
        }
    
};

int main(){

    Solution obj;
    int n=3;
    vector<int>arr={1,2,2};
    vector<vector<int>>output=obj.subset(arr,n);
    printanswer(output);

    return 0;
}