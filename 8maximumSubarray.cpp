// Given : an array with integers , 
// output : sum of largest continuous postive elements

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxSubarray(vector<int>&v){
    int sum = 0 ;
    int current_sum = 0;
    for (auto x:v){
        if (x<0){
            if (current_sum>sum){
                sum = current_sum;
            }
            current_sum = 0;
        }
        else{
            current_sum +=x;
        }
    }
    return sum;
}

int maxSubarray2(vector<int>&v){
    int current_sum = 0; 
    int sum = v[0]; // Very large negative value
    int start = 0,temp_start=0,end=0;

    for(int i=0;i<v.size();i++){
        current_sum+=v[i];
        // end++;
        if (current_sum>sum){
            sum = current_sum;
            start=temp_start;
            end=i;

        }
        if(current_sum<0){
            current_sum=0;
            temp_start=i+1;
        }
    }
    cout<<endl<<"[";
    for(int i= start;i<=end;i++){
        cout<<v[i]<<",";
    }
    cout<<"]"<<endl;
    return sum;

}

int main(){
    vector<int>v1 = {-2,1,-3,4,-1,2,1,-5,4};
    int largestSum = maxSubarray2(v1);

    cout<<endl<<"Largest sum: "<<largestSum<<endl;
}