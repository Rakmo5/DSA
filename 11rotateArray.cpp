// https://leetcode.com/problems/rotate-array/description/

// Given : Integer array & K , rotate it by K positions , rotate towards right ->

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

vector<int>rotateArray(vector<int>&v,int k){
    vector<int>v_temp;
    if (v.empty()){
        return v;
    }
    if (k==0){
        return v;
    }

    k=k%v.size();
    // int counter=0;
    for(int i=v.size()-k;i<v.size();i++){
        v_temp.push_back(v[i]);
    }
    printVector(v_temp);

    for(int i=v.size()-1;i>=k;i--){
        v[i]=v[i-k];
    }
    for(int i=0;i<v_temp.size();i++){
        v[i]=v_temp[i];
    }
    return v;
}

vector<int>rotateArray2(vector<int>&v,int k){
    reverse(v.begin(),v.end());
    cout<<"Entire Rotation: "<<endl;
    printVector(v);
    reverse(v.begin(),v.begin()+k);
    cout<<"Rotation of first k: "<<endl;
    printVector(v);
    reverse(v.begin()+k,v.end());
    cout<<"Final rotation: "<<endl;
    printVector(v);
    return v;
}

int main(){
    vector<int>v1={1,2,3,4,5,6};
    rotateArray2(v1,3);
    printVector(v1);
}

/*

1,2,3|,4,5,6,7,k=3
 A        B
3,2,1  7,6,5,4
 arev   brev
4,5,6,7,|1,2,3
3,2,1,7,6,5,4


*/