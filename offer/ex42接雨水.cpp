#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        stack<int> stk;
        stk.push(0);
        int i = 0;
        int res = 0, tmp = 0;
        while(i < n){
            if (height[i] < height[stk.top()]){
                tmp += height[stk.top()] - height[i];
            }else{
                res += tmp;
                tmp = 0;
                stk.pop();
                stk.push(i);
            }

            i++;
        }
        int mid = stk.top();
        while (!stk.empty()){
            stk.pop();
        }
        tmp = 0;
        int j = n-1;
        stk.push(j);
        while(j >= mid){
            if (height[j] < height[stk.top()]){
                tmp += height[stk.top()] - height[j];
            }else{
                res += tmp;
                tmp = 0;
                stk.pop();
                stk.push(j);
            }
            j--;
        }


        return res;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> nums = {0,1,0,2,1,0,1,3,2,1,2,1};
    solution.trap(nums);

    return 0;
}
