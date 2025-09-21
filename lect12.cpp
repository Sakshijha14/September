#include<iostream>
#include<vector>
using namespace std;

/*brute
bool matrix(vector<vector<int>>&arr,int target){
    int n=arr.size();
    int m=arr[0].size();
    

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j]==target){
                return true;
            }
        }
    }
    return false;
}*/

bool matrix(vector<vector<int>>&arr,int target){
    int n=arr.size();
    int m=arr[0].size();

    int l=0;
    int h=n*m-1;
    while(l<=h){
        int mid=(l+h)/2;
        int row=mid/m;
        int col=mid%m;

        if(arr[row][col]==target){
            return true;
        }
        else if(arr[row][col]<target){
            l=mid+1;
        }
        else{
            h=mid-1;
        }
    }
    return false;
}
int main(){

    vector<vector<int>>arr={
        {3, 4, 7, 9},
    {11, 12, 13, 18},
    {20, 21, 23, 29}
    };
    int target=11;

    cout<<"the matrix element found: "<<matrix(arr,target)<<endl;
}