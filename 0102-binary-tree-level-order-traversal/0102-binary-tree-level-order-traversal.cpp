class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == nullptr) return {};

        queue<TreeNode*> q;
        vector<vector<int>> res;

        q.push(root);

        while (!q.empty()){
            int levelSize = ssize(q);
            vector<int> currentLevel;

            for (int i = 0; i < levelSize; ++i) {
                TreeNode* curr = q.front();
                q.pop();

                currentLevel.push_back(curr->val);

                if (curr->left != nullptr) q.push(curr->left);
                if (curr->right != nullptr) q.push(curr->right);
            }

            res.push_back(currentLevel);
        } 

        return res;
    }
};