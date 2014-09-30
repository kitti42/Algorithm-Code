#include<iostream>
#include<map>
#include<queue>
using namespace std;


pair<int,int> convert(int maze[3][3],int state)
{
	pair<int,int> pos;
	for(int i=2;i>=0;i--)
		for(int j=2;j>=0;j--)
		{
			maze[i][j]=state%10;
			state=state/10;
			if(maze[i][j]==9)
				pos=make_pair(i,j);	
		}
	return pos;
}

int build_state(int maze[3][3])
{
	int state=0;
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
			state=state*10+maze[i][j];
	return state;
}


inline int move_up(int state)
{
	int maze[3][3];
	pair<int,int> pos=convert(maze,state);
	if(pos.first==0)
		return 0;
	else
		swap(maze[pos.first][pos.second],maze[pos.first-1][pos.second]);
	return build_state(maze);
}

inline int move_down(int state)
{
	int maze[3][3];
	pair<int,int> pos=convert(maze,state);
	if(pos.first==2)
		return 0;
	else
		swap(maze[pos.first][pos.second],maze[pos.first+1][pos.second]);
	return build_state(maze);
}

inline int move_left(int state)
{
	int maze[3][3];
	pair<int,int> pos=convert(maze,state);
	if(pos.second==0)
		return 0;
	else
		swap(maze[pos.first][pos.second],maze[pos.first][pos.second-1]);
	return build_state(maze);
}

inline int move_right(int state)
{
	int maze[3][3];
	pair<int,int> pos=convert(maze,state);
	if(pos.second==2)
		return 0;
	else
		swap(maze[pos.first][pos.second],maze[pos.first][pos.second+1]);
	return build_state(maze);
}

int main()
{
	map<int,int > state;
	int input_state=817456293;
	//cin>>input_state;
	
	state[input_state]=input_state;
	//state[0]=0;
	int goal=912345678;
	
	queue<int> Q;
	
	Q.push(input_state);
	while(!Q.empty())
	{
		int current_state=Q.front();
		//cout<<"Current State" <<current_state<<endl;
		//cout<<"UP = "<<move_up(current_state)<<endl;
		//cout<<"Down = "<<move_down(current_state)<<endl;
		//cout<<"Left = "<<move_left(current_state)<<endl;
		//cout<<"Right = "<<move_right(current_state)<<endl;
		//cin.get();
		Q.pop();
		if(current_state==goal)
			break;
		if(state.find(move_up(current_state))==state.end() && move_up(current_state)!=0)
		{
		//	cout<<" U";
			state[move_up(current_state)]=current_state;
			Q.push(move_up(current_state));	
		}
		if(state.find(move_down(current_state))==state.end() && move_down(current_state)!=0)
		{
		//	cout<<"D";
			state[move_down(current_state)]=current_state;
			Q.push(move_down(current_state));
		}
		if(state.find(move_left(current_state))==state.end() && move_left(current_state)!=0)
		{
		//	cout<<"L";
			state[move_left(current_state)]=current_state;
			Q.push(move_left(current_state));
		}
		if(state.find(move_right(current_state))==state.end() && move_right(current_state)!=0)
		{	
		 //	cout<<"R";
			state[move_right(current_state)]=current_state;
			Q.push(move_right(current_state));
		}
	}		
	int count=0;
	while(state[goal]!=goal)
	{
		count++;
		cout<<goal<<" ";
		goal=state[goal];
	}
	cout<<count<<endl;
}


