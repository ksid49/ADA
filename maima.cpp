#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<fstream>
using namespace std;
void maxmin(long int a[],long int n)
{
  int i,max,min;
  min=max=a[0];
  for(i=1;i<n;i++)
  {
    if(max<a[i])
      max=a[i];
    if(min>a[i])
      min=a[i];
  }

}

int main()
{
  long int a[5000],n,i,j;
  double t=0;
  ofstream fin;
  fin.open("graph.txt");
  srand(time(NULL));
  clock_t start;
  for(n=500;n<=5000;n+=500)
  {
   for(j=1;j<=10000;j++)
    {
      for(i=0;i<n;i++)
      {
       a[i]=rand()%n;

      }
      start=clock();
      maxmin(a,n);
      t=t+(clock()-start);
    }
    fin<<n<<"\t"<<t<<endl;
  }
}
