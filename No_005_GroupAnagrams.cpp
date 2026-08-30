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
 * Problem: Group Anagrams
 * Difficulty: Medium
 * Level: Level 1
 * Pattern: Hashing / Canonical Form
 * Why/Skill: Normalize + hash
 * 
 * Problem Statement:
 * (Solve this on LeetCode: https://leetcode.com/problems/group-anagrams/)
 * 
 * Hints:
 * - If you get stuck, ask me for a hint in the chat!
 */

class Solution {

public:
    int anagram(string s,string t){
        vector<int> v(26);
        for (auto it = s.begin();it!=s.end();it++){
            v[(*it)-'a']++;
        }
        for (auto it = t.begin();it!=t.end();it++){
            v[(*it)-'a']--;
        }
        for (auto it =v.begin();it!=v.end();it++){
            if(*it!=0){
                return false;
            }
        }
        return true;
    }
    vector<vector<string>> anagram_list(vector<string>v){
        vector<vector<string>> output;
        vector<bool>visited(v.size(),false) ;
        for (int i=0;i<v.size();i++){
            string candidate = v[i];
            vector<string>array;
            if (visited[i]==false){
                array.push_back(v[i]);
                for (int j=i+1;j<v.size();j++){
                    if (visited[j]==true){
                        continue; // skip this loop
                    }
                    if (anagram(v[i],v[j])){
                        array.push_back(v[j]);
                        visited[j]=true;
                    }
                }
                output.push_back(array);
            }
        }
        return output;
    }
    unordered_map<string,vector<string>> anagram_list2(vector<string>v){
        unordered_map<string,vector<string>>output;
        for (auto it =v.begin();it!=v.end();it++){
            string temp =*it;
            sort(temp.begin(),temp.end());
            output[temp].push_back(*it);
        }
        return output;
    }

    // void print1(vector<vector<string>>v){
    //     for(int i=0;i<v.size();i++){
    //         cout<<endl<<"{";
    //         for (int j=0;j<v[i].size();j++){
    //             cout<<v[i][j]<<",";
    //         }
    //         cout<<"},"<<endl;
    //     }
    //     return;
    // }
    void print2(unordered_map<string,vector<string>> map1){
        for (auto it = map1.begin();it!=map1.end();it++){
            cout<<endl<<"{";
            for (auto it2=it->second.begin();it2!=it->second.end();it2++){
                cout<<*it2<<",";

            }
            cout<<"},"<<endl;
        }
        return;
    }
};

int main() {
    cout << "Running No. 5: Group Anagrams..." << endl;
    Solution solver;
    // Add test cases here
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    // vector<vector<string>> v;
    unordered_map<string,vector<string>> v;
    v = solver.anagram_list2(strs);
    solver.print2(v);
    return 0;
}
