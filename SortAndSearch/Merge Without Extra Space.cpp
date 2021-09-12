// O(1) space . O(n1 * n2) time
void merge(int arr1[], int arr2[], int n1, int n2) {
	   
	    for( int i=n2-1; i >= 0; --i) // second array
	    {
	        int last = arr1[n1-1];
	        int j=n1-2;
	        for( ; j>=0 && arr1[j]>arr2[i]; --j)
	        {
	            arr1[j+1] = arr1[j];
	        }
	        if(last>arr2[i] || j!=n1-2)
	        {
	            arr1[j+1] = arr2[i];
	            arr2[i] = last;
	        }
	    }
	}
// O(1) space , O(n+m) time
void merge(int arr1[], int arr2[], int n1, int n2) {
	   int gap = (n1+n2+1) / 2;
	   int i;
	   int j;
	   while(gap >= 1)
	   {
	       for(i=0; (i+gap)<n1; ++i)
	       {
	           if (arr1[i] > arr1[i + gap])
	            swap(arr1[i] , arr1[i+gap]);
	       }
	       for(j = gap>n1 ? gap-n1 : 0; j<n2 && i<n1; ++j , ++i)
	       {
	           if(arr2[j] < arr1[i])
	            swap( arr2[j] , arr1[i] );
	       }
	       if(j<n2)
	       {
	           for( j=0; j+gap<n2; ++j)
	           {
	               if (arr2[j] > arr2[ j+ gap])
	               swap(arr2[j] , arr2[j+gap]);
	           }
	       }
	       if(gap<=1)
	        break;
	       gap = (gap)/2 + (gap%2);
	   }
	}
