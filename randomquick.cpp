#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<fstream>
using namespace std;
void quicksort(int x[],int first,int last)
{
    int pivot,j,temp,i;
    int n=last-first;
    srand(time(NULL));
     if(first<last)
     {
         pivot=first+(rand()%n);
         cout<<pivot;
         i=first;
         j=last;
         while(i<j)
         {
             while(x[i]<=x[pivot]&&i<last)
                 i++;
             while(x[j]>x[pivot]&&j>=0)
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


int main()
{
   int a[5000],n=10,i,j;
  //double t=0;
  //ofstream fin;
 // fin.open("graph.txt");
  srand(time(NULL));
 // clock_t start;
  for(i=0;i<n;i++)
    a[i]=rand()%(n);

  for(i=0;i<n;i++)
    cout<<a[i]<<"  ";

  cout<<endl;
  quicksort(a,0,n-1);
  cout<<endl;
  for(i=0;i<n;i++)
    cout<<a[i]<<"  ";
}

