#include<iostream>
#include<vector>
using namespace std;

struct meeting{
    int start;
    int end;
    int position;
};

class Solution{
    
    public:
    
    bool static comparator(struct meeting m1,meeting m2){
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

    void meeting(int start[],int end[],int n){
        
    }
};


int main(){

    Solution obj;
    int n=6;
    int start[]={1,3,0,5,8,5};
    int end[]={2,4,5,7,9,9};
    obj.meeting(start,end,n);

    return 0;

}