#include<iostream>
#include<vector>
using namespace std;
class graph
{
public:
 vector<int> *l;
 int v;
 graph(int v)
 {
 this->v=v;
 l=new vector<int> [v];
 }
 void addedge(int x, int y)
 {
 l[x].push_back(y);
 l[y].push_back(x);
 }
 bool isCyclic_util(vector<int> l[], vector<int> visited, int curr)
 {
 if(visited[curr]==2)
 return true;
 visited[curr] = 1;
 bool FLAG = false;
 for(int i=0; i<l[curr].size(); ++i)
 {
 if(visited[l[curr][i]]==1)
 visited[l[curr][i]] = 2;
 else
 {
 FLAG = isCyclic_util(l, visited, l[curr][i]);
 if(FLAG==true)
 return true;
 }
 }
 return false;
26
 }
 bool isCyclic(vector<int> l[], int V)
 {
 vector<int> visited(V,0);
 bool FLAG = false;
 for(int i=0; i<V; ++i)
 {
 visited[i] = 1;
 for(int j=0; j<l[i].size(); ++j)
 {
 FLAG = isCyclic_util(l,visited,l[i][j]);
 if(FLAG==true)
 return true;
 }
 visited[i] = 0;
 }
 return false;
 }
};
int main()
{
 graph g(10);
 g.addedge(0,1);
 g.addedge(1,2);
 g.addedge(2,3);
 g.addedge(3,4);
 g.addedge(4,5);
 g.addedge(4,1);
 if(g.isCyclic(g.l,10))
 cout<<"yes undirected graph contains cycle";
 else
 cout<<"doesn't contain cycle";
 return 0;
}
