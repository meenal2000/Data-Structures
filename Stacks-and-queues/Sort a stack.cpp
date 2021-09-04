// time - O(n2)
// space - O(n)
void insert(stack<int> &s, int top)
{
    if(s.size()==0 || top>=s.top())
    {
        s.push(top);
        return;
    }
    int tmp = s.top();
    s.pop();
    insert( s , top);
    s.push(tmp);
}
void SortedStack :: sort()
{
   if(s.size()==0)
   {
       return;
   }
   
   int top = s.top();
   s.pop();
   sort();
   
   insert(s,top);    
   
}
