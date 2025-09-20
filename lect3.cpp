#include<iostream>
#include<climits>
#include<vector>

using namespace std;

/*better
int maxsum(vector<int>&arr,int n){
   
    int maxsumm=INT_MIN;
    for(int i=0;i<n;i++){
        int summing=0;
        for(int j=i;j<n;j++){
            
            summing+=arr[j];
            maxsumm=max(maxsumm,summing);
        }
       
    }

    return maxsumm;
}

*/

int maxsum(vector<int>&arr,int n){

    int maxsumm=INT_MIN;
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];

        if(sum>0){
            maxsumm=max(maxsumm,sum);
        }

        if(sum<0){
            sum=0;
        }
    }
    return maxsumm;
}

int main(){


    vector<int>arr={-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int n=arr.size();
    int output=maxsum(arr,n);
    cout<<"the maximum sum is: "<<output<<endl;
}