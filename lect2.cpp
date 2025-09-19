#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int>solve(vector<int>&arr){
    int n=arr.size();
    int index=-1;
    
    for(int i=0;i<n;i++){
        if(arr[i]<arr[i+1]){
            index=i;
            break;
        }
    }
    if(index==-1){
        reverse(arr.begin(),arr.end());
        return arr;
    }

    for(int i=n-1;i>=index;i--){
        if(arr[i]>arr[index]){
            swap(arr[i],arr[index]);
            reverse(arr.begin()+index+1,arr.end());
        }
    }
    return arr;

}

int main(){
    vector<int>arr={2,1,5,4,3,0,0};
    vector<int>output=solve(arr);
    cout<<"the next permutation is: ";
    for(int i=0;i<arr.size();i++){
        cout<<output[i]<<" ";
    }
    cout<<endl;

    return 0;
}