#include<iostream>
#include<vector>
#include<map>
using namespace std;

/*better
vector<int>findmissingrepeat(vector<int>&arr){

    vector<int>output(2,-1);

    map<int,int>mp;
    for(int i=0;i<arr.size();i++){
        mp[arr[i]]++;
    }

    for(int i=1;i<=arr.size();i++){
        
        if(mp[i]>1){
            output[0]=i;
        }
        if(mp[i]==0){
            output[1]=i;
        }
    }
    return output;

}*/

vector<int>findmissingrepeat(vector<int>&arr){
    long long n=arr.size();
    long long sum=n*(n+1)/2;
    long long sum2=(n*(n+1)*(2*n+1))/6;

    long long s1=0;
    long long s2=0;
    for(int i=0;i<n;i++){
        s1+=arr[i];
        s2+=(long long )arr[i]*(long long)arr[i];
    }

    long long val=s1-sum;
    long long val2=s2-sum2;

    val2=val2/val;

    long long x=(val+val2)/2;
    long long y=x-val;

    return {(int)x,(int)y};
}

int main(){
    vector<int>arr={3, 1, 2, 5, 4, 6, 7, 5};
    vector<int>output=findmissingrepeat(arr);
    cout<<"the missing and repeating : "<<output[0]<<" "<<output[1]<<endl;
}