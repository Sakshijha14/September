#include<iostream>
#include<algorithm>
using namespace std;

struct item{
    int value;
    int weight;
};

class Solution{
    public:

    bool static comparator(item a,item b){
        double r1=(double)a.value/(double)a.weight;
        double r2=(double)b.value/(double)b.weight;
        return r1>r2;
    }
    double fractional(int W,item arr[],int n){
        sort(arr,arr+n,comparator);
        int noweight=0;
        double final=0.0;

        for(int i=0;i<n;i++){
            if(noweight+arr[i].weight<=W){
                noweight+=arr[i].weight;
                final+=arr[i].value;
            }
            else{
                int subst=W-noweight;
                final+=(arr[i].value/(double)arr[i].weight)*(double)subst;
                break;
            }
        }
        return final;
    }
};

int main(){
    int n=3;
    int weight=50;
    item arr[n]={{100,20},{60,10},{120,30}};
    Solution obj;
    double output=obj.fractional(weight,arr,n);
    cout<<"the maximum is: "<<output<<endl;

}