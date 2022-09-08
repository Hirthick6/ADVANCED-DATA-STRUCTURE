#include<iostream>
using namespace std;
template<typename T>
T linear(T a[],int n,T x)
{
    int c=0;
    for(int i=0;i<n;i++)
    {
        if(a[i]==x)
        {
            cout<<"The Element "<<a[i]<<" is Found"<<endl;
            c=1;
            break;
        }
    }
        if(c==0)
        {
            cout<<"Element Not Found"<<endl;
        }

}
int main()
{
    int n,ch,x;
    char y;
    cout<<"Enter Size of Array:";
    cin>>n;
    int a[n];
    char b[n];
    cout<<"Enter Your choice:\n1.Int\n2.Char\n";
    cin>>ch;
    switch(ch)
    {
    case 1:
        cout<<"Enter Numbers:";
        for(int i=0;i<n;i++)
        {
           cin>>a[i];
        }
        cout<<"Enter Element To Be searched:\n";
        cin>>x;
        linear<int>(a,n,x);
        break;

        case 2:
        cout<<"Enter Characters:";
        for(int i=0;i<n;i++)
        {
           cin>>b[i];
        }
        cout<<"Enter Element to be Searched:\n";
        cin>>y;
        linear<char>(b,n,y);
        break;
    }
}
