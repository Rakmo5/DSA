// Given : 2 sorted arrays 
// Output : one sigle sorted array combining both

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void printVector(vector<int>&v){
    cout<<endl<<"Printing Vector :"<<endl;
    for(auto x : v){
        cout<<x<<",";
    }
    cout<<endl;
}

vector<int> combineVector1(vector<int> &v1,vector<int> &v2){
    vector<int>v;
    v.insert(v.end(),v1.begin(),v1.end());
    v.insert(v.end(),v2.begin(),v2.end());
    sort(v.begin(),v.end());
    cout<<"Merged Vector: ";
    printVector(v);
    return v;
}

vector<int> combineVector2(vector<int>&v1,vector<int>&v2){
    if(v1.empty()){
        printVector(v2);
        return v2;
    }

    if(v2.empty()){
        printVector(v1);
        return v1;
    }

    
    int i = 0;
    int j = 0;
    vector<int>v;
    v.reserve(v1.size()+v2.size());
    while(i<v1.size() && j<v2.size()){
        if(v1[i]<v2[j]){
            v.push_back(v1[i]);
            i++;
        }
        else{
            v.push_back(v2[j]);
            j++;
        }
    }
    if(i<v1.size()){
        while(i<v1.size()){
            v.push_back(v1[i]);
            i++;
        }
    }
    if(j<v2.size()){
        while(j<v2.size()){
            v.push_back(v2[j]);
            j++;
        }
    }
    printVector(v);
    return v;
}

vector<int> combineVector3(vector<int>&v1,vector<int>&v2){
    vector<int>v;
    merge(v1.begin(),v1.end(),
    v2.begin(),v2.end(),
    back_inserter(v));
    printVector(v);
    return v;
}


int main(){
    vector<int> v1 = {1,3,4,5};
    vector<int> v2 = {2,4,6};
    // combineVector1(v1,v2);
    combineVector2(v1,v2);
    combineVector3(v1,v2);
}