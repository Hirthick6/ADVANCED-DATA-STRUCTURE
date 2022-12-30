//linear search
#include<iostream>
using namespace std;
int main()
{
int a[100],n,data,found = 0;
cout<<"Enter Size of an Array :";
cin>>n;
cout<<"Enter Array Elements \n";
for(int i=0;i<n;i++)
{
cin>>a[i];
}
cout<<"Enter the data to be searched:";
cin>>data;
for(int i=0;i<n;i++)
{
if(a[i]==data)
{
cout<<"Element Present at the index:"<<i;
found = 1;
break;
}
 }
 if(found==0)
{
cout<<"Not found";
}
return 0;
}
