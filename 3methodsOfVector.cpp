#include <iostream>
#include <vector>

using namespace std;

/*
Operations of Vector

Method          | Time Complexity   | Why
-----------------------------------------------------------------
v.push_back()   | O(1) avg          | Appends at end
v.pop_back()    | O(1)              | Remove last element
v.empty()       | O(1)              | Just Check size == 0
v.size()        | O(1)              | Stored Internally
v.clear()       | O(n)              | Destroys all the elements
v.at()          | O(1)              | Direct Addressing
v.front()       | O(1)              | First element
v.back()        | O(1)              | Last Element

Vector maintain Capacity Doubles 2,4 add 5th element capacity becomes 8
Vector use Direct accessing
Pushing and poping in front of vector is disaster as it needs to shift 
all elements to right or left which has O(n)
Vector Adv:
    1. Fast insert
    2. Fast push_back
*/

void printVector(vector<int>&v){
    cout<<endl<<"Printing Vector :"<<endl;
    for(auto x : v){
        cout<<x<<",";
    }
    cout<<endl;
}

int main(){
    // Creating an simple array
    int array1[5] = {1,2,3,4,5};
    // Accessing a simple array
    for (auto x: array1){
        cout<<endl<<x;
    }
    
    // Dynamic Array : Vector
    vector<int> v = {1,2,3,4,5};
    cout<<endl<<"Size of the vector: "<<v.size();
    cout<<endl<<"Is v empty: "<<v.empty();
    v.push_back(6);
    printVector(v);
    v.pop_back();
    printVector(v);
    cout<<"Size of vector: "<<v.size()<<endl;
    cout<<"Last Element in : "<<v.back();
}

