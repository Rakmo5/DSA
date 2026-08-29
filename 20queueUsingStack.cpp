#include<iostream>
#include<stack>

using namespace std;

class Queue{

    stack<int> input_stack;
    stack<int> output_stack;
    public:
        // void Queue()
        void push_queue(int element){
            input_stack.push(element);
            cout<<element <<" has been pushed on queue"<<endl;
            return;
        }
        void pop_queue(){
            // cout << "Entered pop_queue()" << endl;
            if(input_stack.empty() && output_stack.empty()){
            cout << "Queue is empty" << endl;
            return;
            }
            if (output_stack.empty()){
                // cout << "Moving elements..." << endl;
                while (!input_stack.empty()){
                    output_stack.push(input_stack.top());
                    input_stack.pop();
                }
            }

            cout<<output_stack.top()<<" has been popped"<<endl;
            output_stack.pop();
            return;
        }       
        void front(){
            if(input_stack.empty() && output_stack.empty()){
            cout << "Queue is empty" << endl;
            return;
            }
            if (output_stack.empty()){
                // cout << "Moving elements..." << endl;
                while (!input_stack.empty()){
                    output_stack.push(input_stack.top());
                    input_stack.pop();
                }
            }
            cout<<output_stack.top()<<" is at front"<<endl;
        }

};

int main(){
    Queue q1;
    q1.push_queue(1);
    q1.push_queue(2);
    q1.push_queue(3);
    q1.push_queue(4);
    q1.pop_queue();
    q1.front();
}
