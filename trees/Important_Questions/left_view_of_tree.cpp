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
    vector<int> leftSideView(TreeNode* root) {
        vector<int> left_view;
        queue<TreeNode*> q;
        int level = 0;
        
        q.push(root);
        while(!q.empty()){
        	int size = q.size();
            bool insert = true;
        	while(size--){
        		TreeNode* curr = q.front();
        		q.pop();
        		if(insert){
        			left_view.push_back(curr->val);
                    insert = false;
                }
        		if(curr->left)
        			q.push(curr->left);
        		if(curr->right)
        			q.push(curr->right);
        	}
        	level++;
        }
        return left_view;
    }
};