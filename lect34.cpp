#include<iostream>
#include<algorithm>
using namespace std;

/*brute
int countplat(int n,int arr[],int dep[]){
    int output=1;
    for(int i=1;i<n;i++){
        int count=1;
        for(int j=i+1;j<n;j++){
            if((arr[i]>=arr[j]) && (arr[i]<=dep[j])||(arr[j]>=arr[i] && arr[j]<=dep[i])){
                count++;
            }
        }
        output=max(output,count);
    }
    return output;
}
*/

int countplat(int n,int arr[],int dep[]){
    sort(arr,arr+n);
    sort(dep,dep+n);

    int output=1;
    int count=1;
    int i=1;
    int j=0;
    while(i<n && j<n){
        if(arr[i]<=dep[j]){
            count++;
            i++;
        }
        else{
            count--;
            j++;
        }
        output=max(output,count);
    }
    return output;
}

int main(){
    int arr[]={900,945,955,1100,1500,1800};
    int dep[]={920,1200,1130,1150,1900,2000};
    int n=sizeof(dep)/sizeof(dep[0]);
    cout<<"minimum number of platform required"<<countplat(n,arr,dep)<<endl;
}