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
 * Problem: Best Time to Buy and Sell Stock
 * Difficulty: Easy
 * Level: Level 1
 * Pattern: Greedy / Running Minimum
 * Why/Skill: Maintain best previous state
 * 
 * Problem Statement:
 * (Solve this on LeetCode: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/)
 * 
 * Hints:
 * - If you get stuck, ask me for a hint in the chat!
 */

class Solution {
public:
    pair<int,int> bestTime(vector<int>prices){
        int buy =0;
        int sell =prices.size()-1;
        pair<int,int> p;
        for (int i=0;i<prices.size();i++){
            cout<<endl<<i<<endl;
            cout<<"buy"<<prices[buy]<<endl;
            cout<<"sell"<<prices[sell]<<endl;
            cout<<"current"<<prices[i]<<endl;
            if (prices[i]>prices[sell] && i<=buy){
                cout<<"sell :"<< prices[sell]<<" -> " <<prices[i];
                sell = i;
                
            }
            if (prices[i]<prices[buy] && i>=sell){
                cout<<"buy :"<< prices[buy]<<" -> "<< prices[i];
                buy = i;
            }
        }
        p.first=buy;
        p.second=sell;
        cout<<endl<< "Best days to buy is " <<buy<< "th day";
        cout<<endl<< "Best days to sell is " <<sell<< "th day";
        return p;
        
    }
    pair<int,int> bestTime2(vector<int>prices){
        
        int bestBuy=prices[0];
        int bestSell=0;
        int currentBuy=prices[0];

        for (auto it = prices.begin();it!=prices.end();it++){
            // cout<<endl<<"inside for";
            if((bestSell-bestBuy)< (*it-currentBuy)){
                bestSell=*it;
                bestBuy=currentBuy;
            }
            if (*it<currentBuy){
                currentBuy=*it;
            }
        }
        pair<int,int> p;
        p.first=bestBuy;
        cout<<endl<<"best buy: "<<p.first;
        p.second=bestSell;
        cout<<endl<<"best sell: "<<p.second;
        return p;
    }
};

int main() {
    cout << "Running No. 8: Best Time to Buy and Sell Stock..." << endl;
    Solution solver;
    // Add test cases here
    vector <int> v={7,1,5,3,6,4};
    solver.bestTime2(v);
    return 0;
}
