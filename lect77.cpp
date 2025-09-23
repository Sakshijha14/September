#include<iostream>
#include<vector>
using namespace std;

int maxproduct(vector<int>&nums){
    int n=nums.size();
    int output=INT_MIN;
    for(int i=0;i<n;i++){
        int product=nums[i];
        for(int j=i+1;j<n;j++){
            output=max(output,product);
            product*=nums[j];
        }
        output=max(output,product);
    }
    return output;

}

int main(){
    vector<int>nums={1,2,-3,0,-4,-5};
    cout<<maxproduct(nums);
    return 0;
}