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
    vector<int> ans;
    void helper(TreeNode* root){
        if(!root) return;
        ans.push_back(root->val);
        if(!root->left && !root->right) {
            return;
        }
        helper(root->left);
        helper(root->right);

    }
    vector<int> preorderTraversal(TreeNode* root) {
        
        if(!root) return ans;
        //helper(root);
        stack<TreeNode* > st;
        st.push(root);
        while(!st.empty()){
            root = st.top();
            st.pop();
            ans.push_back(root->val);

            if(root->right!=NULL){
                st.push(root->right);
            }
            if(root->left!=NULL){
                st.push(root->left);
            }
        }
        
        return ans;
        
    }
};