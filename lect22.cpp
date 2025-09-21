#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

class Solution{

    public:
    int word(string str){

        int left=0,right=0;
        vector<int>mp(256,-1);
        int n=str.size();
        int maxlength=0;
        while(right<n){
            if(mp[str[right]]!=-1){
                left=max(left,mp[str[right]]+1);
            }
            mp[str[right]]=right;

            maxlength=max(maxlength,right-left+1);
            right++;
        }
        return maxlength;
    }
};

int main(){
    string str="takeuforward";
    Solution obj;
    cout<<"the length of longest substring without repeating charactrs is: "<<obj.word(str)<<endl;

    return 0;
}