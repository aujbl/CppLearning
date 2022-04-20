/*
 * @lc app=leetcode.cn id=104 lang=cpp
 *
 * [104] 二叉树的最大深度
 */

// @lc code=start

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
public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr){
            return 0;
        }

        return max(maxDepth(root->left), maxDepth(root->right)) + 1;

    }
};

class Solution1 {
private:
    int res = 0;
    int deep = 0;

public:
    int maxDepth(TreeNode* root) {
        traverse(root);

        return res;
    }

    void traverse(TreeNode* root){
        if (root == nullptr){
            return;
        }

        deep++;
        res = max(res, deep);
        traverse(root->left);
        traverse(root->right);
        deep--;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    solution.maxDepth();

    return 0;
}



// @lc code=end

