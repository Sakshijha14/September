#include<iostream>
#include<vector>
using namespace std;

/*brute
int inversion(vector<int>&arr){

    int output=0;
    for(int i=0;i<arr.size();i++){
        for(int j=i+1;j<arr.size();j++){
            if(arr[i]>arr[j]){
                output++;
            }
        }
    }
    return output;
}
*/

int inversion(vector<int>&arr){
    
}

int main(){

    vector<int>arr={5, 4, 3, 2, 1};
    int n=arr.size();
    cout<<"the pairs generted are: "<<inversion(arr)<<endl;
}