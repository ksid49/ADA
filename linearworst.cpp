#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<fstream>
using namespace std;
int main()
{
  clock_t start,end;
  ofstream f;
  f.open("graphworst.txt");

  long int a[100000],i,key,j,n,delay=0;
  srand(time(NULL));
 for(n=500;n<=10000;n+=500)
 {
   delay=0;
  for(j=1;j<=10000;j++)
  {
      for(i=0;i<n;i++)
      {
        a[i]=rand()%(n);
      }
    key=(rand()%(n/4))+(3*n/4);
    start=clock();
    for(i=0;i<n;i++)
    {
       if(a[key]==a[i])
        break;
    }
    end=clock();
    delay=delay+(end-start);
  }


  f<<delay<<endl;
  cout<<delay<<endl;
 }

}
