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
                //cout<<"Hello "<<node->val<<" "<<currLevelSum<<endl;
            }
            //cout<<"Hello "<<endl;
            levelSum.push_back(currLevelSum);
        }
        sort(levelSum.begin(), levelSum.end(), greater<long long>());
        //cout<<"Hello www "<<k-1<<" "<<levelSum[k-1]<<endl;
        if(k>levelSum.size())
        return -1;

        return levelSum[k-1];
    }
};