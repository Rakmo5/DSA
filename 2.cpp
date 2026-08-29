// Given : The array of integers ,and target value
        // array is unordered
// Required : To check if 2 elements add to target

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;
// O(n^2) approch
auto checkTargetSum1(vector<int> &v,int target){
    bool flag=false;
    for(int i=0;i<v.size();i++){
        for (int j=i+1;j<v.size();j++){
            if (v[i]+v[j]==target){
                cout<<endl<<"Match found:"<<v[i] <<"+"<<v[j]<<"="<<target;
                flag=true;
                return;
            }
        }
    }
    if(!flag){
        cout<<"No Match found";
        return;
    }
}
auto checkTargetSum2(vector<int> &v,int target){
    bool flag=false;
    int left=0;
    int right=v.size()-1;
    while(left<right){
        int result=v[left]+v[right];
        if(result==target){
            cout<<endl<<"Match Found: "<<v[left]<<"+"<<v[right]<<"="<<target;
            flag=true;
            return;
        }
        else if(result>target){
            right=right-1;
            continue;
        }
        else{
            left=left+1;
            continue;
        }
    }
}

auto CheckSumTarget3(vector<int> &v,int target){
    unordered_set<int> s;
    for(auto num :v){
        int needed=target-num;
        if(s.count(needed)){
            cout<<endl<<"Match Found:"<<num<<"+"<<needed<<"="<<target;
            return;
        }
        s.insert(num);
    }
    cout<<endl<<"No match Found";
}

int main(){
    vector<int>v1={1,2,3,4,5};
    vector<int>v2={3,2,1,4,5};
    auto target = 8;
    // checkTargetSum1(v1,target);
    // checkTargetSum2(v1,target);
    CheckSumTarget3(v2,target);
}
