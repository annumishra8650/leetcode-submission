
class Solution {
public:

    int sumOfLeftLeaves(TreeNode* root) {

        if(root == NULL) {
            return 0;
        }

        int sum = 0;

        // Check left child
        if(root->left != NULL) {

            // Check whether left child is a leaf
            if(root->left->left == NULL &&
               root->left->right == NULL) {

                sum += root->left->val;
            }
            else {
                sum += sumOfLeftLeaves(root->left);
            }
        }

        // Check right subtree
        sum += sumOfLeftLeaves(root->right);

        return sum;
    }
};
