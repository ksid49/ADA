#include "iostream"
#include<bits/stdc++.h>
using namespace std;
int n=20;
ofstream fp;
int partition(int arr[],int low,int high)
{
	int value=arr[low];
	int i=low;
	int j=high;
	//int arr[j+1]=89;
	while(i<j)
	{
		while(arr[i]<=value&&i<=high)//take equal case
			i++;
		while(arr[j]>value&&j>=0)
			j--;
		if(i<j)
		{
			int temp=arr[i];
			arr[i]=arr[j];
			arr[j]=temp;
		}

	}
	arr[low]=arr[j];//swap with j
	arr[j]=value;
	return j;
}
int partitionr(int arr[],int low,int high)
{

	//double d=clock();
	int diff=high-low+1;
	//srand(time(NULL));
	int pivot=(rand()%diff)+low;
//cout<<pivot<<"\t";
	int value=arr[pivot];
	arr[pivot]=arr[low];
	arr[low]=value;
	int i=low;
	int j=high;
	//int arr[j+1]=89;
	while(i<j)
	{
		while(arr[i]<=value&&i<=high)//take equal case
			i++;
		while(arr[j]>value&&j>=0)
			j--;
		if(i<j)
		{
			int temp=arr[i];
			arr[i]=arr[j];
			arr[j]=temp;
		}

	}
	arr[low]=arr[j];//swap with j
	arr[j]=value;
	return j;
}
void qsortr(int b[],int low,int high)
{
	if(low<high)
	{
		int r=partitionr(b,low,high);
		qsortr(b,low,r-1);
		qsortr(b,r+1,high);
	}
}

void qsort(int arr[],int low,int high)
{
	if(low<high)
	{
		int r=partition(arr,low,high);
		qsort(arr,low,r-1);
		qsort(arr,r+1,high);

	}
}

void merge(int arr[],int low,int mid ,int high)
{
	int i=low,k=low,j=mid+1;
	int c[1000];
	while(i<=mid&&j<=high)
	{
		if(arr[i]>arr[j])
		{
			c[k++]=arr[j++];
		}
		else
		{
			c[k++]=arr[i++];
		}
	}
	if(i<=mid)
	{
		for(;i<=mid;i++)
			c[k++]=arr[i];
	}
	else if(j<=high)
	{
		for(;j<=high;j++)
			c[k++]=arr[j];
	}
	for(i=low;i<=high;i++)
		arr[i]=c[i];
}
void mergesort(int arr[],int low,int high)
{
	if(low<high)
	{
		int mid=(low+high)/2;
		mergesort(arr,low,mid);
		mergesort(arr,mid+1,high);
		merge(arr,low,mid,high);
	}
}
int main()
{

	int arr[1000];
	int b[1000],c[1000];
	clock_t start;
	srand(time(NULL));
	double t1=0,t2=0,t3=0;
	n=100;
	fp.open("qsort.txt");
while(n<=1000)
{
	for(int i=0;i<700;i++)
	{
		for(int i=0;i<n;i++)
		arr[i]=rand()%(n*100);
	srand(time(NULL));
	//sort(arr+n,arr);
	for (int i = 0; i < n; ++i)
	{
		/* code */
		for (int j = 0; j < n-i-1; ++j)
		{
			/* code */
			if(arr[j]<arr[j+1])
			{
				int temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}
	for(int i=0;i<n;i++)//sorting in reverse
		{
			b[i]=arr[i];
			c[i]=arr[i];
	//cout<<arr[i]<<endl;
		}
		start=clock();
		qsort(arr,0,n-1);
		t1=t1+(clock()-start);
	//cout<<"randomized\n";
	start=clock();
	qsortr(b,0,n-1);
	t2=(clock()-start)+t2;

	/*for (int i = 0; i < n; ++i)
	{
		cout<<b[i]<<endl;
	}*/
	start=clock();
	mergesort(c,0,n-1);
	/*for (int i = 0; i < n; ++i)
	{
		cout<<c[i]<<endl;
	}*/
	t3=(clock()-start)+t3;
	}


	cout<<t1<<'\t'<<t2<<'\t'<<t3<<endl;
	fp<<n<<'\t'<<t1<<'\t'<<t2<<'\t'<<t3<<endl;
		n+=100;
	t1=t2=t3=0;
	//
}


	return 0;
}
