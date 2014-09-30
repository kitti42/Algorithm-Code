#include<iostream>
using namespace std;


template<class T> class vector
{
	private:
		T *p;
		size_t sz;
		size_t cap;
	public:

	size_t capacity()
	{
		return cap;
	}
	
	size_t size()
	{
	return sz;
	}
	
	void resize(size_t newsize)
	{
		if(newsize<capacity())
		sz=newsize;
		else
		{
		while(newsize<=capacity())
		{
			cap=cap*2;
		}
		T * temp=new T[cap];
		for(int i=0;i<sz;i++)
		temp[i]=p[i];

		delete[] p;
		p=temp;
		sz=newsize;
		}
 	}


	vector()
	{
		p=NULL;
		sz=0;
		cap=1;
	}
	vector(size_t size)
	{
		cap=1;
		sz=0;
		this->resize(size);
	}

	vector(size_t size,const T value)
	{
		sz=0;
		cap=1;
		this->resize(size);
		for(int i=0;i<size;i++)
		p[i]=value;
	}

	T & operator [](size_t pos)
	{
		return p[pos];
	}

	class overflow{};

	T & at(size_t pos)
	{
		if(pos<sz)
		return p[pos];	
		else
		throw overflow();
	}
	T back()
	{
		return p[sz-1];
	}
	void push_back(const T &value)
	{
		resize(sz+1);
		p[sz-1]=value;
	}
	void pop_back()
	{
		resize(sz-1);
	}
};

int main()
{
	cout<<"Hi...";
	vector<int> a;
	a.push_back(5);
	cout<<a.size();
	for(int i=0;i<a.size();i++)
	cout<<a[i];
}
