#include<iostream>
#include<vector>
using namespace std;
/*
brute
void markrow(vector<vector<int>>&arr,int n,int m,int row){
    for(int i=0;i<m;i++){
        if(arr[row][i]!=0){
            arr[row][i]=-1;
        }
    }
}

void markcol(vector<vector<int>>&arr,int n,int m,int col){
    for(int j=0;j<n;j++){
        if(arr[j][col]!=0){
            arr[j][col]=-1;
        }

    }
}
vector<vector<int>>zero(vector<vector<int>>&arr,int n,int m){
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j]==0){
                markrow(arr,n,m,i);
                markcol(arr,n,m,j);
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j]==-1){
                arr[i][j]=0;
            }
        }
    }
    return arr;

    o(n*m)*(m+n)+o(n*m)
}*/

/*better
vector<vector<int>>zero(vector<vector<int>>&arr,int n,int m){
    vector<int>row(n,0);
    vector<int>col(m,0);
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j]==0){
                row[i]=1;
                col[j]=1;
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j]==1 && row[i]==1 || col[j]==1){
                arr[i][j]=0;
            }
        }
    }
    return arr;

}
    o(n*m)+o(n*m)
    o(n)+o(m)
*/

vector<vector<int>>zero(vector<vector<int>>&arr,int n,int m){
    int col=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j]==0){
                arr[i][0]=0;
                if(j!=0){
                    arr[0][j]=0;
                }
                else{
                    col=0;
                }
            }
        }
    }

    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            if(arr[i][j]!=0 && arr[i][0]==0 ||arr[0][j]==0){
                arr[i][j]=0;
            }
        }
    }
    if(arr[0][0]==0){
        for(int j=0;j<m;j++){
            arr[0][j]=0;
        }
    }
    if(col==0){
        for(int i=0;i<n;i++){
            arr[i][0]=0;
        }
    }
    return arr;
    //o(n*m)
    //o(1)
}



int main(){

    vector<vector<int>>arr={{1,1,1,1},{1,0,0,1},{1,1,0,1},{1,1,1,1}};
    int n=arr.size();
    int m=arr[0].size();
    vector<vector<int>>output=zero(arr,n,m);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<output[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
    

}