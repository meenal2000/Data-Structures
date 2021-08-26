Merge K sorted linked lists
// O( (n*k) *logk )
Node* merge2Lists(Node *l1, Node *l2)
    {
        if(!l1)
            return l2;
        if(!l2)
            return l1;
        if(l1->data <= l2->data)
        {
            l1 -> next = merge2Lists(l1->next,l2);
            return l1;
        }
        else
        {
            l2 -> next = merge2Lists(l1,l2->next);
            return l2;
        }
    }
    Node* mergeKLists(Node* arr[], int K)
    {
        int len = K;
        while(len > 1)
        {
            for(int i=0; i<(len/2); ++i)
            {
                arr[i] = merge2Lists(arr[i],arr[len-i-1]);
            }
            len = (len+1) / 2;
        }
        return arr[0];
    }
    
// using heaps
struct compare {
    bool operator()( struct Node* a, struct Node* b)
    {
        return a->data > b->data;
    }
};
    Node* mergeKLists(Node* arr[], int K)
    {
        if(!K)
            return NULL;
        priority_queue< Node* , vector<Node*> , compare > pq;
        for(int i=0; i<K; ++i)
        {
            if(arr[i])
                pq.push(arr[i]);
        }
        Node* dummy = new Node(0);
        Node* tail = dummy;
        while(!pq.empty())
        {
            Node *curr = pq.top();
            pq.pop();
            tail -> next = curr;
            tail = tail -> next;
            if(curr->next)
            {
                pq.push(curr->next);
            }
        }
        tail -> next = NULL;
        return dummy->next;
    }
    
};
