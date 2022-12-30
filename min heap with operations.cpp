#include<iostream>
#include<math.h>
#include<limits.h>
#include<windows.h>
using namespace std;
void swapping(int &x, int&y)
{
 int temp=x;
 x=y;
 y=temp;
}
class minheap
{
public:
 int*arra;
 int capacity;
 int heap_size;
 minheap(int capacit)
 {
 heap_size = 0;
 capacity=capacit;
 arra = new int[capacity];
 }
 int parent(int i)
 {
 return (i-1)/2;
 }
 void inserting_the_key(int key)
 {
 if(heap_size==capacity)
 {
 cout<<"overflow"<<endl;
32
 return;
 }
 heap_size++;
 int index=heap_size-1;
 arra[index]=key;
 while(index!=0 && arra[parent(index)] > arra[index])
 {
 swapping(arra[parent(index)],arra[index]);
 index=parent(index);
 }
 }
 void printing_the_heap()
 {
 for(int i=0; i<heap_size; i++)
 cout<<arra[i]<<" ";
 cout<<endl;
 }
 int left(int i)
 {
 return (2*i)+1;
 }
 int right(int i)
 {
 return (2*i)+2;
 }
 void decreasekey(int i,int new_value)
 {
 arra[i] = new_value;
 while(i!=0 && arra[i] < arra[parent(i)])
 {
 swapping(arra[i] , arra[parent(i)]);
 i= parent(i);
 }
 }
 void minheapify(int index)
 {
 int left_child_index=left(index);
 int right_child_index=right(index);
 int smallest = index;
 if (left_child_index < heap_size && arra[left_child_index] < arra[index])
 smallest = left_child_index;
33
 if (right_child_index < heap_size && arra[right_child_index] <
arra[smallest])
 smallest = right_child_index;
 if (smallest!=index)
 {
 swapping(arra[index],arra[smallest]);
 minheapify(smallest);
 }
 }
 int extractmin()
 {
 if (heap_size <= 0)
 return INT_MAX;
 if (heap_size == 1)
 {
 heap_size --;
 return arra[0];
 }
 int root = arra[0];
 arra[0]=arra[heap_size-1];
 heap_size--;
 minheapify(0);
 return root;
 }
 void keydeletion(int i)
 {
 decreasekey(i,INT_MIN);
 extractmin();
 }
 int getmin()
 {
 return arra[0];
 }
};
int main()
{
 int array_size;
 cout<<"enter the size of the min heap:"<<endl;
 cin>>array_size;
 minheap obj(array_size);
 int option;
34
 do
 {
 cout<<"what operation has to be performed:"<<endl;
 cout<<"1.insertion"<<endl;
 cout<<"2.display"<<endl;
 cout<<"3.extract minimum"<<endl;
 cout<<"4.delete minimum"<<endl;
 cout<<"5.clear screen"<<endl;
 cout<<"6.deletion using index"<<endl;
 cin>>option;
 switch(option)
 {
 case 0:
 break;
 case 1:
 {
 cout<<"insert operation starts"<<endl;
 cout<<"enter the value to be inserted:"<<endl;
 int value;
 cin>>value;
 obj.inserting_the_key(value);
 break;
 }
 case 2:
 {
 cout<<"printing operation will be performed:";
 obj.printing_the_heap();
 break;
 }
 case 3:
 {
 cout<<"extract min operation will be performed:"<<"\t";;
 int min =obj.extractmin();
 cout<<min;
 break;
 }
 case 4:
 {
 cout<<"get min operation will be performed"<<endl;
 obj.getmin();
 break;
35
 }
 case 5:
 system("cls");
 break;
 case 6:
 cout<<"enter the index number to be deleted:"<<endl;
 int delete_key_value;
 cin>>delete_key_value;
 obj.keydeletion(delete_key_value);
 break;
 default:
 cout<<"enter the option between 1 to 5"<<endl;
 break;
 }
 }
 while(option !=0);
 return 0;
}
