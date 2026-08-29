// Given : An array/vector of strings like [["abc","dba","c"]
// Output : Return if the string can form palindrom , even if it needs to change the order

#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

bool palindromCheck(vector<string>&v){
    unordered_map<char,int> charCount;
    int counter = 0;
    for(int i =0;i<v.size();i++){
        string s = v[i];
        for (int j=0;j<s.size();j++){
            charCount[s[j]]++;
        }
    }
    for (auto x:charCount){
        if(x.second % 2!=0){
            counter++;
        }
    }
    if (counter>1){
        cout<<endl<<"We cannot form palindrom"<<endl;
        return false;
    }
    else{
        cout<<endl<<"We can form palindrom"<<endl;
        return true;
    }
}

int main(){
    vector<string>v={"abc","dba","c"};
    palindromCheck(v);
}