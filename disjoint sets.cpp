#include <bits/stdc++.h>
using namespace std;

class DisjSet{
int *rank, *parent, n;
public:
DisjSet(int n)
{
rank = new int[n];
parent = new int[n];
this->n = n;
createSet();
}
void createSet()
{
for (int i = 0; i < n; i++)
{
parent[i] = i;
}
}
int find_parent(int x){
if (parent[x] != x) {
parent[x] = find_parent(parent[x]);
}
return parent[x];
}

void Union(int x, int y){
int setx = find_parent(x);
int sety = find_parent(y);
if (setx == sety)
return;
if (rank[setx] < rank[sety]) {
parent[setx] = sety;
}
else if (rank[setx] > rank[sety]) {
parent[sety] = setx;
}
else {
parent[sety] = setx;
rank[setx] = rank[setx] + 1;
}
}
};
int main(){
int n,a,b,x,y;
cout<<"enter no of nodes :";
cin>>n;
DisjSet obj(n);
cout<<"enter the connection to"<< n<<" nodes :";
for(int i=0;i<n-1;i++){
cin>>a>>b;
obj.Union(a, b);
}
/*obj.Union(0, 2);
obj.Union(4, 2);
obj.Union(3, 1);*/
cout<<"enter 2 elements to find it's parent or not :";
cin>>x>>y;
if (obj.find_parent(x) == obj.find_parent(y))
cout << "Yes\n";
else
cout << "No\n";
return 0;
}
