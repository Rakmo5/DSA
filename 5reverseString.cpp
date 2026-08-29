#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

string reverseString(string str){
    vector<char>v;
    for(char character: str){
        v.push_back(character);
    }
    // v.reserve(v.size());
    // cout<<"Reverse string: ";
    // for(int i = v.size()-1;i>=0;i--){
    //     cout<<v[i];
    // }
    reverse(v.begin(),v.end());
    string reversed_string(v.begin(),v.end());
    return reversed_string;

}

int main(){
    string hello = reverseString("hello");
    cout<<"Reversed String: "<<hello;
}