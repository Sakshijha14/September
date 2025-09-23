#include<iostream>
#include<queue>
#include<vector>
using namespace std;

void bfs(vector<vector<char>>&grid,vector<vector<bool>>&visited,int row,int col){
    int n=grid.size();
    int m=grid[0].size();
    queue<pair<int,int>>q;
    q.push({row,col});
    visited[row][col]=true;
    
    int dr[]={-1,1,0,0};
    int dc[]={0,0,1,-1};
    while(!q.empty()){
        auto [r,c]=q.front();
        q.pop();

        for(int i=0;i<4;i++){
            int newr=r+dr[i];
            int newc=c+dc[i];

            if(newr>=0 && newr<n && newc>=0 && newc<m && grid[newr][newc]=='1' && !visited[newr][newc]){
                q.push({newr,newc});
                visited[newr][newc]=true;

            }

        }

    }
    
}

int numisland(vector<vector<char>>&grid){

    if(grid.empty())
    return 0;
    int n=grid.size();
    int m=grid[0].size();
    vector<vector<bool>>visited(n,vector<bool>(m,false));
    int islandcount=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]=='1' && !visited[i][j]){
                islandcount++;
                bfs(grid,visited,i,j);
            }
        }
    }
    return islandcount;

}
int main(){

    vector<vector<char>> grid{
        {'1', '1', '0', '1', '1'},
        {'1', '0', '0', '0', '0'},
        {'0', '0', '0', '0', '1'},
        {'1', '1', '0', '1', '1'}};

    int output=numisland(grid);
    cout<<output;
}