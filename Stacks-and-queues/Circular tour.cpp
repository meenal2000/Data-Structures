int tour(petrolPump p[],int n)
    {
       int s = 0;
       int e = 1;
       int curr = p[s].petrol - p[s].distance;
       while(curr<0 || s!=e)
       {
           while(curr < 0 && s!=e)
           {
               curr -= p[s].petrol - p[s].distance;
               s = (s+1)%n;
               if(s==0)
                 return -1;
           }
           curr += p[e].petrol - p[e].distance;
           e = (e+1)%n;
       }
       
       return s;
    }
