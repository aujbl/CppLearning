/*
 * @lc app=leetcode.cn id=543 lang=cpp
 *
 * [543] 二叉树的直径
 */

// @lc code=start


// @lc code=end

#include <bits/stdc++.h>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
private:
    int depth;

public:
    int diameterOfBinaryTree(TreeNode* root) {
        traverse(root);

        return depth;
    }

    int traverse(TreeNode* node){
        if (node == nullptr){
            return 0;
        }

        int l_depth = traverse(node->left);
        int r_depth = traverse(node->right);

        depth = max(depth, l_depth + r_depth);

        return max(l_depth, r_depth) + 1;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    solution

    return 0;
}
