#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution{

    public:
    vector<vector<string>>partition(string s){
        vector<vector<string>>output;
        vector<string>path;
        funt(0,s,path,output);
        return output;
    }

    void funt(int index,string s,vector<string>&path,vector<vector<string>>&output){
        if(index==s.size()){
            output.push_back(path);
            return;
        }
        for(int i=index;i<s.size();i++){
            if(ispalindr(s,index,i)){
                path.push_back(s.substr(index,i-index+1));
                funt(i+1,s,path,output);
                path.pop_back();
            }
        }
    }
    bool ispalindr(string s,int start,int end){
        while(start<=end){
            if(s[start++]!=s[end--]){
                return false;
            }
            return true;
        }
    }

};

int main(){
    string s="aabb";
    Solution obj;
    vector<vector<string>>output=obj.partition(s);
    int n=output.size();
    cout<<"the palindrome partition are: "<<endl;
    cout<<"[";
    for(auto i: output){
        cout<<"[";
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<"]";
    }
    cout<<"]";

    return 0;
}