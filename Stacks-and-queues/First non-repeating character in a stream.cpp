// O(n*26) time 
// O(26) space
string FirstNonRepeating(string A){
		    vector<char> v;
		    vector<int> vis(26,0);
		    int n = A.size();
		    string ans = "";
		    for(int i=0; i<n; ++i)
		    {
		          if(!vis[A[i] - 'a'])
    	          {
    	              v.push_back(A[i]);
    	          } 
    	          vis[A[i] - 'a']++;
    	          int m = v.size();
    	          bool found = 0;
    	          for(int i=0; i<m; ++i)
    	          {
    	              if(vis[v[i]-'a']==1)
    	              {
    	                  found = 1;
    	                  ans += v[i];
    	                  break;
    	              }
    	          }
    	          if(!found)
		            ans += '#';
		    }
		    return ans;
		}
