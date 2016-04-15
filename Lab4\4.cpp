#include <cstdio>
#include <cmath>
#include <tchar.h>
#include <cstdlib>
#include <iostream>
#include <stdexcept>
using namespace std;
class Number
{
private:
	static const int hi = 1000;
	int low;
public:
	Number()
	{
		low = 0;
	}
	Number(int n)
	{
		if (n > hi) throw runtime_error("Out of borders");
		low = n;
	}
	Number(const Number &n)
	{
		low = n.low;
	}
	Number& operator = (Number &n)
	{
		low = n.low;
		return(*this);
	}
	Number operator + (const Number &n)
	{
		return Number(low + n.low);
	}
	Number operator * (const Number &n)
	{
		return Number(low * n.low);
	}
	Number operator = (const Number &n)
	{
		low = n.low;
	}
	friend ostream & operator<< (ostream &, const Number &);
	friend istream & operator>> (istream &, Number &);
};

class multiplexException :  public exception {};

class matrix
{
	Number** T;
	size_t M;
	size_t N;
public:
	matrix() = delete;
	matrix(size_t m, size_t n) : T(NULL), M(m), N(n)  
	{
		T = new Number*[M];
		for(size_t i=0; i<M; i++)
			T[i] = new Number[N];
	};
	matrix(const matrix& o): T(NULL), M(o.M), N(o.N) 
	{

		T = new Number*[M];
		for(size_t i=0; i<M; i++)
		{
			T[i] = new Number[N];
			copy(o.T[i], o.T[i]+ N*sizeof(Number), T[i]);
		}
	};
	size_t m()
	{
		return M;
	};
	size_t n()
	{
		return N;
	};
	matrix rotX(double a)
	{
		matrix r(3, 3);
		r(0, 0) = Number(1);
		r(1, 1) = cos(a);
		r(1, 2) = -sin(a);
		r(2, 1) = sin(a);
		r(2, 2) = cos(a);
		return *this*r;
	}
	matrix rotY(double a)
	{
		matrix r(3, 3);
		r(0, 0) = cos(a);
		r(0, 2) = sin(a);
		r(1, 1) = Number(1);
		r(2, 0) = -sin(a);
		r(2, 2) = cos(a);
		return *this*r;
	}
	matrix rotZ(double a)
	{
		matrix r(3, 3);
		r(0, 0) = cos(a);
		r(0, 1) = -sin(a);
		r(1, 0) = sin(a);
		r(1, 1) = cos(a);
		r(2, 2) = Number(1);
		return *this*r;
	}
	
	const Number& operator ()(size_t i, size_t j) const
	{
		if(NULL)
			throw out_of_range("Matrix wasn't initialised");
		if(i>M)
			throw out_of_range("Index \"i\" is out of range");
		if(j>N)
			throw out_of_range("Index \"j\" is out of range");
		
		return T[i][j];
	};	
	
	Number& operator ()(size_t i, size_t j)
	{
		if(NULL)
			throw out_of_range("Matrix wasn't initialised");
		if(i>M)
			throw out_of_range("Index \"i\" is out of range");
		if(j>N)
			throw out_of_range("Index \"j\" is out of range");
		
		return T[i][j];
	};
	
	matrix operator *(const matrix& o) const
	{
		if(N!=o.M)
			throw multiplexException();
		
		matrix x(M, o.N);
		for(size_t i=0; i<M; i++)
			for(size_t j=0; j<o.N; j++)
				for(size_t k=0; k<N; k++)
					x(i, j) = x(i, j) + (T[i][k]*o(k,j));
		return x;
	};
	
	matrix operator *(const Number& o) const
	{
		matrix x(*this);
		for(size_t i=0; i<x.M; i++)
			for(size_t j=0; j<x.N; j++)
				x(i, j)= x(i, j) * o;
		return x;
	};
	
	matrix& operator =(const matrix& o)
	{
		if(T!=NULL)
		{
			for(size_t i=0; i<N; i++)
				delete[] T[i];
			delete[] T;
		}
		N = o.N;
		M = o.M;
		T = new Number*[M];
		for(size_t i=0; i<M; i++)
		{
			T[i] = new Number[N];
			copy(o.T[i], o.T[i]+ N*sizeof(Number), T[i]);
		}
		return *this;
	};
	~matrix()
	{
		for(size_t i=0; i<M; i++)
			delete[] T[i];
		delete[] T;
	};
	
};

ostream& operator<<(ostream &out, const Number &n)
{
	out << "(" << n.low << ")";
	return out;
}
istream& operator>> (istream &in, Number &n)
{
	in >> n.low;
	return in;
}
int main()
{
	/*Number a(10);
	cout << "a= " << a;
	cout << "Sum: " << a + a << endl;
	cout << "Mul: " << a * a << endl;*/
	matrix A(1, 2);
	A(0, 0) = Number(1);
	A(0, 1) = Number(2);
	
	matrix B(2, 1);
	B(0, 0) = Number(3);
	B(1, 0) = Number(4);
	
	matrix D(1, 3);
	D(0, 0) = Number(5);
	D(0, 1) = Number(6);
	D(0, 2) = Number(7);
	
	try
	{
	
	matrix C = B*A;
	cout << "C: " << endl 
		<< C(0, 0) << endl
		<< C(0, 1) << endl
		<< C(1, 0) << endl
		<< C(1, 1) << endl << endl;
	
	matrix F = D.rotX(3.14);
	
	cout << "F: " << endl
		<< F(0, 0) << endl
		<< F(0, 1) << endl
		<< F(0, 2) << endl;
	}
	catch(exception e)
	{
		cout << "Some error..." << endl;
	}
	system("pause");
	return 0;
}
