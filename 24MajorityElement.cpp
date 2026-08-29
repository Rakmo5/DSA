// Input:  [2, 2, 1, 1, 1, 2, 2]

// Output: 2
#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>

using namespace std;

int majority(vector<int>v){
    // Map
    unordered_map<int,int> dictionary;
    for(int i =0;i<v.size();i++){
        dictionary[v[i]]++;
    }
    for (auto it=dictionary.begin();it!=dictionary.end();it++){
        if (it->second>v.size()/2){
            cout<<endl<<it->first<<" is the majority number"<<endl;
            return it->first;
        }
    }
}
int majority2(vector<int>v){
    
    sort(v.begin(),v.end());
    pair<int,int> p={v[0],1};
    for (auto it=v.begin()+1;it!=v.end();it++){
        if (p.first==*it){
            p.second++;
        }
        if (p.first!=*it){
            if (p.second>v.size()/2){
                cout<<endl<<*it<<" is the majority number"<<endl;
                return p.first;
            }
            p.first=*it;
            p.second=1;
        }

    }
    if (p.second > v.size() / 2) {
        cout<<endl<<p.first<<" is the majority number"<<endl;
        return p.first;
    }
    cout<<endl<<"No majority element";
    return -1;
    // check 
}
int majority3(vector<int>v){
    int count=0;
    int candidate=v[0];
    for (int i=0;i<v.size();i++){
        
        if (v[i]!=candidate ){
            if (count==0){
                candidate=v[i+1];
                count=0;
            }
        }
        else{
            count++;
        } 
    }
    if (count >0){
        cout<<endl<< candidate <<" is majoity element."<<endl;
        return candidate;
    }
    else{
        cout<<endl <<"No number is majoity element."<<endl;
        return -1;
    }
}

int main(){
    vector<int> v = {2, 2, 1, 1, 1, 2, 2,2};
    majority3(v);
}

// 1,1,1,2,2,2,2
// counter = 3 ;
// 3/2 -> n
// 2