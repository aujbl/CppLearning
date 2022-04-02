#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution {
public:
    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<int, int> prevs;
        prevs[0] = 1;
        int ans = 0, prev = 0;
        ans = dfs(root, prevs, prev, ans, targetSum);

        return ans;
    }

    int dfs(TreeNode* root, unordered_map<int, int>& prevs, int prev, int ans, int targetSum){
        if (root == nullptr) return 0;
        int new_prev = prev + root->val;
        ans = prevs[new_prev - targetSum];
        ++prevs[new_prev];
        ans += dfs(root->left, prevs, new_prev, ans, targetSum);
        ans += dfs(root->right, prevs, new_prev, ans, targetSum);
        --prevs[new_prev];

        return ans;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    TreeNode* root = new TreeNode(1, new TreeNode(-2), new TreeNode(-3));
    cout << solution.pathSum(root, -1) << endl;

    return 0;
}
