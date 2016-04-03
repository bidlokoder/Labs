#include <iostream>
#include <string>
using namespace std;

class stack
{
    stack* Next;
    string Data;
public:
    stack(): Next(nullptr), Data("") {};
    void push(string data);
    void get();
    string pop();
    ~stack(){if(Next!= nullptr) delete Next;}
}Stack;

void stack::push(string data)
{
    if(Next== nullptr)
        if(Data!="")
            Next = new stack();
        else
        {
            Data = data;
            return;
        }
    Next->push(Data);
    Data = data;
}

void stack::get()
{
    cout << Data << endl;
}

string stack::pop()
{
    string temp = Data;
    if(Next!= nullptr)
        Data = Next->pop();
    else
        Data = "";
    return temp;
}



int main()
{
    size_t n;       //Number of commands
    string line;    //Command name
    cin >> n;
    for (size_t i = 0; i < n; i++)
    {
        cin >> line;
        if(line=="add")
        {
            cin >> line;
            Stack.push(line);
        }
        else if(line=="get")
            Stack.get();
        else if(line=="del")
            Stack.pop();
        else
            return 1;

    }

    return 0;
}
