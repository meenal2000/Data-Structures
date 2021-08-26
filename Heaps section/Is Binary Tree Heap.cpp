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
// using recursion O(3*n)
int countNodes(Node *tree)
    {
        if(!tree)
            return 0;
        return 1 +countNodes(tree->left)+countNodes(tree->right);
    }
    bool isCompTree(Node *tree, int i, int n)
    {
        if(!tree)
            return 1;
        if(i >= n)
            return false;
        bool left = isCompTree(tree->left, 2*i+1, n);
        bool right = isCompTree(tree->right, 2*i+2, n);
        return (left && right);
    }
    bool isHeapy(Node *tree)
    {
        if(!tree->left && !tree->right)
            return true;
        if(!tree->right)
        {
            return tree->data >= tree->left->data;
        }
        else
        {
            bool ok = (tree->data >= tree->left->data) && (tree->data >= tree->right->data);
            return isHeapy(tree->left) && isHeapy(tree->right) && ok;
        }
    }
    bool isHeap(struct Node * tree)
    {
        int n = countNodes(tree);
        if( isCompTree(tree,0,n) && isHeapy(tree) )
            return true;
        return false;
    }
