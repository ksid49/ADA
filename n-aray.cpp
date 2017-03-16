#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<fstream>
using namespace std;
int main()
{

  int n_array_search(int a[],int n,int f,int l,int key);
  void sort(int a[] ,int size);
   int a[100],key,i,size=100,n,res,f,l;
   double t;
  srand(time(NULL));
  ofstream fin;
  fin.open("graph.txt");
  clock_t start,e;


  f=0;l=size-1;


   for(n=3;n<30;n+=2)
     {
         for(i=0;i<size;i++)
         {
           a[i]=rand()%(size);
         }
         sort(a,size);
         srand(start);
         start=clock();
         t=0;
         for(int j=0;j<50000;j++)
         {

             key=rand()%(size);
           res =n_array_search(a,n,f,l,key);


         }
         t=(clock()-start);
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
              return i;
     }
     else
    {

       for(i=0;i<=n;i++)
          par[i]=f+((l-f)*i)/n;
       for(i=1;i<n;i++)
        {
          if(key==a[par[i]])
               return par[i];
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
