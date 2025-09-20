#include<iostream>
#include<climits>
#include<vector>

using namespace std;

/*better
void sortarray(vector<int>&arr){
    int n=arr.size();
    int count0=0;
    int count1=0;
    int count2=0;

    for(int i=0;i<arr.size();i++){
        if(arr[i]==0){
            count0++;
        }
        else if(arr[i]==1){
            count1++;
        }
        else{
            count2++;
        }
    }

    for(int i=0;i<count0;i++){
        arr[i]=0;
    }
    for(int i=count0;i<count0+count1;i++){
        arr[i]=1;
    }
    for(int i=count0+count1;i<n;i++){
        arr[i]=2;
    }
}*/

void sortarray(vector<int>&arr){
    int n=arr.size();
    int l=0,mid=0,h=n-1;

    for(int i=0;i<n;i++){

        if(arr[mid]==0){
            swap(arr[l],arr[mid]);
            l++;
            mid++;
        }
        else if(arr[mid]==1){
            mid++;
        }
        else{
            swap(arr[mid],arr[h]);
            h--;
        }
    }
}

int main(){

    vector<int>arr={0,2,1,2,0,1};
    int n=arr.size();
    sortarray(arr);
    cout<<"the sorted array is: "<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    return 0;
}