#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*better
vector<vector<int>>merge(vector<vector<int>>&arr){

    int n=arr.size();

    sort(arr.begin(),arr.end());

    vector<vector<int>>output;
    for(int i=0;i<n;i++){
        int start=arr[i][0];
        int end=arr[i][1];
        if(!output.empty() && end<=output.back()[1]){
            continue;
        }
        for(int j=i+1;j<n;j++){
            if(arr[j][0]<=end){
                end=max(end,arr[j][1]);
            }
            else{
                break;
            }
            
        }
        output.push_back({start,end});
       

    }
     return output;
}
*/

vector<vector<int>>merge(vector<vector<int>>&arr){
    int n=arr.size();
    sort(arr.begin(),arr.end());
    vector<vector<int>>output;
    for(int i=0;i<n;i++){
        if(output.empty() || arr[i][0]>output.back()[1]){
            output.push_back(arr[i]);
        }
        else{
            output.back()[1]=max(output.back()[1],arr[i][1]);
        }
    }
    return output;
}


int main(){
    vector<vector<int>>arr={{1,3},{8,10},{2,6},{15,18}};
    vector<vector<int>>output=merge(arr);
    cout<<"the merge intervals is: "<<endl;
    for (auto it : output) {
        cout << "[" << it[0] << ", " << it[1] << "] ";
    }
        cout<<endl;
    
}