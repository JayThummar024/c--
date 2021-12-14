#include<bits/stdc++.h>
using namespace std;

class Graph{
    int V;
    list<int> *l;
    public:
        Graph(int v){
            V = v;
            l = new list<int>[V];
        }

        void addEdge(int i,int j,bool undir=true){
            l[i].push_back(j);
            if(undir){
                l[j].push_back(i);
            }
        }

        void bfs_shortest_path (int source , int dest){
            queue<int> q;
            bool *visited = new bool[V]{0};
            int *dist = new int[V]{0};
            int *parent = new int[V];

            for(int i =0 ;i<V;i++){
                parent[i] = -1;
            }

            q.push(source);
            visited[source] = true;
            parent[source] = source;
            dist[source]=0;

            while(!q.empty()){
                int f = q.front();
                cout<< f << ",";
                q.pop();

                for( auto ele:l[f]){
                    if(!visited[ele]){
                        q.push(ele);
                        parent[ele] = f;
                        dist[ele] = dist[f] +1;
                        visited[ele] = true;
                    }
                }
            }

            for( int i=0; i<V; i++ ){
                cout<<"Shortest dist of node "<<i<<" is "<<dist[i]<<endl;
            }

            if(dest!=-1){
                int temp=dest;
                while(temp!=source){
                    cout<<temp<<" -- ";
                    temp = parent[temp];
                }
                cout<<source;
            }
        }
};

int main(){
    Graph g(7);
    g.addEdge(0,1);
    g.addEdge(2,1);
    g.addEdge(3,5);
    g.addEdge(6,5);
    g.addEdge(4,5);
    g.addEdge(0,4);
    g.addEdge(3,4);
    g.bfs_shortest_path(1 , 6);

    return 0;
}