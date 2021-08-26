// heaps O(Nodes)
bool isHeap(struct Node * tree)
    {
        queue<Node *> q;
        q.push(tree);
        bool nullish = false;
        while(!q.empty())
        {
            Node *curr = q.front();
            q.pop();
            if(curr->left)
            {
                if(nullish || curr->left->data >= curr->data)
                    return false;
                q.push(curr->left);
            }
            else
                nullish = true;
            if(curr->right)
            {
                if(nullish || curr->right->data >= curr->data)
                    return false;
                q.push(curr->right);
            }
            else
                nullish = true;
        }
        return true;
    }
