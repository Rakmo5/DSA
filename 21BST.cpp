#include <iostream>

using namespace std;

class Node{
    public:
    int data;
    Node * left;
    Node * right;
    Node(int value){
        this->data = value;
        left = nullptr;
        right= nullptr;
    }
};
class BST {
    private:
    Node * root;

    void inorder(Node* current){
        if (current == nullptr){
            return;
        }
        inorder(current->left);
        cout<<current->data<<" ";
        inorder(current->right);

    }
    void preorder(Node* current){
        if (current == nullptr){
            return;
        }
        cout<<current->data<<" ";
        preorder(current->left);
        preorder(current->right);
    }
    public:

    BST(){
        root = nullptr;
    }
    void insert(int value){
        
        if (root==nullptr){
            root = new Node(value);
            return;
        }
        Node * current = root;
        while (current != nullptr){
            if (current->data > value){
                
                if (current -> left == nullptr){
                    current->left = new Node(value);
                    return;
                }
                current=current->left;
            }
            else {
                if (current -> right == nullptr){
                    current->right = new Node(value);
                    return;
                }
                current= current->right;

            }
        }
    
    }    
    void lookup(int value){
        Node* current = root;
        while(current!=nullptr){
        
            if (current->data== value ){
                cout<<"Element Found";
                return;
            }
            else if(current->data > value){
                current = current->left;
            }
            else {
                current = current->right;
            }

        }
        cout<<"Element not found";
        return;
    }
    void removeNode(int value){
        // Lookup logic

        Node* current = root;
        Node* current_parrent=nullptr;
        while (current!=nullptr){
            if (current->data==value){
                if (current_parrent==nullptr){
                    
                }
                if (current->left==nullptr && current ->right==nullptr){
                    if (current_parrent->left==current){
                        current_parrent->left=nullptr;
                    }
                    else{
                        current_parrent->right=nullptr;
                    }
                    delete current;
                    
                    cout<<endl<<"Removed "<<value<<endl;
                    return;
                }
                else if(current->left==nullptr && current->right!=nullptr){
                    current_parrent->right=current->right;
                    delete current;
                    cout<<endl<<"Removed "<<value<<endl;
                    return;
                }
                else if(current->right==nullptr && current->left!=nullptr){
                    current_parrent->left=current->left;
                    delete current;
                    cout<<<<endl<<"Removed "<<value<<endl;
                    return;
                }
                else{
                    Node* finder=current->right;
                    while (finder->left!=nullptr){
                        finder=finder->left;
                    }
                    current->data=finder->data;
                    if (finder->right!=nullptr){
                        
                    }
                    delete finder;
                    cout<<<<endl<<"Removed "<<value<<endl;
                    return;
                }
            }
            else if (current->data>value){
                current_parrent=current;
                current= current->left;
            }
            else {
                current_parrent=current;
                current= current->right;
            }

        }
        

    }
    void inorder(){
        inorder(root);
        }
    void preorder(){
        preorder(root);
    }
};

int main(){
    BST tree;
    tree.insert(5);
    tree.insert(2);
    tree.insert(4);
    tree.insert(3);
    tree.insert(1);
    cout<<"inoreder: ";
    tree.inorder();
    cout<<endl<<"preorder: ";
    tree.preorder();
    cout<<endl;
    tree.lookup(1);
}
