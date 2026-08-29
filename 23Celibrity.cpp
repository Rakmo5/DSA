#include<iostream>
#include<vector>

using namespace std;

int celebrity(vector<vector<int>>people){
    if (people.size()<=1){
        return 0;
    }
    
    vector<int>candidates;
    for(int i=0;i<people[1].size();i++){
        if (people[1][i]==1){
            candidates.push_back(i);
        }
    }
    for (int i=0;i<candidates.size();i++){
        int counter=0;
        for (int j=0;j<people[1].size();j++){
            
            if (people[candidates[i]][j]==1){
                counter++;
            }
        }
        if (counter==0){
            cout<<endl<<"Celebrity exist"<<endl;
            return 1;
        }
        
    }
    return -1;
}

int celebrity2(vector<vector<int>>people){
    if (people.size()<=1){
        return 0;
    }
    vector<int>eliminator;
    for (int i = 0 ; i<people.size();i++){
        eliminator.push_back(i);
    }
    
    // for (int p=0;p<people.size();p++){
    //     // If i knows j , eliminate i
    //     if(people[i][j]==1){
            
    //     }
    // }
    while (eliminator.size()>1){
        int i=eliminator.size()-2;
        int j=eliminator.size()-1;
        if(people[eliminator[i]][eliminator[j]]==0){
            // i dont know j
            eliminator.erase(eliminator.end()-1);
            
        }
        else{
            eliminator.erase(eliminator.end()-2);
        }
    }
    for (int x=0;x<people[eliminator[0]].size();x++){

        if (people[eliminator[0]][x]==1){
            cout<<endl<<"No celebrity exist";
            return -1;
        }
    }
    cout<<"celebrity exist at "<<eliminator[0]<<"position";
    return 1;

}


int main(){
    vector<vector<int>> people = {{0,1,1,0},{1,0,1,0},{0,0,0,0},{1,0,0,0}};
    celebrity2(people);
}

// [0,1,1,0],[1,0,1,0],[0,0,0,0],[1,0,0,0]
// 0 is candidate , he knows 1 and 2 , eliminate 0 and 3, then check 1 and 2 