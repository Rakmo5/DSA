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
 * Problem: Two Sum II - Input Array Is Sorted
 * Difficulty: Medium
 * Level: Level 1
 * Pattern: Two Pointers
 * Why/Skill: Sorted two-pointer elimination
 * 
 * Problem Statement:
 * (Solve this on LeetCode: https://leetcode.com/problems/two-sum-ii---input-array-is-sorted/)
 * 
 * Hints:
 * - If you get stuck, ask me for a hint in the chat!
 */

class Solution {
public:
    pair<int,int> two_sum(vector<int>v,int target){
        pair<int,int> p;
        int *start_pointer=&v[0];
        int *end_pointer=&v[v.size()-1];
        while (start_pointer!=end_pointer){
            if(*start_pointer+*end_pointer==target){
                p.first=*start_pointer;
                p.second=*end_pointer;
                return p;
            }
            else if(*start_pointer+*end_pointer>target){
                end_pointer--;
            }
            else{
                start_pointer++;
            }
        }

    }
    pair<int,int> two_sum_index(vector<int>v,int target){
        pair<int,int> p;
        int start=0;
        int end = v.size()-1;
        while (start!=end){
            if(v[start]+v[end]==target){
                p.first=++start;
                p.second=++end;
                return p;
            }
            else if(v[start]+v[end]>target){
                end--;
            }
            else{
                start++;
            }
        }

    }
};

int main() {
    cout << "Running No. 7: Two Sum II - Input Array Is Sorted..." << endl;
    Solution solver;

    // Add test cases here
    pair<int,int>p;
    vector<int>v = {2, 7, 11, 15};
    p=solver.two_sum_index(v,9);
    cout<<endl<<p.first<<" & "<<p.second;
    return 0;
}
