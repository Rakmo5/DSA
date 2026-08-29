#include<iostream>
#include<vector>

using namespace std;
class stack{

    private:
    vector<int> v;

    public:
    void printVector(){
    cout<<endl<<"Printing Vector :"<<endl;
    for(auto x : v){
        cout<<x<<",";
    }
    cout<<endl;
}

    void push_stack(int element){
        v.push_back(element);
        cout<<element <<" is pushed on stack"<<endl;
        printVector();
        return;
    }
    void pop_stack(){
        
        cout<< v.back()<<" is poped element on stack"<<endl;
        v.pop_back();
        printVector();
        return;
    }
    void peak_stack(){
        cout<< v.back()<<" is at top of stack"<<endl;
    }
};

int main(){
    stack s1;
    s1.push_stack(1);
    s1.push_stack(2);
    s1.push_stack(3);
    s1.peak_stack();
    s1.pop_stack();

}