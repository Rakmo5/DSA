// https://leetcode.com/problems/contains-duplicate/description/
// Given : An array of integers
// Output : return true if any element is repeated in array 

#include<iostream>
#include<vector>
#include<unordered_set>
#include<algorithm>

using namespace std;

bool repeatCheck(vector<int>&v){
    unordered_set<int> check;
    for(auto x: v){
        if (check.count(x)){
            return true;
        }
        else{
            check.insert(x);
        }
    }
    return false;
}
bool repeatCheck2(vector<int>&v){
    sort(v.begin(),v.end());
    for(int i=0;i<v.size()-1;i++){
        if(v[i]==v[i=1]){
            return true;
        }
    }
    return false;
}


int main(){
    vector<int>v1={1,2,3,1};
    bool result = repeatCheck2(v1);
    if(result==1){
        cout<<endl<<"true"<<endl;
    }
    else{
        cout<<endl<<"false"<<endl;
    }
}