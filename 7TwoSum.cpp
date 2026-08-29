// Given :
// An array and target , check if two elements in array adds upto target

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

vector<int> addToTarget(vector<int>&v, int &target){
    unordered_set<int> visited;
    // vector<int> visited;
    vector<int> output;
    for (int i=0;i<v.size();i++){
        int pair = target-v[i];
        if(visited.count(pair)){
            output.push_back(v[i]);
            output.push_back(pair);
            return output;
        }
        else{
            visited.insert(v[i]);
        }
    }
    if (output.empty()){
        cout<<endl<<"No pair found"<<endl;
    }
    return output;
    
}

int main(){
    vector<int>v1 = {3,2,4};
    int target1 = 6;
    vector<int>v = addToTarget(v1,target1);
    if(!v.empty()){
        cout<<endl;
        for (auto x :v){
            cout<<x<<",";
        }
    }
}