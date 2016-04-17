#include<iostream>
using namespace std;

void direct(int i, int* a, size_t n)
{
	for(size_t j=0; j<n; j++)
		if(a[j]==i)
		{
			cout << j;
			direct(j, a, n);
		}
}


void reverse(int i, int* a, size_t n)
{
	for(size_t j=0; j<n; j++)
		if(a[j]==i)
		{
			reverse(j, a, n);
		}
	if(i!=-1) cout << i;	
}

void symetric(int i, int* a, size_t n)
{
	int x = 0;
	for(size_t j=0; j<n; j++)
		if(a[j]==i)
		{
			symetric(j, a, n);
			if((!x)&&(i!=-1)) cout << i;
			x++;
		}
	if(x==0)
	{
		cout << i;	
	}
}


int main()
{
	size_t n;
	cin >> n;
	int* tree = new int[n];
	for(size_t i=0; i<n; i++)
		cin >> tree[i];
		
	direct(-1, tree, n);
	cout << endl;
	
	reverse(-1, tree, n);
	cout << endl;
	
	symetric(-1, tree, n);
	cout << endl;

	delete[] tree;
	return 0;
}

