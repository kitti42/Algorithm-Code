#include<iostream>
#include<conio.h>
#include<list>
#include<mem.h>
using namespace std;
int index=0;
main(){
       int v,e;
       cin>>v>>e;
       list<int> arr[v];
       list<int> wt[v];
       int a,b,w,i,ans=0;
       
       for(i=0;i<e;i++)
       {
                       cin>>a>>b>>w;
                       arr[a].push_back(b);
                       arr[b].push_back(a);
                       wt[a].push_back(w);
                       wt[b].push_back(w);
       }
       
       int s[v];
       memset(s,0,v-1);
       s[0]=1;
       int heap[e],heap2[e];
       memset(heap,32768,e-1);
       memset(heap2,-1,e-1);
       int b;
       for(i=0;i<arr[0].size();i++)
       {
                                   b=arr[0].pop_front();
                                   heapInsert(heap,wt[0].pop_front(),heap2,b);
       }
       while(index>=0)
       {
                      ans=ans+heap[0];
                      ver=heap2[0];
                      s[ver]=1;
                      delMin(heap,v,heap2);
                      for(i=0;i<arr[ver].size();i++){
                                                     b=arr[ver.pop_front()];
                                                     if(s[b]==0)
                                                     heapInsert(heap,wt[ver].pop_front(),heap2,b);
                                                     }
cout<<ans<<endl;                      
getch();
}

void heapInsert(int heap[],int key,int heap2[],int b)
{
     heap[index]=key;
     heap2[index]b;
     int y=index;
     while(i>=0)
     {
                i=(y-1)/2;
                if(heap[i]>heap[index])
                {
                heap[i]^=heap[y]^=heap[i]^=heap[y];
                heap2[i]^=heap2[y]^=heap2[i]^=heap2[y];
                }
                else break;
                y=i;
     }
}

void delMin(int heap[],int n,int heap2)
{
    int y=heap[0];
    heap[0]=heap[index];
    heap[index]=32768;
    heap2[0]=heap2[index];
    heap2[index]=-1;
    index--;
    heapify(heap,0,n,heap2);
}

void heapify(int a[],int i,int n,int heap2)
{
    int l,r,largest,temp;
    l=2*i+1;
    r=2*i+2;
    if(l<n&&a[l]<a[i])
    largest=l;
    else largest=i;
    if(r<n&&a[r]<a[largest])
    largest=r;
    if(largest!=i)
    {
               temp=a[i];
               a[i]=a[largest];
               a[largest]=temp;
                temp=heap2[i];
               heap2[i]=heap2[largest];
               heap2[largest]=temp;
               heapify(a,largest,n,heap2);
    }
}  
     
     
     
                                   

       
       
       
       
       
