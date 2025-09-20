#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<vector<int>>rotate(vector<vector<int>>&arr){
    int n=arr.size();
    int m=arr[0].size();
    

    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            swap(arr[i][j],arr[j][i]);
        }
    }

    for(int i=0;i<n;i++){
        reverse(arr[i].begin(),arr[i].end());
    }

    return arr;
}

int main(){
    vector<vector<int>>arr={
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };
    vector<vector<int>>output=rotate(arr);
    for(int i=0;i<output.size();i++){
        for(int j=0;j<output[0].size();j++){
            cout<<output[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}