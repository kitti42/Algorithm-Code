/*
  Name: kriti
  Copyright: 
  Author: 
  Date: 28/05/13 12:00
  Description: prims
*/  
#include<iostream>
#include<conio.h>
#include<list>
#include<mem.h>
void heapInsert(int heap[],int key,int heap2[],int b);
void delMin(int heap[],int n,int heap2[]);
void heapify(int a[],int i,int n,int heap2[]);
int linsearch(int a[],int key,int n);
void pheapify(int heap[],int k,int heap2[]);
using namespace std;
int index=0;
main()
{
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
       
       for(i=0;i<v;i++)
       s[i]=0;
       s[0]=1;
       int heap[e],heap2[e];
       for(i=0;i<e;i++){
       heap[i]=0;
       heap2[i]=-1;
       }
     //  cout<<arr[0].size()<<endl;
       int k=arr[0].size();
       for(i=0;i<k;i++)
       {
                                  b=arr[0].front();
                                  // cout<<b<<" ";
                                  arr[0].pop_front();
                                  heapInsert(heap,wt[0].front(),heap2,b);
                                  wt[0].pop_front();     
       }
       //cout<<endl;
       int ver;
       int count=v-1;
       while(count--)
       {  /*for(i=0;i<index;i++)
       cout<<heap[i]<<" ";
       cout<<endl;
       for(i=0;i<4;i++)
       cout<<s[i]<<" ";
       cout<<endl;*/
                      ans=ans+heap[0];
                      //cout<<ans<<endl;  
                      ver=heap2[0];
                      //delMin(heap,index,heap2);
                      //cout<<ver<<endl;
                      s[ver]=1;
                      delMin(heap,v,heap2);
                      k=arr[ver].size();
                      for(i=0;i<k;i++){     
                                                     b=arr[ver].front();
                                                    // cout<<b<<" ";
                                                     arr[ver].pop_front();
                                                     if(s[b]==0){
                                                     int o=linsearch(heap2,b,index);
                                                     if(o==-1){
                                                     heapInsert(heap,wt[ver].front(),heap2,b);
                                                     //wt[ver].pop_front();
                                                     }
                                                     else if(heap[o]>wt[ver].front()){
                                                          //cout<<"kit"<<b<<" ";
                                                     heap[o]=wt[ver].front();
                                                     pheapify(heap,o,heap2);
                                                     }
                                                     }wt[ver].pop_front();
     
                                                     }                                                  
                      
                   }  cout<<endl; 
cout<<ans<<endl;                      
getch();
}

void heapInsert(int heap[],int key,int heap2[],int b)
{
	heap[index]=key;
    heap2[index]=b;
    int y=index;
    int i=0;
    while(i>=0&&index!=0)
    {
    	i=(y-1)/2;
        if(heap[i]>heap[y])
        {
        	heap[i]^=heap[y]^=heap[i]^=heap[y];
            heap2[i]^=heap2[y]^=heap2[i]^=heap2[y];
        }
        else break;
        y=i;
     }
	 index++;
}
void pheapify(int heap[],int o,int heap2[]){
     int i=10;
     while(i>=0){
                 i=(o-1)/2;
                 if(heap[i]>heap[o])
                 { heap[i]^=heap[o]^=heap[i]^=heap[o];
                heap2[i]^=heap2[o]^=heap2[i]^=heap2[o];
                }
                else break;
                o=i;
                }
                }                  
int linsearch(int a[],int key,int n)
{
    for(int i=0;i<n;i++)
    if(a[i]==key)
    	return i;
    return -1;
}    
     
void delMin(int heap[],int n,int heap2[])
{
    int y=heap[0];
    heap[0]=heap[index-1];
    heap[index-1]=32768;
    heap2[0]=heap2[index-1];
    heap2[index-1]=-1;
    index--;
    heapify(heap,0,index,heap2);
}

void heapify(int a[],int i,int n,int heap2[])
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
     
     
     
                                   

       
       
       
       
       
