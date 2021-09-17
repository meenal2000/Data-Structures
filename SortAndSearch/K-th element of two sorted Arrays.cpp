int kthElement(int arr1[], int arr2[], int n1, int n2, int k)
    {
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
	   if(k<=n1)
	    return arr1[k-1];
	   return arr2[k-n1-1];
    }
// another approach
int kthElement(int arr1[], int arr2[], int n1, int n2, int k_req)
    {
	   int i = 0;
	   int j = 0;
	   int k = 0;
	   while(i<n1 && j<n2)
	   {
	       if(arr1[i] < arr2[j])
	       {
	           ++k;
	           if(k==k_req)
	            return arr1[i];
	           ++i;
	       }
	       else
	       {
	           ++k;
	           if(k==k_req)
	            return arr2[j];
	           ++j;
	       }
	   }
	   while(i < n1)
       {
           ++k;
           if(k==k_req)
            return arr1[i];
           ++i;
       }
       while(j < n2)
       {
           ++k;
           if(k==k_req)
            return arr2[j];
           ++j;
       }
    }
