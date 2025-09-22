#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct meeting{
    int start;
    int end;
    int position;
};

class Solution{
    public:
    bool static comparartor(struct meeting m1,meeting m2){
        if(m1.end<m2.end){
            return true;
        }
        else if(m1.end>m2.end){
            return false;
        }
        else if(m1.position<m2.position){
            return true;
        }
        return false;
    }

    void maxmeeting(int s[],int e[],int n){
        struct meeting meet[n];

        for(int i=0;i<n;i++){
            meet[i].start=s[i];
            meet[i].end=e[i];
            meet[i].position=i+1;
        }
        sort(meet,meet+n,comparartor);
        vector<int>output;

        int limit=meet[0].end;
        output.push_back(meet[0].position);

        for(int i=1;i<n;i++){
            if(meet[i].start>limit){
                output.push_back(meet[i].position);
                limit=meet[i].end;
            }
        }
        cout<<"number of meeting: "<<endl;
        for(int i=0;i<output.size();i++){
            cout<<output[i]<<" ";
        }
    }
};

int main(){
    Solution obj;
    int n=6;
    int start[]={1,3,0,5,8,5};
    int end[]={2,4,5,7,9,9};
    obj.maxmeeting(start,end,n);

    return 0;
}