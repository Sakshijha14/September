#include<iostream>
#include<vector>

#include<map>
using namespace std;

vector<int>majority(vector<int>&arr){
    int n=arr.size();
    vector<int>input;
    int mini=int(n/3)+1;
    map<int,int>mp;

    for(int i=0;i<n;i++){
        mp[arr[i]]++;

        if(mp[arr[i]]==mini){
            input.push_back(arr[i]);

        }
        if(input.size()==2)
        break;
    }
    return input;
}

int main(){
    vector<int>arr={11,33,33,11,33,11};
    vector<int>output=majority(arr);

    cout<<"the majority is: ";
    for(auto it:output){
        cout<<it<<" ";
    }
    cout<<endl;

    return 0;
}