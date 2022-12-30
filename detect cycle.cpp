# include <iostream>
#include <limits.h>
#include <list>
using namespace std;

class Graph
{
int V;
list<int>* adj;
public:
Graph(int V){
this->V = V;
adj = new list<int>[V];
}
void addEdge(int v, int w){
adj[v].push_back(w);
adj[w].push_back(v);
}
bool isadjacent(int v, bool visited[], int parent){
visited[v] = true;
list<int>::iterator i;
for (i = adj[v].begin(); i != adj[v].end(); ++i) {
if (!visited[*i]){
if (isadjacent(*i, visited, v))
return true;
}
else if (*i != parent)
return true;
}
return false;
}
bool isCyclic(){
bool* visited = new bool[V];
for (int i = 0; i < V; i++)
visited[i] = false;
for (int u = 0; u < V; u++) {
if (!visited[u])
if (isadjacent(u, visited, -1))
return true;
}
return false;
}
};
int main(){
int n,a,b;
cout<<"enter no of points to be connected :";
cin>>n;
Graph g1(n);
cout<<"enter the connectivity of "<<n-1<<" points :\n";
for(int i=0;i<n-1;i++){
cin>>a>>b;
g1.addEdge(a,b);
cout<<"THE POINTS ARE\t"<<a<<"->"<<b<<"\n";
}
cout<<"\n";
if(g1.isCyclic())
cout << "Graph contains cycle\n";
else
cout << "Graph doesn't contain cycle\n";
return 0;
}
