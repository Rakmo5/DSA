// Given an array = [2,5,1,2,3,5,1,2,4]:
// It should return 2

// Given an array = [2,1,1,2,3,5,1,2,4]:
// It should return 1

// Given an array = [2,3,4,5]:
// It should return undefined

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int firstRecure(vector<int> &v){
    unordered_set<int>visited;
    for (auto x:v){
        if (visited.count(x)){
            cout<<endl<<"First recurring digit: "<<x;
            return x;
        }
        else{
            visited.insert(x);
        }
    }
    throw "No recuring digits";
}

// This approch has many cons like we change original array, 
// and it dont work if element exced vector size
int firstRecure2(vector<int>&v){
    for(int i=0;i<v.size();i++){
        int index = abs(v[i]);
        if (v[index]<0){
            cout<<endl<<v[i]<<" is the first recurring number";
            return v[i];
        }
        else{
            v[index] = -v[index];
        }
    }
    throw "No recuring digits";
}

int main(){
    vector<int>v1={2,5,1,2,3,5,1,2,4};
    vector<int>v2={2,3,4,5};
    try{
        firstRecure2(v2);
    }
    catch(const char *msg){
        cout<<endl<<msg<<endl;
    }
}