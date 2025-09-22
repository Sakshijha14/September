#include<iostream>
#include<vector>

using namespace std;

void recur(int index,vector<int>&arr,vector<vector<int>>&output){

    if(index==arr.size()){
        output.push_back(arr);
        return ;
    }
    for(int i=index;i<arr.size();i++){
        swap(arr[index],arr[i]);
        recur(index+1,arr,output);
        swap(arr[index],arr[i]);
    }
}

int main(){
    vector<int>arr={1,2,3};
    vector<vector<int>>sum=permute(arr);
    cout<<"the permute "<<endl;
    for(int i=0;i<sum.size();i++){
        for(int j=0;j<sum[i].size();j++){
            cout<<sum[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}