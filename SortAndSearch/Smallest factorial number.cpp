int TrailingZeros(int num)
{
    int c = 0;
    for(int i=5; (num/i) >= 1; i*=5)
    {
        c += (num/i);
    }
    return c;
}
class Solution
{
    public:
    int findNum(int n)
    {
        int low = 0;
        int high = n*5;
        int cnt = 0;
        while(low <high)
        {
            int mid = (low+high)/2;
            cnt = TrailingZeros(mid);
            if(cnt >= n)
            {
                high = mid;
            }
            else
            {
                low = mid+1;
            }
        }
        return high;
    }
