#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <stack>
#include <utility>
#include <queue>
#include <unordered_map>
#include <math.h>
#include <numeric>
using namespace std;

//implementing stack using array

class stk{
    int *arr;
    int size;
    int top;
    public:
    stk(int size)
    {
        arr=new int[size];
        top=-1;
        this->size=size;
    }
    void push_num(int num);
    int pop_num();
    void display();
};

//push
void stk::push_num(int num)
{
    if(top==size-1)
    {
        cout<<"Stack overflow\n";
    }
    else{
        top++;
        arr[top]=num;
    }
}
//pop
int stk::pop_num()
{
    int x=-1;
    if(top==-1)
    {
        cout<<"Stack Underflow\n";
    }
    else{
        x=arr[top];
        top--;
    }
    return x;
}

//display
void stk::display()
{
    for(int i=top;i>=0;i--)
    {
        cout<<arr[i]<<" ";
    }
}
int main()
{
    stk s(5);
    s.push_num(5);
    s.push_num(4);
    s.push_num(3);
    s.push_num(2);
    s.push_num(1);
    s.display();

}