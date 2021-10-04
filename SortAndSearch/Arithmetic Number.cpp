int inSequence(int A, int B, int C){
        if(C==0)
            return A==B;
        int n = ( (B-A) / C )+1;
        if(n <= 0)
            return 0;
        int val = A + ( (n-1)*C );
        return val == B;
    }
