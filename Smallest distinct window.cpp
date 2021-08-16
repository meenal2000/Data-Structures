// Brute force
// using hashmap for maintaining the size of distinct characters and count of characters
// then, find the substrings . O(n^2)
// keep a vis array and ( current count and distinct_count)
// as soon as the curr_cnt == dist_cnt
// update ans . Space - O(N)

// Two - pointer
// O(n) time
// O(n) space for visited array
string findSubString(string str)
    {
       int n = str.size();
       vector<char> vis(256);
       int dist_count = 0;
       for(int i=0; i<n; ++i)
       {
           if(!vis[str[i]])
           {
               vis[str[i]] = 1;
               ++dist_count;
           }
       }
       int start = 0;
       int start_index = -1;
       vector<char> freq(256);
       int window_len = INT_MAX;
       int cnt = 0; // for storing all distinct characters encountered yet
       for(int j=0; j<n; ++j)
       {
           freq[str[j]]++;
           if(freq[str[j]] == 1)
                ++cnt;
           if(cnt == dist_count)
           {
               while(start < n && freq[str[start]] > 1)
               {
                   --freq[str[start]];
                   ++start;
               }
               int len = j-start+1;
               if(len < window_len)
               {
                   start_index = start;
                   window_len = len;
               }
           }
       }
       return str.substr(start_index,window_len);
    }
