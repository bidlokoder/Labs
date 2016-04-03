#include <iostream>
#include <string>
using namespace std;

class move
{
    move* Next;
    string Data;
public:
    move(): Next(nullptr), Data("") {};
    void push(string data);
    void get();
    void pop();
    ~move(){if(Next!= nullptr) delete Next;}
}Move;

void move::push(string data)
{
    if(Next== nullptr)
        if(Data!="")
            Next = new move();
    else
    {
        Data = data;
        return;
    }
    Next->push(Data);
    Data = data;
}

void move::get()
{
    if(Next== nullptr)
    {
        cout << Data << endl;
        return;
    }
    Next->get();
}

void move::pop()
{
    if(Next == nullptr)
    {
        Data = "";
        return;
    }
    else
        Next->pop();
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
            Move.push(line);
        }
        else if(line=="get")
            Move.get();
        else if(line=="del")
            Move.pop();
        else
            return 1;

    }

    return 0;
}
