#include<iostream>
#include<vector>
#include<set>
#include<vector>
#include<algorithm>
using namespace std;

vector<vector<int>>four(vector<int>&arr,int target){
    int n=arr.size();
    set<vector<int>>st;

    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            set<long long>seen;
            for(int k=j+1;k<n;k++){
                long long sum=arr[i]+arr[j];
                sum+=arr[k];
                long long lastneed=target-sum;
                if(seen.find(lastneed)!=seen.end()){
                    vector<int>nums={arr[i],arr[j],arr[k],(int)lastneed};
                    sort(nums.begin(),nums.end());
                    st.insert(nums);
                }
                seen.insert(arr[k]);
            }
        }
    }
    vector<vector<int>>output(st.begin(),st.end());
    return output;
}

int main(){
    vector<int>arr={4,3,3,4,4,2,1,2,1,1};
    int target=9;
    vector<vector<int>>output=four(arr,target);
    cout<<"the quadrant are: ";
    for(auto it:output){
        cout<<"[";
        for(auto element:it){
            cout<<element<<" ";
        }
        cout<<"]";
    }
    cout<<endl;
}