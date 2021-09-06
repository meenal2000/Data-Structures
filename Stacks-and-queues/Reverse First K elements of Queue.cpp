void solve(queue<int> &q, int k , int n)
{
    if(q.size() == n-k)
        return;
    int ele = q.front();
    q.pop();
    solve(q,k,n);
    q.push(ele);
}
queue<int> modifyQueue(queue<int> q, int k)
{
    int n = q.size();
    solve(q , k , n);
    for(int i=0; i<(n-k); ++i)
    {
        int tmp = q.front();
        q.pop();
        q.push(tmp);
    }
    return q;
}
