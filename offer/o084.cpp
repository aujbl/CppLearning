#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int ans = 0;
        stack<int> mono_s;
        vector<int> left(n, -1), right(n, n);
        for (int i=0; i<n; ++i){
            while (!mono_s.empty() && heights[mono_s.top()] >= heights[i]){
                right[mono_s.top()] = i;
                mono_s.pop();
            }
            if (!mono_s.empty()){
                left[i] = mono_s.top();
            }
            mono_s.push(i);
        }
        for (int i=0; i<n; ++i){
            ans = max(ans, (right[i] - left[i] - 1) * heights[i]);
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;

    vector<int> heights = {2, 1, 5, 6, 2, 3};

    solution.largestRectangleArea(heights);

    return 0;
}
