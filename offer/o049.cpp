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
private: 
    int total = 0;
    string str;
public:
    int sumNumbers(TreeNode* root) {
        dfs(root, str);
        return total;
    }

    void dfs(TreeNode* root, string& str){
        if (root->left == nullptr && root->right == nullptr){
            total += stoi(str+to_string(root->val));
            return;
        }
        str += to_string(root->val);
        if (root->left != nullptr){
            dfs(root->left, str);
        }
        if (root->right != nullptr){
            dfs(root->right, str);
        }
        str.erase(str.end()-1);
        // str -= to_string(root->val);

        return;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    printf("%d", solution.sumNumbers(new TreeNode(0, new TreeNode(1), nullptr)));
    // printf("%d", solution.sumNumbers(new TreeNode(4, new TreeNode(9, new TreeNode(5), new TreeNode(1)), new TreeNode(0))));

    return 0;
}
