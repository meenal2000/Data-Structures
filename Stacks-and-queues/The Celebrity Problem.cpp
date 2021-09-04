// 3 solutions
// 1st - Using in[] and out[] array -> O(n2) time , O(n) space
// 2nd - Using stack -> O(n) space , O(n) time
// 3rd - Using for loop and basic logic -> O(n) time , O(1) space
int celebrity(vector<vector<int> >& M, int n) 
    {
        int c = 0;
        for(int i=1; i<n; ++i)
        {
            if(M[c][i])
            {
                c = i;
            }
        }
        for(int i=0; i<n; ++i)
        {
            if(i!=c && (M[c][i]==1 || M[i][c]==0) )
            {
                return -1;
            }
        }
        return c;
    }
