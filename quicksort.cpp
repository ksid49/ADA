#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<fstream>
using namespace std;
void quicksort(int x[],int first,int last)
{
    int pivot,j,temp,i;

     if(first<last)
     {
         pivot=first;
         i=first;
         j=last;

         while(i<j)
         {
             while(x[i]<=x[pivot]&&i<last)
                 i++;
             while(x[j]>x[pivot])
                 j--;
             if(i<j)
             {
                 temp=x[i];
                  x[i]=x[j];
                  x[j]=temp;
             }
         }

         temp=x[pivot];
         x[pivot]=x[j];
         x[j]=temp;
         quicksort(x,first,j-1);
         quicksort(x,j+1,last);

      }
}

void randomsort(int x[],int first,int last)
{
    int pivot,j,temp,i;
    int n=last-first;
     if(first<last)
     {
         pivot=first+(rand()%n);
         temp=x[pivot];
         x[pivot]=x[first];
         x[first]=temp;

         i=first;
         j=last;

         while(i<j)
         {
             while(x[i]<=x[first]&&i<last)
                 i++;
             while(x[j]>x[first])
                 j--;
             if(i<j)
             {
                 temp=x[i];
                  x[i]=x[j];
                  x[j]=temp;
             }
         }

         temp=x[first];
         x[first]=x[j];
         x[j]=temp;
         quicksort(x,first,j-1);
         quicksort(x,j+1,last);

      }
}
void merge(int a[],int low,int mid ,int high)
{
	int i=low,k=low,j=mid+1;
	int temp[10000];
	while(i<=mid&&j<=high)
	{
		if(a[i]>a[j])
		{
			temp[k++]=a[j++];
		}
		else
		{
			temp[k++]=a[i++];
		}
	}
	if(i<=mid)
	{
		for(;i<=mid;i++)
			temp[k++]=a[i];
	}
	else if(j<=high)
	{
		for(;j<=high;j++)
			temp[k++]=a[j];
	}
	for(i=low;i<=high;i++)
		a[i]=temp[i];
}
void mergesort(int a[],int low,int high)
{
	if(low<high)
	{
		int mid=(low+high)/2;
		mergesort(a,low,mid);
		mergesort(a,mid+1,high);
		merge(a,low,mid,high);
	}
}
/*
void sort(int a[],int size)
{
 int i,temp;
  for(i=0;i<size;i++)
  {
    for(int j=i+1;j<size;j++)
    {
      if(a[i]>a[j])
      {
        temp=a[i];
        a[i]=a[j];
        a[j]=temp;
      }
    }
  }
} */

int main()
{
    int a[10000],b[10000],c[10000],n,i,j;
   double t1=0,t2=0,t3=0;
  ofstream fin;
  fin.open("quicksort.txt");
  srand(time(NULL));
  clock_t start;
  for(n=100;n<=1000;n+=100)
  {
      t3=t2=t1=0;
    for(int j=0;j<5000;j++)
    {
     for(i=0;i<n;i++)
     {
       a[i]=rand()%n;
       b[i]=a[i];
       c[i]=a[i];
     }

     start=clock();
    quicksort(a,0,n-1);
    t1=(clock()-start)+t1;

    start=clock();
    randomsort(b,0,n-1);
    t2=(clock()-start)+t2;

    start=clock();
    mergesort(c,0,n-1);
    t3=(clock()-start)+t3;

    }
     cout<<n<<"\t"<<t1<<"\t"<<t2<<"\t"<<t3<<endl;
     fin<<n<<"\t"<<t1<<"\t"<<t2<<"\t"<<t3<<endl;
  }
    fin.close();
}

