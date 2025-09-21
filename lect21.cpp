#include<iostream>
#include<vector>
using namespace std;

/*brute
int subarrays(vector<int>&arr,int m){
    int n=arr.size();
    int count=0;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            int xorr=0;
            for(int k=i;k<=j;k++){
                xorr^=arr[k];
            }

            if(xorr==m){
                count++;
            }
        }
    }
    return count;
}*/

int subarrays(vector<int>&arr,int m){
    int n=arr.size();
    int count=0;

    for(int i=0;i<n;i++){
        int xorr=0;
        for(int j=i;j<n;j++){
            xorr^=arr[j];

            if(xorr==m){
                count++;
            }
        }
    }
    return count;
}
int main(){
    vector<int>arr={4,2,2,6,4};
    int m=6;
    int output=subarrays(arr,m);
    cout<<"the number of subarray with xor k is: "<<output<<endl;
    return 0;
}