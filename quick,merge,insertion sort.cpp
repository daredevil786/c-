#include<iostream>
using namespace std;
class sort
{
int a[30],n;
public:
void read()
{
cout<<"Enter size\n";
cin>>n;
cout<<"enter elements\n";
for(int i=0;i<n;i++)
cin>>a[i];
}
int u=n-1,l=0,i,j;
void qs();
void ms();
void is();
void display()
{
cout<<"\nelemnts after sorting\n";
for(int i=0;i<n;i++)
cout<<a[i]<<" ";cout<<"\n\n";
}
void choice();
};
void sort::choice()
{
cout<<"\nmenu\n1.quick sort\n2.merge sort\n3.insertion sort\nenter choice";
int ch;
cin>>ch;
switch (ch)
{
case 1: qs();
break;
case 2: ms();
break;
case 3: is();
break;
default: cout<<"enter the choice precisely\n";
choice();
}
}
int partition(int a[],int l,int u)
{
int v,i,j,temp;
v=a[l];
i=l;
j=u+1;
do
{
do
i++;
while(a[i]<v&&i<=u);
do
j--;
while(v<a[j]);
if(i<j)
{
temp=a[i];
a[i]=a[j];
a[j]=temp;
}
}while(i<j);
a[l]=a[j];
a[j]=v;
return(j);
}
void quick_sort(int a[],int l,int u)
{
int j;
if(l<u)
{
j=partition(a,l,u);

quick_sort(a,l,j-1);
quick_sort(a,j+1,u);
}
}
void sort::qs()
{
quick_sort(a,0,n-1);
}

void sort::is()
{
int i,j,temp;
for(i=1; i<n; i++)
{
temp=a[i];
j=i-1; 
while((temp<a[j]) && (j>=0))
{
a[j+1]=a[j];
j=j-1;
}
a[j+1]=temp;}
}
void merge(int arr[], int start, int  middle, int end)
{
int i, j, k;
int n1 = middle-start + 1;
int n2 = end-middle;
int L[30], R[30];
for (i = 0; i < n1; i++)
L[i] = arr[start+i];
for (j = 0; j < n2; j++)
R[j] = arr[middle + 1+ j];
i = 0;
j = 0;
k = start;
while (i < n1 && j < n2)

{
if (L[i] <= R[j])
{
arr[k] = L[i];
i++;
}
else
{
arr[k] = R[j];
j++;
}
k++;
}
while (i < n1)
{
arr[k] = L[i];
i++;
k++;
}
while (j < n2)
{
arr[k] = R[j];
j++;
k++;
}
}
void mergeSort(int arr[], int start, int end)
{
if (start < end)
{
int middle =start+(end-start)/2;
mergeSort(arr, start, middle);
mergeSort(arr,middle+1, end);
merge(arr, start, middle, end);
}
}
void sort::ms()
{ mergeSort(a, 0, n-1);

}

int main()
{
sort s;
int a=1;
do{
s.read();
s.choice();
s.display();
cout<<"\nenter any number to perform the sorting again\nenter 0 to quit";
cin>>a;
}while(a);
}
