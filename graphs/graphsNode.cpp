#include <iostream>
#include<bits/stdc++.h>
using namespace std;


class Node{
    public:
        string name;
        list<string> nbrs;

        Node(string name){
            this->name = name;
        }
};

class Graph{
   
    unordered_map<string,Node*> m;

    public:
        Graph(vector<string> cities){
            for ( auto city : cities ){
                m[city] = new Node(city);
            }
        }

        void addEdge(string s , string d , bool undir=false){
            m[s]->nbrs.push_back(d);
            if(undir){
                m[d]->nbrs.push_back(s);
            }
        }

        void printGraph(){
            for( auto cityPair : m ){
                auto city = cityPair.first;
                Node *node = cityPair.second;
                cout << city <<"-->";

                for ( auto nbr : node->nbrs ){
                    cout << nbr << ",";
                } 
                cout<<endl;
            }
        }
};

int main(){

    vector<string> cities{"mumbai" , "pune" ,"nagpur" ,"delhi"};
    Graph g(cities);

    g.addEdge("mumbai","delhi");
    g.addEdge("mumbai","nagpur");
    g.addEdge("pune","delhi");
    g.addEdge("nagpur","delhi");
    g.addEdge("nagpur","pune");
    g.addEdge("delhi","pune");

    g.printGraph();

    return 0;
}



