// Author - Meenal gupta
#include <bits/stdc++.h>
using namespace std;
#define trace1(x)                cerr<<#x<<": "<<x<<"\n";
#define trace2(x, y)             cerr<<#x<<": "<<x<<" | "<<#y<<": "<<y<<"\n";
#define trace3(x, y, z)          cerr<<#x<<":" <<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<"\n";
#define trace4(a, b, c, d)       cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<"\n";
#define trace5(a, b, c, d, e)    cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<"\n";
#define trace6(a, b, c, d, e, f) cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<" | "<<#f<<": "<<f<<"\n";
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
// #define N 1e8+5
#define ll long long int

int main()
{
    IOS
    long long int n , m ,mx;
    cin >> n >> m;
    vector<ll> ht(n);
    mx = -1;
    for(int i=0; i<n; ++i)
    {
        cin >> ht[i];
        mx = max(mx , ht[i]);
    }
    long long int s = 0 , e = mx, mid,cnt,ans;
    while(s <= e)
    {
        mid = (s+e)/2;
        cnt = 0;
        for(int i=0; i<n; ++i)
        {
            if(ht[i] > mid)
            {
                cnt += ht[i]-mid;
            }
        }
        if(cnt >= m)
        {
            ans = mid;
            s = mid+1;
        }
        else
        {
            e= mid-1;
        }
       // trace1(ans)
    }
    cout << ans << "\n";
    return 0;
}
