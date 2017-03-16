#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,j,swap;
  int a[10],b[10],i,c=0,loc;
  cout <<"Enter the no. of animals:";
  cin>>n;
  cout<<"Enter their hunger values:";
  for(i=0;i<n;i++)
    cin>>a[i];
   for(i=0;i<(n-1); i++)
  {
    for (j = 0 ; j < n - i - 1; j++)
    {
      if (a[j] > a[j+1])
      {
        swap   = a[j];
        a[j]   = a[j+1];
        a[j+1] = swap;
      }
    }
  }
  for(i=0;i<n;i++)
  {
    if(i%2==0)
    {
      loc = n/2 + c;
      b[loc]=a[i];
      c++;

    }
    else
    {
      loc = n/2 - c;
      b[loc]=a[i];
    }

  }
  cout<<"The output is :";
  int dif=0,lar=0;
for(i=0;i<n;i++)
{
    cout<<b[i]<<"   ";

}
for(i=0;i<n-1;i++)
{
   dif = abs(b[i]-b[i+1]);

    if(dif>lar)
        lar=dif;

}
 if((b[n-1]-b[0])>lar)
    lar=(b[n-1]-b[0]);
cout<<"\nMax diff:"<<lar;
}
