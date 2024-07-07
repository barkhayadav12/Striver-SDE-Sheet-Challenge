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

class q{
    int front;
    int rear;
    int size;
    int *arr;
    public:
    q(int size)
    {
        front=-1;
        rear=-1;
        this->size=size;
        arr=new int[size];
    }
    void push_num(int num);
    int pop_num();
    void display();
};

//push

void q::push_num(int num)
{
    if(rear==size-1)
    {
        cout<<"Queue is full\n";
    }
    else{
        if(front==-1)
        {
            front++;
        }
        rear++;
        arr[rear]=num;
    }
}

//pop

int q::pop_num()
{
    int x=-1;
    if(front==-1)
    {
        cout<<"queue is empty\n";
    }
    else{
        x=arr[front];
        front++;
    }
    return x;
}

//display

void q::display()
{
    for(int i=front;i<=rear;i++)
    {
        cout<<arr[i]<<" ";
    }
}
int main()
{
    q que(5);
    que.push_num(5);
    que.display();
}