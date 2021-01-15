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
	int rec(TreeNode* root, int &gmax){
		if(!root)
    		return -10000;
    	int left_sum = rec(root->left, gmax);
    	int right_sum = rec(root->right, gmax);
    	int curr_max = max(root->val,
    						max(left_sum + root->val,
    							right_sum + root->val
    					)
    			);
        gmax = max(gmax, curr_max);
    	gmax = max(left_sum + right_sum + root->val, gmax);    	
    	return curr_max;
	}
    int maxPathSum(TreeNode* root) {
    	int gmax = -100000;
    	rec(root, gmax);
    	return gmax;;        
    }
};