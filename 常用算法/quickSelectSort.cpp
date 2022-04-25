#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int idx;

public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        idx = n - k;
        quickSelectSort(nums, 0, n-1);

        return nums[idx];
    }

    void quickSelectSort(vector<int>& nums, int left, int right){
        if (left == right) return;
        
        int pos = left + (right - left) / 2;
        int key = nums[pos];
        swap(nums[left], nums[pos]);
        int i = left + 1, j = right;
        while (i <= j){
            while (nums[j] >= key){
                j--;
                if (i > j) break;
            }
            while (nums[i] <= key){
                i++;
                if (i > j) break;
            }
            if (i > j) break;
            swap(nums[i++], nums[j--]);
        }
        swap(nums[left], nums[j]);
        if (j == idx) return;

        if (j > idx){
            quickSelectSort(nums, left, j-1);
        }else{
            quickSelectSort(nums, j+1, right);
        }
    }
};

int main(){
    Solution s;
    vector<int> nums = {3, 1, 2, 4};
    s.findKthLargest(nums, 2);

}