8.Implement Job sequencing with deadlines using Greedy strategy 

Source Code 
#include<iostream.h>
#include<stdlib.h>
#include<conio.h>

class Job{
public:
  int deadLine,profit;
};

int compare(const void* a,const void* b){
 Job* jobA=(Job*)a;
 Job* jobB=(Job*)b;
 return jobB->profit-jobA->profit;
}

int main(){
int n;
clrscr();
cout<<"Enter the number of processes: ";
cin>>n;
Job* arr=(Job*)malloc(n*sizeof(Job));
cout<<"Enter number of deadlines: ";
for(int i=0;i<n;i++){
cin>>arr[i].deadLine;
}
cout<<"Enter number of profits: ";
for(i=0;i<n;i++){
cin>>arr[i].profit;
}

qsort(arr,n,sizeof(Job),compare);
int* profit=(int*)malloc(n*sizeof(int));
for(i=0;i<n;i++){
profit[i]=-1;
}
int totalProfit=0;
for(i=0;i<n;i++){
int deadLine=arr[i].deadLine;
for(int j=deadLine-1;j>=0;j--){
if(profit[j]==-1){
profit[j]=arr[i].profit;
break;
}
}
}
for(i=0;i<n;i++){
if(profit[i]!=-1){
totalProfit+=profit[i];
}
}
cout<<"Total Profit="<<totalProfit<<endl;
free(arr);
free(profit);
getch();
return 0;
}
