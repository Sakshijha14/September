#include<iostream>
#include<vector>
using namespace std;

int team(vector<int>&arr,int n){
    int output=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]>2*arr[j]){
                output++;
            }
        }
    }
    return output;
}

int main(){
    vector<int>arr={4,1,2,3,1};
    int n=5;
    int count=team(arr,n);
    cout<<"the number of reverse pairs is: "<<count<<endl;
}