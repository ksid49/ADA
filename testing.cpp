#include<iostream>
#include<stdlib.h>
#include<time.h>

using namespace std;
int main()
{
  int n_array_search(int a[],int n,int f,int l,int key);
  void sort(int a[] ,int size);
   int a[500],key,i,size=500,n=3,res=0,f,l;
  srand(time(NULL));

  for(i=0;i<size;i++)
  {
    a[i]=rand()%(size);
  }
  sort(a,size);
  key=rand()%size;
  cout<<key<<endl;
  f=0;l=size-1;
   for(i=0;i<size;i++)
      cout<<a[i]<<"  ";
  res=n_array_search(a,n,f,l,key);
   cout<<endl<<res;
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
     int res=0,par[n+1],i;
     if((l-f+1)<=n)
     {
         for(i=f;i<=l;i++)
            if(key==a[i])
               return 2;
     }
     else
     {
       for(i=0;i<=n;i++)
          par[i]=f+((l-f)*i)/n;
       for(i=1;i<n;i++)
        {
          if(key==a[par[i]])
             {

              return 3;

             }
          else if(key<a[par[i]])
               {
                 return (n_array_search(a,n,par[i-1],par[i]-1,key));
               }


        }
        if(a[par[i]]>=key)
          return (n_array_search(a,n,par[i-1],par[i],key));

     }

 return 0;
}
