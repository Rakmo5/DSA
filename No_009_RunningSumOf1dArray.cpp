#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;

/*
 * Problem: Running Sum of 1D Array
 * Difficulty: Easy
 * Level: Level 1
 * Pattern: Prefix Sum
 * Why/Skill: Cumulative state
 * 
 * Problem Statement:
 * (Solve this on LeetCode: https://leetcode.com/problems/running-sum-of-1d-array/)
 * 
 * Hints:
 * - If you get stuck, ask me for a hint in the chat!
 */

class Solution {
public:
    vector<int> runningSum(vector<int>v){
        int sum = 0;
        for (auto it=v.begin();it!=v.end();it++){
            sum+=*it;
            *it=sum;
        }
        return v;
    }
    void printvector(vector<int>v){
        cout<<endl<<"{";
        for(auto it=v.begin();it!=v.end();it++){
            cout<<*it<<",";
        }
        cout<<"}"<<endl;
        return;
    }
};

int main() {
    cout << "Running No. 9: Running Sum of 1D Array..." << endl;
    Solution solver;
    // Add test cases here
    vector<int>v={1,2,3,4};
    v=solver.runningSum(v);
    solver.printvector(v);
    return 0;
}
