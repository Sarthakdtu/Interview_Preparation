/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    void rec(Node* root){
        if(!root)
            return;
        if(root->left){
            root->left->next = root->right;
        }
        if(root->right && root->next){
            root->right->next = root->next->left;
        }
        rec(root->right);
        rec(root->left);
    }

    Node* connect(Node* root) {
        // rec(root); RECURSION
        //ITERATIVE
        Node* curr = root;
        Node* temp = root;

        while(curr){
            temp = curr;
            while(temp){
                if(temp->left)
                    temp->left->next = temp->right;
                
                if(temp->right && temp->next)
                    temp->right->next = temp->next->left;
                
                temp = temp->next;
            }
            curr = curr->left;
        }
        return root;
    }
};