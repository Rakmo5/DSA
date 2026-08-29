#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
using namespace std;

// Input has 2 vectors or arrays
//  output is to return if there is a common element
auto commonElement(vector<string> &v1, vector<string> &v2)
{
    // vector<string> v4;
    bool found = false;
    unordered_set<string> s;
    for (auto str : v1)
    {
        s.insert(str);
    }

    for (auto _ : v2)
    {
        if (s.count(_)){
                cout << endl
                 << _;
                s.erase(_);
                found = true;
            }
    }
    if (!found)
    {
        cout<<"No common Elements!";
    }
}

int main()
{

    vector<string> v1 = {"a", "b", "c"};
    vector<string> v2 = {"d", "e", "f"};
    vector<string> v3 = {"x", "y", "a"};
    commonElement(v1,v2);
    commonElement(v1,v3);
}
