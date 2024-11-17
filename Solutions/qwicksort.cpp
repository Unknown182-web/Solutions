 
#include<iostream.h> 
#include<conio.h> 
void qsort(int [],int,int); 
int n; 
void main() 
{ 
int a[80],i; 
char ch='y'; 
clrscr(); 
while(ch=='y') 
{ 
cout<<"Enter no.of elements:"; 
cin>>n; 
cout<<"Enter the elements of the array:"; 
for(i=0;i<n;i++) 
cin>>a[i]; 
cout<<"Passes are:\n"; 
qsort(a,0,n-1); 
cout<<"\nThe sorted elements are:"; 
for(i=0;i<n;i++) 
cout<<a[i]<<" "; 
cout<<"\nDo you want to sort again?"; 
cout<<"\nEnter your choice y/n:"; 
cin>>ch; 
 } 
 getch(); 
} 
void qsort(int a[],int lb,int ub) 
{ 
 int i,j,pivot; 
 if(lb<ub) 
 { 
  i=lb,j=ub,pivot=a[lb]; 
  while(i<j) 
  { 
   i++; 
   while(a[i]<pivot&&i<=ub) 
   i++; 
   while(a[j]>pivot&&j>=lb) 
   j--; 
   if(i<j) 
   { 
    int t=a[i]; 
    a[i]=a[j]; 
    a[j]=t; 
   } 
  } 
  int temp=a[lb]; 
  a[lb]=a[j]; 
a[j]=temp; 
for(i=0;i<n;i++) 
cout<<a[i]<<" "; 
cout<<"\n"; 
qsort(a,lb,j-1); 
qsort(a,j+1,ub); 
} 
} 