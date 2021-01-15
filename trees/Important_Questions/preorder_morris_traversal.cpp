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
    vector<int> preorderTraversal(TreeNode* root) {
        TreeNode* curr = root;
        vector<int> preorder;
        while(curr){
        
        	if(curr->left){
        		TreeNode* currp1 = curr->left;
        		while(currp1->right && currp1->right!=curr)
        			currp1 = currp1->right;
        		if(!currp1->right){
        			preorder.push_back(curr->val);
        			currp1->right = curr;
        			curr = curr->left; 
        		}
        		else if(currp1->right == curr){
        			curr = currp1->right->right;
        			currp1->right = NULL;
        		}
        	}
        	else{
        		preorder.push_back(curr->val);
        		curr = curr->right;
        	}
        }
        return preorder;
    }
};