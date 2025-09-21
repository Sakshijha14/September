#include<iostream>
#include<vector>
using namespace std;

/*recursion
class Solution{
    public:

int uni(int i,int j,int m,int n){
    if(i==n-1 && j==m-1){
        return 1;
    }
    if(i>=n || j>=m){
        return 0;
    }
    return uni(i+1,j,m,n)+uni(i,j+1,m,n);
}
int unique(int m,int n){

return uni(0,0,m,n);
}
};*/

class Solution{
    public:

   /* int uni(int i,int j,int m,int n,vector<vector<int>>&dp){
    if(i==n-1 && j==m-1){
        return 1;
    }
    if(i>=n || j>=m){
        return 0;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    return dp[i][j]=uni(i+1,j,m,n,dp)+uni(i,j+1,m,n,dp);
}
int unique(int m,int n){
    vector<vector<int>> dp(n, vector<int>(m, -1));

return uni(0,0,m,n,dp);
}*/

int unique(int m,int n){
    long long output=1;
    int N=m+n-2;
    int r=min(m-1,n-1);

    for(int i=1;i<=r;i++){
        output=output*(N-r+i)/i;
    }

    return (int)output;
}

};
int main(){
    Solution obj;

    int totalsum=obj.unique(3,7);
    cout<<totalsum<<endl;
}