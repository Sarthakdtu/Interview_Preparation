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
    void left_boundary(TreeNode* root, vector<int> &nodes){
        if(!root->left && !root->right)
            return;
        nodes.push_back(root->val);
        if(root->left){
            left_boundary(root->left, nodes);
        }
        else if(root->right){
            left_boundary(root->right, nodes)
        }
    }

    void leaves(TreeNode* root, vector<int> &nodes){
        if(!root)
            return;
        else if(!root->left && !root->right)
            nodes.push_back(root->val);
        else{
            leaves(root->left);
            leaves(root->right);
        }
    }    

    void right_boundary(TreeNode* root, vector<int> &nodes){
        if(!root->left && !root->right)
            return;
        nodes.push_back(root->val);
        if(root->right){
            right_boundary(root->right, nodes);
        }
        else if(root->left){
            right_boundary(root->left, nodes)
        }
    }


    vector<int> boundary(TreeNode* root) {
        vector<int> ans;
        ans.push_back(root->val);
        left_boundary(root->left, ans);
        leaves(root, ans);
        right_boundary(root->right, ans);
        return ans;
    }
};