#include<iostream>
#include<vector>

using namespace std;

class graph{
    private :
        vector<vector<int>> mygraph;
    public:
        graph(int size){
            int number_of_nodes=size;
            mygraph.resize(size);
        }
        void addEdge(int node1 ,int node2){
            mygraph[node1].push_back(node2);
            mygraph[node2].push_back(node1);
            cout<<"Edge added between "<<node1<<" and "<< node2;
            return;
        }
        void  printgraph(){
            cout<<endl;
            for (auto x: mygraph){
                cout<<"{";
                for(auto y: x){
                    cout<<y<<",";
                }
                cout<<"}"<<endl;
            }
            return;
        }
};
int main(){
    graph g(4);
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(0,3);
    g.printgraph();
}

