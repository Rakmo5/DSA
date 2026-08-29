// https://leetcode.com/problems/move-zeroes/description/
// Given : An array containing '0' move them at end

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void printVector(vector<int>&v){
    cout<<endl<<"Printing Vector :"<<endl;
    for(auto x : v){
        cout<<x<<",";
    }
    cout<<endl;
}


vector<int>moveZeros1(vector<int>&v){
    for(int i=0;i<v.size();i++){
        if(v[i]==0){
            v.erase(v.begin()+i);
            v.push_back(0);
        }
    }
    return v;
}

vector<int>moveZeros2(vector<int>&v){
    int firstZeroIndex=0;
    int step_counter=0;
    for(int i=0;i<v.size();i++){
        if (v[i]==0){
            firstZeroIndex = i;
            break;
        }
    }
    for(int i=firstZeroIndex+1;i<v.size();i++){
        step_counter++;
        string ptr_space(firstZeroIndex*2,'.');
        cout<<endl<<"Step "<<step_counter<<":";
        printVector(v);
        cout<<ptr_space<<"^"<<endl;
        if(v[i]!=0){
            v[firstZeroIndex]=v[i];
            v[i]=0;
            firstZeroIndex++;
        }
    }
    return v;
}

int main(){
vector<int>v1={0,1,0,3,12};
// remove(v1.begin(),v1.end(),0);

v1=moveZeros2(v1);
printVector(v1);
}