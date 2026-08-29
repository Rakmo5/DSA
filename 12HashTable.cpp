// Hash Table , Insertion, deletion, lookup and access : O(1)


/*
        Array   vs   Hash table
search  O(n)            O(1)
lookup  O(1)            O(1)
push    O(1)            -
Insert  O(n)            O(1)
delete  O(n)            O(1)


fast look up ,insert and flexible keys
unordered nature and slow key iteration
need good collision resolution 
*/


#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void printVector(vector<string>&v){
    cout<<endl<<"Printing Vector :"<<endl;
    for(auto x : v){
        cout<<x<<",";
    }
    cout<<endl;
}

class HashTable{
    private:
    int hashTableLength=5;

    vector<vector<pair<string,int>>> Table;

    int hashFunction(string s){
        int index = 0;
        for (int i=0;i<s.length();i++){
            int x=s[i];
            index+=x;
        }
        return index%hashTableLength;
    }
    public: 
    HashTable(int size){
        // Sets the size of hashtable
        hashTableLength=size;
        Table.resize(size);
    }
    void set(string key, int value){
        int index = hashFunction(key);
        pair<string,int> p = {key,value};
        Table[index].push_back(p);
        cout<<endl<<"Key: "<<key<<", value: "<<value<<" inserted successfully";
    }
    int get(string key){
        int index = hashFunction(key);
        vector<pair<string,int>> &bucket = Table[index];
        for(int i=0;i<bucket.size();i++){
            if (bucket[i].first == key){
                return bucket[i].second;
            }
        }
        throw "Key not found";
    }
    vector<string> keys(){
        vector<string> keys;
        for (int i=0;i<hashTableLength;i++){
        vector<pair<string,int>> & bucket  = Table[i];
            for(int j=0;j<bucket.size();j++){
                keys.push_back(bucket[j].first);
            }
        }
        return keys;
    }
};

int main(){
    HashTable mytable(5);
    mytable.set("apple",10);
    mytable.set("banana",20);
    int no_banana;
    try{
        no_banana=mytable.get("orange");
    }
    catch(const char* msg){
        cout<<msg;
    }
    cout<<endl<<"Number of banana = "<<no_banana<<endl;
    vector<string> key;
    key=mytable.keys();
    printVector(key);
}