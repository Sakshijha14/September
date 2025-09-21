#include<iostream>
#include<vector>
#include<set>
using namespace std;

/*brute
int linearsearch(vector<int>&arr,int next){
    int n=arr.size();
    for(int i=0;i<n;i++){
        if(arr[i]==next){
            return 1;
        }
    }
    return 0;
    
}

int longestsequence(vector<int>&arr){

    int n=arr.size();
    int longest=1;

    for(int i=0;i<n;i++){
        int element=arr[i];
        int count=1;

        while(linearsearch(arr,element+1)==true){
            count++;
            element++;
        }
        longest=max(longest,count);
    }

    return longest;
}*/

int longestsequence(vector<int>&arr){

    int n=arr.size();
    if(n==0){
        return 0;
    }
    int longest=1;
    set<int>st;
    for(int i=0;i<n;i++){
        st.insert(arr[i]);
    }
    for(auto it:st){
        int count=1;
        int element=it;
        while(st.find(element+1)!=st.end()){
            count++;
            element++;
        }
        longest=max(longest,count);
    }
    return longest;

}

int main(){
    vector<int>arr={100,200,1,2,3,4};
    int output=longestsequence(arr);
    cout<<"the longest sequences is: "<<output<<endl;
}