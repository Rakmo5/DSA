// Linked list are used for fast insertion and deletion in between the nodes
// Slower insertion
#include<iostream>
#include<vector>

using namespace std;

class Node{
    public:
    int data;
    Node *next = nullptr;

    Node (int data){
        this->data = data;
        this->next = nullptr;
    }

};

class LinkedList{
    
    public:
    Node *head;
    LinkedList (){
        head = nullptr;
    }
    // Insertat the end
    void insert(int value){
        // Create a new node
        Node *newNode = new Node(value);
        // if list is empty
        if (head == nullptr){
            head = newNode;
            return;
        }
        
        // Traverse to last node
        Node *current = head;
        while(current->next!= nullptr){
            current = current->next;
        }
        current->next = newNode; 
    };

    // Print linked list
    void printList(){
        Node *current = head;

        while(current!=nullptr){
            cout<<endl<<current->data<<"->";
            current=current->next;
        }
        cout<<endl<<"NULL"<<endl;
    }

    void insertAtPosition(int value, int position){
        Node *newNode = new Node(value);
        int i=0;
        if (head == nullptr){
            head = newNode;
            return;
        }
        Node *current = head;

        while (i<position && current!=nullptr ){
            if(current==nullptr){
                cout<<endl<<"Position exceded the length of list"<<endl;
                current = newNode;
                return;
            }
            if(i==position){
                Node *temp=current->next;
                current->next=newNode;
                newNode->next=temp;
            }
            i++;
        }
    void deletePos(int position){
        // int i =0;
        Node *current=head;
        for (int i =0; i<=position;i++){
            if (i<position-1){
                current=current->next;
            }
            if (i==position-1){
                current->next=current->next->next;
                delete current->next;

            }
        }
    }

};

int main(){
    LinkedList list;
    list.insert(10);
    list.insert(20);

    list.printList();
}

