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
    vector<int> bottomView(TreeNode* root) {
        map<int, int> bottom_map;
        vector<int> bottom_view;
        queue<pair<TreeNode*, int> > q;
        int vlevel = 0;
        int min_level = 0;
        int max_level = 0;

        q.push({root, 0});
        while(!q.empty()){
            int size = q.size();
            bool insert = true;
            while(size--){
                pair<TreeNode*, int> curr = q.front();
                q.pop();
                
                vlevel = curr.second;
                min_level = min(min_level, vlevel);
                max_level = max(max_level, vlevel);
                
                bottom_map[vlevel] = curr.first->val;
                
                if(curr.first->left)
                    q.push({curr.first->left, vlevel-1});
                if(curr.first->right)
                    q.push({curr.first->right, vlevel+1});
            }
        }
        for(int i=min_level;i<=max_level;i++){
            bottom_view.push_back(bottom_map[i]);
        }
        return bottom_view;
    }
};