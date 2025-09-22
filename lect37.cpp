#include<iostream>
#include<vector>

#include<algorithm>
using namespace std;

class Solution{

    public:

    int children(vector<int>&student,vector<int>&cookie){
        sort(student.begin(),student.end());
        sort(cookie.begin(),cookie.end());

        int studentindex=0;
        int cookieindex=0;

        while(studentindex<student.size() && cookieindex<cookie.size()){
            if(cookie[cookieindex]>=student[studentindex]){
                studentindex++;
            }
            else{
                cookieindex++;
            }
        }
        return studentindex;
    }
};

int main(){
    vector<int>student={1,2,3};
    vector<int>cookie={1,1};

    Solution solve;

    int output=solve.children(student,cookie);
    cout<<"maximum number of student: "<<output<<endl;

    return 0;
}