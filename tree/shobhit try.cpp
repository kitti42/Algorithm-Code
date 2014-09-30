#include<iostream>
using namespace std;



class a
{
	public:
		a()
		{
			cout<<"A constructor";
		}
		~a()
		{
			cout<<"A destructor";
		}
};

class b
{
	public:
		b()
		{
			cout<<"B constructor";
			throw 5;
			cout<<"hiee";
		}
		~b()
		{
			cout<<"B destructor";
		}
};

void func()
{
	a ob;
	b ob2;
}
int main()
{
	try
	{
	
	func();
	}catch(...)

{
}}
