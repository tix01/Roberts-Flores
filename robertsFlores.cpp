#include <iostream>
#include <vector>

class Graph{
    
public:
    std::vector<std::vector<int>> abj;
    int V;
    Graph(int vertices):V(vertices),abj(vertices){}

    void addEdge(int u,int v){
        abj[u].push_back(v);
    }
};

void findCycles(Graph& graph,int start,int v,std::vector<bool>& visited, std::vector<int>& path){
    visited[v]=true;
    path.push_back(v);
    for(int u:graph.abj[v]){
        if(u==start){
            for (int vertex : path) {
                std::cout << vertex << " ";
            }
            std::cout << std::endl;
        }
        else if (!visited[u]){
            findCycles(graph,start,u,visited,path);
        }
    }
    path.pop_back();
    visited[v]=false;
}
void robertsFlores(Graph& graph){
    int V=graph.V;
    std::vector<bool> visited(V,false);
    for(int v=0;v<V;v++){
        std::vector<int> path;
        findCycles(graph,v,v,visited,path);
        visited[v]=true;
    }
}

int main(){
    int V = 5;
    Graph graph(V);
    graph.addEdge(0, 1);
    graph.addEdge(1, 2);
    graph.addEdge(2, 0);
    graph.addEdge(1, 3);
    graph.addEdge(3, 2);
    graph.addEdge(2, 4);
    graph.addEdge(4, 0);
    robertsFlores(graph);

    return 0;

}