O(nlogn) time 
// O(1) space 
bool findPair(int arr[], int n, int k){
    sort(arr, arr+n);
    int s = 0;
    int e = 1;
    while(s<n && e<n)
    {
        if( s!=e && (arr[s]-arr[e]==k || arr[e]-arr[s]==k) )
        {
            return true;
        }
        else if(arr[e]-arr[s] < k)
            ++e;
        else
            ++s;
    }
    return false;
}
