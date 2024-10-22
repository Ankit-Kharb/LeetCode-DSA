/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int partitionArr(vector<long long>&num, int l, int r)
    {
        if(l==r)
            return l;

        int pivot = l-1;
        int maxEleIndex = r;

        for(int i=l;i<r;i++)
        {
            if(num[i] < num[maxEleIndex])
            {
                pivot++;
                swap(num[i], num[pivot]);
            }
        }
        pivot++;
        swap(num[pivot], num[maxEleIndex]);
        return pivot;
    }
    long long quickSelect(vector<long long>&num, int l, int r, int k)
    {
       // cout<<l<<" "<<r<<" "<<k<<endl;
        int partition = partitionArr(num, l, r);
        //cout<<l<<" "<<r<<" "<<k<<" "<<partition<<endl;
        if(partition == k)
            return num[k];
        if(partition>k)
        {
            return quickSelect(num, l, partition-1, k);
        }
        return quickSelect(num, partition+1, r, k);
    }
    long long kthLargestLevelSum(TreeNode* root, int k) 
    {
        vector<long long>levelSum;

        queue<TreeNode *> myQueue;
        myQueue.push(root);

        while(!myQueue.empty())
        {
            int size = myQueue.size();

            long long currLevelSum = 0;
            while(size--)
            {
                TreeNode* node = myQueue.front();
                myQueue.pop();
                currLevelSum += (long long)node->val;
                if(node->left)
                    myQueue.push(node->left);
                if(node->right)
                    myQueue.push(node->right);
            }
            levelSum.push_back(currLevelSum);
        }

        int n = levelSum.size();
        if(k>n)
        return -1;

        int reqIndex = n-k;
        return quickSelect(levelSum, 0, n-1, reqIndex);
    }
};

