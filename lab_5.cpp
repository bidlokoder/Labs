include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class file {
	string name;
	string data;
public:
	file();
	~file() {};
	file(string, string);
	string getname();
	void setname(string);
	string getdata();
	void setdata(string);
};

file::file() { name = "default"; data = "empty"; }
file::file(string fname, string fdata) { name = fname; data = fdata; }
string file::getname() { return name; }
void file::setname(string fname) { name = fname; }
string file::getdata() { return data; }
void file::setdata(string fdata) { data = fdata; }


class Directory {
	string name;
	vector<Directory> dir;
	vector<file> fl;
public:
	Directory();
	~Directory();
	Directory(string);
	void push(file&);
	void delete(string);
	void Dpush(Directory&);
	void Ddelete(string);
	friend ostream &operator<<(ostream&, Directory);
	void Dprint();
	void print();
	string getName();
	void Fsearch(string, Directory&);
	void Directory::Ddelete(Directory&);

};

string Directory::getName() {
	return name;
}

Directory::Directory() {
	name = "default";
}
Directory::~Directory() {
	fl.clear();
}
Directory::Directory(string dname) {
	name = dname;
}
ostream &operator<<(ostream &stream, Directory obj) {
	stream << obj.name;
	return stream;
}
void Directory::print() {
	for (file k : fl) {
		cout << k.getname();
	}
}
void Directory::push(file &file) {
	fl.push_back(file);
}
void Directory::delete(string fname) {
	int i = 0;
	for (file k : fl) {
		if (k.getname() == fname) {
			fl.erase(fl.begin() + i);
			break;
		}
		i++;
	}
}
void Directory::Ddelete(Directory& direct) {
	fl.clear();
	for (Directory k : dir) {
		k.Ddelete(k);
	}
	dir.clear();
}
void Directory::Ddelete(string dname) {
	for (Directory k : dir) {
		if (k.getName() == dname) {
			k.Ddelete(k);
			break;
		}
	}
}
void Directory::Dprint() {

	cout << "Dirs: " << endl;
	for (Directory k : dir) {
		cout << k.getName() << endl;
	}
	cout << "Files: " << endl;
	for (file k : fl) {
		cout << k.getname() << endl;
	}
}
void Directory::Dpush(Directory &directory) {
	dir.push_back(directory);
}
vector<file> list;

void Directory::Fsearch(string fname, Directory& direct) {

	for (file k : fl) {
		if (k.getname() == fname)
			list.push_back(k);
	}

	for (Directory k : dir) {
		k.searchF(fname, k);
	}
}


int main()
{
    return 0;
}

