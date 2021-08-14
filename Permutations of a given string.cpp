void solve(string s, int i,int n,vector<string> &ans)
	    {
	        if(i>=n)
	        {
	            ans.push_back(s);
	            return;
	        }
	        for(int j=i; j<n; ++j)
	        {
	            swap(s[i],s[j]);
	            solve(s,i+1,n,ans);
	            swap(s[i],s[j]);
	        }
	    }
		vector<string>find_permutation(string S)
		{
		    vector<string> ans;
		    solve(S,0,S.size(),ans);
		    sort(ans.begin(),ans.end());
		    return ans;
		}
