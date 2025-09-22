#include<iostream>
#include<vector>

using namespace std;

int main(){
    int V=49;
    vector<int>output;
    
    int coins[]={1,2,5,10,20,50,100,500,1000};
    int n=9;
    for(int i=n-1;i>=0;i--){
        while(V>=coins[i]){
            V-=coins[i];
            output.push_back(coins[i]);
        }
    }
    cout<<"the minimum coins is: "<<output.size()<<endl;
    cout<<"the coins is: "<<endl;
    for(int i=0;i<output.size();i++){
        cout<<output[i]<<" ";
    }

    return 0;
}