#include<iostream>
#include<map>
#include<queue>
using namespace std;
//---------------------------------------
string move(string parent,int choice)
{
	int a[4];
	int b[4];
	for(int i=0;i<2;i++)
	{
		a[i]=parent[i]-'0';
		b[i]=3-a[i];
	}
	a[2]=parent[2]-'0';
	
		if(choice==1)
		{
			if(a[2]==0)
			{
				a[0]--;
				b[0]++;
			}
			else
			{
				a[0]++;
				b[0]--;
			}
		}
		else if(choice==2)
		{
			if(a[2]==0)
			{
				a[1]--;
				b[1]++;
			}
			else
			{
				a[1]++;
				b[1]--;
			}
		}
		else if(choice==3)
		{
			if(a[2]==0)
			{
				a[0]--;   b[0]++;
				a[1]--;   b[1]++;
			}
			else
			{
				a[0]++;   b[0]--;
				a[1]++;   b[1]--;
			}
		}
		else if(choice==4)
		{
			if(a[2]==0)
			{
				a[0]-=2;
				b[0]+=2;
			}
			else
			{
				a[0]+=2;
				b[0]-=2;
			}
		}
		else
		{
			if(a[2]==0)
			{
				a[1]-=2;
				b[1]+=2;
			}
			else
			{
				a[1]+=2;
				b[1]-=2;
			}
		}
		if(a[0]>a[1] && a[1]!=0)
			return "N";
		if(b[0]>b[1] && b[1]!=0)
			return "N";
		char str[4];
		str[0]=a[0]+'0';
		str[1]=a[1]+'0';
		str[2]=(a[2]+1)%2+'0';
		str[3]='\0';
		string s=str;
		return s;
}
int main()
{
	int bhoot[3]={0},pari[3]={0};
	string goal="001";
	string start="330";
	map<string,string> state;
	state[start]=start;
	queue<string> Q;
	Q.push(start);
	while(!Q.empty())
	{
		string temp=Q.front();
		Q.pop();
		//cout<<endl<<temp<<" ";
		if(temp==goal)
		break;
		if(((temp[0]>'0' && temp[2]=='0')||(temp[0]<'3' && temp[2]=='1'))&& state.find(move(temp,1))==state.end() && move(temp,1)!="N")   //1 bhoot 
		{
			Q.push(move(temp,1));
			state[move(temp,1)]=temp;
			//cout<<move(temp,1)<<" ";
		}
		
		if(((temp[1]>'0' && temp[2]=='0')||(temp[1]<'3' && temp[2]=='1')) && state.find(move(temp,2))==state.end() && move(temp,2)!="N")   //1 pari
		{
			Q.push(move(temp,2));
			state[move(temp,2)]=temp;
			//cout<<move(temp,2)<<" ";
		}
		
		if(((temp[0]>'0' && temp[1]>'0' && temp[2]=='0')||(temp[0]<'3' && temp[1]<'3' && temp[2]=='1')) && state.find(move(temp,3))==state.end() && move(temp,3)!="N")  //1 bhoot 1 pari
		{
			Q.push(move(temp,3));
			state[move(temp,3)]=temp;
			//cout<<move(temp,3)<<" ";
		}
		
		if(((temp[0]>'1' && temp[2]=='0')||(temp[0]<'2' && temp[2]=='1')) && state.find(move(temp,4))==state.end() && move(temp,4)!="N")    //2 bhoot
		{
			Q.push(move(temp,4));
			state[move(temp,4)]=temp;
			//cout<<move(temp,4)<<" ";
		}
		
		if(((temp[1]>'1' && temp[2]=='0')||(temp[1]<'2' && temp[2]=='1')) && state.find(move(temp,5))==state.end() && move(temp,5)!="N")     //2 pari
		{
			Q.push(move(temp,5));
			state[move(temp,5)]=temp;
			//cout<<move(temp,5)<<" ";
		}
	}
	while(state[goal]!=goal)
	{
		cout<<goal<<endl;
		goal=state[goal];
		//cout<<state[goal]<<endl;
	}
}
