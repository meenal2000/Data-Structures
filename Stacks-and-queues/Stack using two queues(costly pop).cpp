void QueueStack :: push(int x)
{
    q1.push(x);
}

//Function to pop an element from stack using two queues. 
int QueueStack :: pop()
{
    if(!q1.size())
        return -1;
    int n = q1.size();
    for(int i=1; i<n; ++i)
    {
        int tmp = q1.front();
        q1.pop();
        q2.push(tmp);
    }
    int tmp = q1.front();
    q1.pop();
    swap(q1,q2);
    return tmp;
}
