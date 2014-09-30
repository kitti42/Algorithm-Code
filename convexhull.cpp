/*
	Name:  GRaham's scan for convex hull 
	Author: Kriti Dang
	Date: 10/04/14 22:27
	Description: O(n log n)
*/

 #include<iostream>
#include<climits>
#include<cstdlib>
#define MAX 100
#include<stack>
using namespace std;
//---------------------------------------------------------

typedef struct p
{
	int x,y;
}point;
point arr[MAX];

inline int compareAngle(const void *a,const void *b)
{
	if(((point *)a)->y-arr[0].y==0)
		return -1;
	if(((point *)b)->y-arr[0].y==0)
		return 1;
	double a1=(((point *)a)->x-arr[0].x)*1.0/(((point *)a)->y-arr[0].y);
	double b1=(((point *)b)->x-arr[0].x)*1.0/(((point *)b)->y-arr[0].y);
	if(a1>b1)
		return -1;
	else if(b1>a1)
		return 1;
	return 0;
}
//----------------------------------------------------------

int calArea(point a,point b,point c)
{
	int area;
	area=(a.x*(b.y-c.y))-(a.y*(b.x-c.x))+b.x*c.y-c.x*b.y;
	return area;
}
//-----------------------------------------------------------

int main()
{
	int n;
	cin>>n;
	int index;
	
	for(int i=0;i<n;i++)                                  //taking the input,i.e. n points
	{
		cin>>arr[i].x>>arr[i].y;
	}
	int min=INT_MAX;
	
	for(int i=0;i<n;i++)                                 //choosing the lowest point
	{
		if(min>arr[i].y)
		{
			min=arr[i].y;
			index=i;
		}
		else if(min==arr[i].y && arr[i].x < arr[index].x)
		{
			index=i;
		}
	}
	
	point a;
	a.x=arr[index].x;
	a.y=arr[index].y;
	arr[index]=arr[0];
	arr[0]=a;
	qsort(arr+1,n-1,sizeof(point),compareAngle);
	
	stack<point> S;
	S.push(arr[0]);
	S.push(arr[1]);
	for(int i=2;i<n;i++)
	{
		 point a=S.top();
		 S.pop();
		 point b=S.top();
		 S.pop();
		 int area=calArea(b,a,arr[i]);
		 //cout<<area<<endl;
		 if(area>=0)                                     //if area of triangle is negative,it means angle > 180 degrees
		 {
		 	S.push(b);
		 	S.push(a);
		 	S.push(arr[i]);
		 }
		 
		 else
		 {
		 	S.push(b);
		 	S.push(arr[i]);
		 }
	}
	while(!S.empty())
	{
		cout<<S.top().x<<" "<<S.top().y<<endl;
		S.pop();
	}
}
