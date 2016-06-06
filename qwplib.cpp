#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> q;

extern "C" {
	__declspec(dllexport) void add(int a)
	{
		q.push_back(a);
	}

	__declspec(dllexport) void del()
	{
		if (q.size()) {
			std::sort(q.begin(), q.end());
			q.erase(q.begin());
		}
		else throw "ERROR: queue is empty!\n";
	}

	__declspec(dllexport) int get()
	{
		if (q.size()) {
			std::sort(q.begin(), q.end());
			return q[0];
		}
		else throw "ERROR: queue is empty!\n";
	}
}