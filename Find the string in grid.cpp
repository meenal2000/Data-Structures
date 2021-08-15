// O(n*m* (length of string) )
vector<int> x{-1,-1,-1,1,1,1,0,0};
    vector<int> y{-1,0,1,-1,0,1,-1,1};
    bool solve(vector<vector<char>>& board,int i,int j,int r,int c, string &word)
    {
        if(board[i][j] != word[0])
            return false;
        int len = word.size();
        for(int dir=0; dir<8; ++dir)
        {
            int rd = x[dir]+i;
            int cd = y[dir]+j;
            int k;
            for( k =1 ; k<len; ++k)
            {
                if(rd<0 || rd>=r || cd<0 || cd>=c || board[rd][cd] != word[k])
                    break;
                rd += x[dir];
                cd += y[dir];
            }
            if(k==len)
                return true;
        }
        return false;
    }
	vector<vector<int>> searchWord(vector<vector<char>>board, string word){
	    int rows = board.size();
        int cols = board[0].size();
        vector<vector<int> > ans;
        for(int i=0; i<rows; ++i)
        {
            for(int j=0; j<cols; ++j)
            {
                if(solve(board , i , j, rows, cols, word))
                {
                    //cout << i << j << endl;
                    vector<int> v(2);
                    v[0] = i;
                    v[1] = j;
                    ans.push_back(v);
                }
            }
        }
        return ans;
	}
