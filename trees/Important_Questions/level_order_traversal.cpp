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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int> > level_order;
        vector<int> level;

        q.push(root);
        while(!q.empty()){
        	int size = q.size();
        	while(size--){
        		TreeNode* curr = q.front();
        		q.pop(); 
        		level.push_back(curr->val);
        		if(curr->left)
        			q.push(curr->left);
        		if(curr->right)
        			q.push(curr->right);
        	}
        	level_order.push_back(level);
        	level.clear();
        }
        return level_order;
    }
};