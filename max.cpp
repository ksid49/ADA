#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<fstream>
using namespace std;
int main()
{
  double t;
  int n_array_search(int a[],int n,int f,int l,int key);
  void sort(int a[] ,int size);
   int a[500],key,i,size=500,n,res,f,l;
  srand(time(NULL));
  ofstream fin;
  fin.open("graph.txt");
  clock_t start,end;
  for(i=0;i<size;i++)
  {
    a[i]=rand()%(size);
  }
  sort(a,size);
  key=rand()%(size);

  f=0;l=size-1;


   for(n=3;n<30;n+=2)
     {
         start=clock();


         for(int j=0;j<10000;j++)
         {
           res =n_array_search(a,n,f,l,key);

         }

         end=clock();
         cout<<end<<endl;
         t=((double)(end-start))/CLK_TCK;
         fin<<t<<endl;

     }
     fin.close();
}
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
}


int n_array_search(int a[],int n,int f,int l,int key)
{
    int par[n+1],i;
     if((l-f+1)<=n)
     {
         for(i=f;i<=l;i++)
            if(key==a[i])
              return 1;
     }
     else
     {
       for(i=0;i<=n;i++)
          par[i]=f+((l-f)*i)/n;
       for(i=1;i<n;i++)
        {
          if(key==a[par[i]])
               return 1;
          else if(key<a[par[i]])
               {
                 return n_array_search(a,n,par[i-1],par[i]-1,key);
               }
        }
        if(a[par[i]]>=key)
          return n_array_search(a,n,par[i-1],par[i]-1,key);

     }
     return 0;

}
