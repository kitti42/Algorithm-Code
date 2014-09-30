#include<iostream>
#include<list>
#include<vector>
#include<limits>
using namespace std;

#define MAX 100



list<pair<int,int> > adj[MAX];
vector<int> weight(MAX,numeric_limits<int>::max());

void relax (int u,int v,int wt) 
{
     
     if (weight[v] > weight[u] + wt) 
        weight[v] = weight[u] + wt;
}


bool bellman_ford(int v,int e) 
{
     
     weight[0] = 0;
     
     for(int k=0;k<v-1;k++)
     {
     for(int u=0;u<v;u++) 
	 {
             
          for(list<pair<int,int> >::iterator i = adj[u].begin() ; i != adj[u].end() ; i ++) {
                        
                int q = (*i).first;
                int wt =(*i).second;             
                relax(u,q,wt)  ;                         
          }
     }
 	}	
     for(int u=0;u<v-1;u++) {
             
          for(list<pair<int,int> >::iterator i = adj[u].begin() ; i != adj[u].end() ; i ++) {
                        
                int q = (*i).first;
                int wt =(*i).second; 
                if (weight[q] > weight[u] + wt) { 
                
                   weight[q] = weight[u] + wt;
                   return false;
                }                     
          }
     }
          
     return true;
}

int main()
{
    
    int edges,vertices;
    cin >> vertices >> edges ;
    
    int a,b,wt;
    for(int i=0;i<edges;i++) 
	{
            
         cin >> a >> b >> wt;
         
         adj[a].push_back(make_pair(b,wt));
         adj[b].push_back(make_pair(a,wt));        
    }
    
    bellman_ford(vertices,edges) ? cout << "no cycle " : cout << "cycle found ";
        for(int i=0;i<vertices;i++)
        cout<<weight[i]<<" ";
}
