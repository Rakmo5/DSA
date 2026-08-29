#include <iostream>
#include <vector>
using namespace std;
template<typename T>
class MyArray{
    public:
        int length;
        T* data;
        int capacity;

        MyArray(int cap){
            capacity = cap;
            length = 0;
            data = new T[capacity];
            // this->data = {};
            // for(int i=0;i<length;i++){
            //     data[i]=0;
            // }
        }
        // Get method
        auto get(int index){
            if(index<0 || index>=length){
                cout<<"Index out of bounds!"<<endl;
                return -1;
            }
            return data[index];
        }
        // Set Method
        auto set(int index, T value){
            if(index<0||index>=length){
                cout<<"Index out of bounds!"<<endl;
                return -1;
            }
            return data[index]=value;
        }

        // Push back
        auto push_back(T value){
            if(length == capacity){
                // Increase capacity
                capacity = capacity*2;
                T* newData = new T[capacity];
                // Copy old elements
                for(int i=0;i<length;i++){
                    newData[i]=data[i];
                }
                delete[] data; // free old memory 
                data = newData;// point to new memory
            }

            data[length]=value; //free old memory
            length++;             // point to new memory
        }
        auto pop_back(){
            if (length==0){
                cout<<"Array is empty "<<endl;
                return;
            }
            length--;
        }

        // Delete an element
        void shiftItems(int index){
            for (int i = index;i<length-1;i++){
                data[i]=data[i+1];
            }
        }

        void remove(int index){
            if(index<0||index>=length){
                cout<<"Index out of bounds!"<<endl;
                return ;
            }
            T item = data[index];
            shiftItems(index);
            cout<<"Removed "<<item <<" at index "<<index;
            length--;
            return ;

        }
        
        auto printArray(){
            cout<<endl<<"[";
            for (int i=0;i<length;i++){
                cout<<data[i]<<",";
            }
            cout<<"]"<<endl;

        }
        // destructor
        ~MyArray(){
            delete[] data; // free memory
        }
        

};

int main(){
    MyArray<string> arr(5);
    // arr.set(0,10);
    // arr.set(1,20);
    arr.push_back("american");
    // cout<<arr.get(0)<<endl;
    arr.push_back("russian");
    arr.push_back("african");
    arr.push_back("indian");
    arr.push_back("german");
    arr.remove(2);
    arr.printArray();
    // cout<<arr.get(1)<<endl;
    // cout<<arr.get(2)<<endl;
}
