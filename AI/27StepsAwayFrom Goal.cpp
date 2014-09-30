#include<iostream>
#include<map>
#include<queue>
#include<vector>
#include<cmath>
using namespace std;
int count=0,depth;
//-----------------------------------------------------------------------

//------structure of a state that has cost ie. depth ------------
typedef struct N                        
{ 
	int value;
	int cost;
}node;
//---------------------------------------------------------------------

//converts the state(int) in 2-D array maze and returns the position of blank
pair<int,int> convert(int maze[3][3],int temp)             
{
	pair<int,int> pos;
	for(int i=2;i>=0;i--)
		for(int j=2;j>=0;j--)
		{
			maze[i][j]=temp%10;
			temp=temp/10;
			if(maze[i][j]==9)
				pos=make_pair(i,j);	
		}
	return pos;
}
//---------------------------------------------------------------------

//--------gives state in integer format from 2-D array-----------------
int build_state(int maze[3][3])
{
	int state=0;
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
			state=state*10+maze[i][j];
	return state;
}
//----------------------------------------------------------------------

//-----returns the state if possible by moving up,down,left,right-------
inline int move_up(node* state)
{
	int maze[3][3];
	pair<int,int> pos=convert(maze,state->value);
	if(pos.first==0)
		return 0;
	else
		swap(maze[pos.first][pos.second],maze[pos.first-1][pos.second]);
	return build_state(maze);
}

inline int move_down(node* state)
{
	int maze[3][3];
	pair<int,int> pos=convert(maze,state->value);
	if(pos.first==2)
		return 0;
	else
		swap(maze[pos.first][pos.second],maze[pos.first+1][pos.second]);
	return build_state(maze);
}

inline int move_left(node* state)
{
	int maze[3][3];
	pair<int,int> pos=convert(maze,state->value);
	if(pos.second==0)
		return 0;
	else
		swap(maze[pos.first][pos.second],maze[pos.first][pos.second-1]);
	return build_state(maze);
}

inline int move_right(node* state)
{
	int maze[3][3];
	pair<int,int> pos=convert(maze,state->value);
	if(pos.second==2)
		return 0;
	else
		swap(maze[pos.first][pos.second],maze[pos.first][pos.second+1]);
	return build_state(maze);
}
//--------------------------------------------------------------------------

int main()
{
	cin>>depth;
	map<int,pair<int,char> > state;
	int input_state=912345678;
	//cin>>input_state;
	
	state[input_state]=make_pair(input_state,'I');
	//state[0].first=0
	queue <node *> Q;
	
	node * input=new node;
	input->value=input_state;
	input->cost=0;
	Q.push(input);
	while(!Q.empty())
	{
		node *current_state=Q.front();
		
		Q.pop();
		if(current_state->cost==depth)
			count++;
		if(current_state->cost>depth)
			break;
			
		if(state.find(move_up(current_state))==state.end() && move_up(current_state)!=0)
		{
			state[move_up(current_state)]=make_pair(current_state->value,'U');
			node * temp=new node;
			temp->value=move_up(current_state);
			temp->cost=current_state->cost+1;
			Q.push(temp);	
		}
		if(state.find(move_down(current_state))==state.end() && move_down(current_state)!=0)
		{
			state[move_down(current_state)]=make_pair(current_state->value,'D');
			node * temp=new node;
			temp->value=move_down(current_state);
			temp->cost=current_state->cost+1;
			Q.push(temp);
		}
		if(state.find(move_left(current_state))==state.end() && move_left(current_state)!=0)
		{
			state[move_left(current_state)]=make_pair(current_state->value,'L');
			node * temp=new node;
			temp->value=move_left(current_state);
			temp->cost=current_state->cost+1;
			Q.push(temp);
		}
		if(state.find(move_right(current_state))==state.end() && move_right(current_state)!=0)
		{	
			state[move_right(current_state)]=make_pair(current_state->value,'R');
			node * temp=new node;
			temp->value=move_right(current_state);
			temp->cost=current_state->cost+1;
			Q.push(temp);
		}
	}	
		
	cout<<count<<endl;
}


