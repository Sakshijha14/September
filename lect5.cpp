#include<iostream>
#include<vector>

using namespace std;

int maxp(vector<int>&arr){

    int n=arr.size();
    int miniprice=arr[0];
    int maxi=0;
    for(int i=1;i<n;i++){
        miniprice=min(miniprice,arr[i]);

        maxi=max(maxi,arr[i]-miniprice);
    }

    return maxi;
}

int main(){

    vector<int>arr={7,1,5,3,6,4};
    int maxprofit=maxp(arr);
    cout<<"the maxprofit is: "<<maxprofit<<endl;
}