// Given : A singly linked list
// To reverse the content of the list 
// Input : 1,26,3,6 list
// output: 6,3,26,1 list
#include<iostream>
#include<list>

using namespace std;

class Node {
    public:
        int data;
        Node* next;

        Node(int data){
            this->data = data;
            this->next = nullptr;
        }
};

class LinkedList {
    public:
        Node* head;
        LinkedList(){
            head=nullptr;
        }

        //Insert at end
        void insert(int value){
            Node*newNode = new Node(value);
            if (head ==nullptr){
                head = newNode;
                return;
            }
            Node*current = head;
            while (current->next!=nullptr){
                current=current->next;
            }
            current->next = newNode;
        }
    // Print List(){
    void PrintList(){
        Node* current = head;
        while(current!=nullptr){
            cout<< current->data<<"->";
            current=current->next;
        }
        cout<<"NULL"<<endl;
    }
    void reverseList(){
       Node * prev=nullptr;
       Node * current=head;
       Node* next = nullptr;

       while (current != nullptr){
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
       }
       head=prev;
       return;
};



int main(){

}