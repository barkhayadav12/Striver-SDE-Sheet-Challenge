void MyQueue ::push(int x)
{
    // Your Code
    if (rear == 100004)
    {
        return;
    }
    arr[rear] = x;
    rear++;
}

// Function to pop an element from queue and return that element.
int MyQueue ::pop()
{
    // Your Code
    if (front == rear)
    {
        return -1;
    }
    return arr[front++];
}