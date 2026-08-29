#include<iostream>
#include<list>

using namespace std;

class Queue{
    list<int> list;

    public :
        void push_queue(int element){
            list.push_back(element);
            cout<<element<<" is pushed in queue"<<endl;
        }
        void pop_queue(){
            cout<<list.front()<< " is removed"<<endl;
            list.pop_front();
        }
        void peek_queue(){
            cout<<list.front()<< " is the element"<<endl;
        }
        void print_queue(){
            for(auto x: list){
                cout<< x<<"->";
            }
            cout<<endl;
        }
};

int main(){
    Queue Q1;
    Q1.push_queue(1);
    Q1.push_queue(2);
    Q1.push_queue(3);
    Q1.print_queue();
    Q1.pop_queue();
    Q1.peek_queue();
    Q1.print_queue();
}
