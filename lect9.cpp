#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

/*brute
int findduplicates(vector<int>&arr){
    int n=arr.size();
    sort(arr.begin(),arr.end());
    for(int i=0;i<n;i++){
        if(arr[i]==arr[i+1]){
            return arr[i];
        }
    }

    return -1;
}
*/

/*better
int findduplicates(vector<int>&arr){
    int n=arr.size();
    map<int,int>mp;

    for(int i=0;i<n;i++){
        mp[arr[i]]++;

        if(mp[arr[i]]>1){
            return arr[i];
        }
    }
    return -1;
}
*/

int findduplicates(vector<int>&arr){
    int slow=arr[0];
    int fast=arr[0];

    do{
        slow=arr[slow];
        fast=arr[arr[fast]];
    }while(slow!=fast);

    slow=arr[0];
    while(slow!=fast){
        slow=arr[slow];
        fast=arr[fast];
    }

    return slow;

}

int main(){
    vector<int>arr={1,3,4,2,2};
    cout<<"the duplicate element is: "<<findduplicates(arr)<<endl;
}