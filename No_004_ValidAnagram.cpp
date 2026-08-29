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
 * Problem: Valid Anagram
 * Difficulty: Easy
 * Level: Level 1
 * Pattern: Frequency Counting
 * Why/Skill: Frequency map
 * 
 * Problem Statement:
 * (Solve this on LeetCode: https://leetcode.com/problems/valid-anagram/)
 * 
 * Hints:
 * - If you get stuck, ask me for a hint in the chat!
 */

class Solution {
public:
    int anagram(string s, string t){
        if (s.size()!=t.size()){
            cout<<endl<<"Not anagram"<<endl;
            return 0;
        }
        unordered_map<char,int> candi_count1;
        unordered_map<char,int>candi_count2;
        for (int i=0;i<s.size();i++){
            candi_count1[s[i]]++;
            candi_count2[t[i]]++;
        }
        for (auto it = candi_count1.begin();it!=candi_count1.end();it++){
            if (it->second!=candi_count2[it->first]){
                cout<<endl<<"Not anagram"<<endl;
                return 0;
            }
        }
        cout<<endl<< "Anagram"<<endl;
    }
    int anagram2(string s, string t){
        if (s.size()!=t.size()){
            cout<<endl<<"Not anagram"<<endl;
            return 0;
        }
        unordered_map<char,int> candi_count1;
        // unordered_map<char,int>candi_count2;
        for (int i=0;i<s.size();i++){
            candi_count1[s[i]]++;
        }
        for (int i=0;i<t.size();i++){
            candi_count1[t[i]]--;
        }
        for (auto it=candi_count1.begin();it!=candi_count1.end();it++){
            if (it->second!=0){
                cout<<endl<<"Not anagram"<<endl;
            return 0;
            }
        }
    
        cout<<endl<< "Anagram"<<endl;
        return 1;
    }
    int anagram3(string s, string t){
        if (s.size()!=t.size()){
            cout<<endl<<"Not anagram"<<endl;
            return 0;
        }
        vector<int>alpha(26);
        for (auto it=s.begin();it!=s.end();it++){
            alpha[(*it)-'a']++;
        }
        for (auto it=t.begin();it!=t.end();it++){
            alpha[(*it)-'a']--;
        }
        for (auto it =alpha.begin();it!=alpha.end();it++){
            if ((*it)!=0){
                cout<<endl<<"Not anagram"<<endl;
                return 0;
            }
        }
        cout<<endl<< "Anagram"<<endl;
        return 1;


    }
};

int main() {
    cout << "Running No. 4: Valid Anagram..." << endl;
    Solution solver;
    solver.anagram3("listen","silent");
    solver.anagram3("shut","hut");
    return 0;

}
