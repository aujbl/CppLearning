#include <bits/stdc++.h>

using namespace std;

class NumArray {
private:
    vector<int> nums;
    vector<int> prevs;
    int n;

public:
    NumArray(vector<int>& nums) {
        this->nums = nums;
        n = nums.size();
        prevs.resize(n+1);
        for (int i=0; i<n; ++i){
            prevs[i+1] = prevs[i] + nums[i];
        }
    }
    
    void update(int index, int val) {
        int diff = val - nums[index];
        nums[index] = val;
        for (int i=index+1; i<n+1; ++i){
            prevs[i] += diff;
        }
    }
    
    int sumRange(int left, int right) {
        return prevs[right+1] - prevs[left];
    }
};

int main(){
    vector<int> nums = {-1};
    NumArray solution(nums);
    cout <<  solution.sumRange(0, 0) << endl;
    solution.update(0, 1);
    cout << solution.sumRange(0, 0) << endl;

    return 0;
}