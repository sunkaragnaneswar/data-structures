#include<stdio.h>

void Adjust(int Heap_of_Numbers[],int i)  
{
int j;
int copy;
int Number;
int Reference = 1;
Number=Heap_of_Numbers[0];
while(2*i<=Number && Reference==1)
{
j=2*i;   
if(j+1<=Number && Heap_of_Numbers[j+1] > Heap_of_Numbers[j])
j=j+1;
if( Heap_of_Numbers[j] < Heap_of_Numbers[i])
Reference=0;
else
{
copy=Heap_of_Numbers[i];
Heap_of_Numbers[i]=Heap_of_Numbers[j];
Heap_of_Numbers[j]=copy;
i=j;
}
}
}
void Make_Heap(int heap[])
{
int i;
int Number_of_Elements;
Number_of_Elements=heap[0];
for(i=Number_of_Elements/2;i>=1;i--)
Adjust(heap,i);
}
int main()
{
int heap[30];
int NumberofElements;
int i;
int LastElement;
int CopyVariable;
printf("Enter the number of elements present in the unsorted Array:");
scanf("%d",&NumberofElements);
printf("nEnter the members of the array one by one:"); 
for(i=1;i<=NumberofElements;i++)
scanf("%d",&heap[i]);
heap[0]=NumberofElements;
Make_Heap(heap);
while(heap[0] > 1) 
{
LastElement=heap[0];
CopyVariable=heap[1];
heap[1]=heap[LastElement];
heap[LastElement]=CopyVariable;
heap[0]--;
Adjust(heap,1);
}
printf("nSorted Array:n");
for(i=1;i<=NumberofElements;i++)
printf("%d ",heap[i]);
return 0;
}
