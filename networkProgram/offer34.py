# Definition for a binary tree node.
from typing import List

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def pathSum(self, root: TreeNode, target: int) -> List[List[int]]:
        res = []
        path = []
        self.total = 0
        
        def dfs(root):
            if not root:
                return 

            path.append(root.val)
            self.total += root.val
            if not root.left and not root.right and self.total == target:
                    res.append(path.copy())

            dfs(root.left)
            dfs(root.right)

            path.pop()
            self.total -= root.val

        dfs(root)
        return res

if __name__ == '__main__':
    solution = Solution()
    # root = [5,4,8,11,null,13,4,7,2,null,null,5,1]
    root = TreeNode(5, TreeNode(4, TreeNode(11, TreeNode(7), TreeNode(2))), TreeNode(8, TreeNode(13), TreeNode(4, TreeNode(5), TreeNode(1))))
    targetSum = 22
    print(solution.pathSum(root, targetSum))