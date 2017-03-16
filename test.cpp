#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;

void maxchar(char a[],char &max,int low,int high)
{
    char max1;
    int n=high-low+1,mid;
  if(n==1)
    max= a[low];
  else if(n==2)
  {
      if((int)a[low]>(int)a[high])
        max= a[low];
      else
        max=a[high];
  }
  else
  {
      mid=(low+high)/2;
      maxchar(a,max,low,mid);
      maxchar(a,max1,mid+1,high);
      if((int)max<(int)max1)
        max=max1;
  }
  //cout<<max;

}

int main()
{
    char a[50],max;
    int low=0,high,len;
    cout<<"Enter the string:";
    gets(a);

    len=strlen(a);
    high=len-1;
    for(int i=0;i<len;i++)
    {
        if(isupper(a[i]))
            a[i]=tolower(a[i]);
    }
   // puts(a);
    max=a[0];
    //cout<<max;
    maxchar(a,max,low,high);
    cout<<"Greatest character is:"<<max;
}
