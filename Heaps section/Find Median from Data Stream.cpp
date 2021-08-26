 // using insertion sort , it can be done in O(n*n) time
// optimization - O(nlogn) using two heaps

class MedianFinder {
public:
    /** initialize your data structure here. */
    priority_queue<int> pqMax; //max heap
    priority_queue<int , vector<int> , greater<int> > pqMin; //minHeap
    double median;
    MedianFinder() {
        median = 1e5 + 5;
    }
    
    void addNum(int num) {
        
        if(median == 1e5 + 5)
        {
            median = num;
            pqMax.push(num);
            return;
        }
        if(num <= median)
        {
            pqMax.push(num);
        }
        else
        {
            pqMin.push(num);
        }
        
        //cout << "n1 " << n1 << " n2 " << n2 << endl;
        int n1 = pqMax.size();
        int n2 = pqMin.size();
        if(abs(n1-n2) > 1)
        {
            if(n1 > n2)
            {
                int val = pqMax.top();
                pqMax.pop();
                pqMin.push(val);
                n1--;
                n2++;
            }
            else
            {
                int val = pqMin.top();
                pqMin.pop();
                pqMax.push(val);
                n1++;
                n2--;
            }
        }
        
        if(n1 == n2)
        {
            median = (pqMax.top() + pqMin.top()*1.0 )/2;
        }
        else if(n1 > n2)
        {
            median = pqMax.top() ;
        }
        else
        {
            median = pqMin.top() ;
        }
        return;
    }
    
    double findMedian() {
        return median;
    }
};
