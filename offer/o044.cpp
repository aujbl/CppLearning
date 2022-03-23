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
    vector<TreeNode*> q;
    vector<TreeNode*> new_q;
    
public:
    vector<int> largestValues(TreeNode* root) {
        q.emplace_back(root);
        vector<int> res;
        while (!q.empty()){
            res.emplace_back(maxValue(q));
            q = new_q;
        }
        return res;
    }

    int maxValue(vector<TreeNode*> q){
        int tmp = INT_MIN;
        new_q.clear();
        for (TreeNode* node : q){
            tmp = max(tmp, node->val);
            if (node->left != nullptr){
                new_q.emplace_back(node->left);
            }
            if (node->right != nullptr){
                new_q.emplace_back(node->right);
            }
        }
        // q = new_q;
        return tmp;
    }
};

int main(){
    Solution solution;
    TreeNode* root = new TreeNode(1, new TreeNode(2), new TreeNode(3));
    vector<int> res = solution.largestValues(root);
    for (auto n : res){
        cout << n << " ";
    }
    cout << endl;

    return 0;
}
