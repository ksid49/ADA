#include<iostream>
#include<stdlib.h>
#include<fstream>
#include<time.h>
using namespace std;

void conquer(int a[],int &max,int &min,int low,int high)
{
	int mid,min1,max1;
	if(low==high)
	{
		min=a[low];
		max=a[low];
	}
	else if(high==low+1)
	{
		if(a[high]>a[low])
		{
			max=a[high];
			min=a[low];
		}
		else
		{
			max=a[low];
			min=a[high];
		}
	}
	else
	{
		mid=(low+high)/2;
		conquer(a,max,min,low,mid);
		conquer(a,max1,min1,mid+1,high);
		if(min>min1)
		  min=min1;
		if(max1>max)
		  max=max1;
	}

}


void brute(int a[],int n,int &max, int &min)
{
	max=min=a[0];
	for(int i=1;i<n;i++)
	{
		if(a[i]>max)
		 max=a[i];
        if(a[i]<min)
		 min=a[i];
	}
}


int main()
{
	ofstream f("graph.txt");
	int size=0,a[50000],max,min,low=0,high;
	time_t start,start1;
	double duration,duration1;
    srand((unsigned) time(&start));
	for(size=100;size<=2000;size+=100)
	{
     duration=0.0;duration1=0.0;
	 high=size-1;
	 low=0;
	  for(int j=0;j<5000;j++)
	 {
	   for(int i=0;i<size;i++)
		  a[i]=rand()%size*2;

	   max=a[0];
	   min=a[0];

	   start=clock();
       brute(a,size,max,min);
	   duration=duration+(double)(clock()-start)/CLOCKS_PER_SEC;

 	   start=clock();
	   conquer(a,max,min,low,high);
       duration1=duration1+(double)(clock()-start)/CLOCKS_PER_SEC;
	 }

	 cout<<size<<"\t"<<duration<<"\t";
	 cout<<"\t"<<size<<"\t"<<duration1<<endl;
     f<<size<<"\t"<<duration;
	 f<<"\t"<<duration1<<endl;
   }
	return 0;
}
