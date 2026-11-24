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

    void solve(TreeNode* root, vector<int>& ans) {

        if (root == NULL) {
            return;
        }

        // 1. Visit Root
        ans.push_back(root->val);

        // 2. Visit Left
        solve(root->left, ans);

        // 3. Visit Right
        solve(root->right, ans);
    }

    vector<int> preorderTraversal(TreeNode* root) {

        vector<int> ans;

        solve(root, ans);

        return ans;
    }
};
