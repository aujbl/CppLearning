#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> bubblingSort(vector<int>& nums){
        int n = nums.size();
        for (int i=n-1; i>=0; --i){
            for (int j=0; j<i; ++j){
                if (nums[j] > nums[j+1]){
                    swap(nums[j], nums[j+1]);
                }
            }
        }
        return nums;
    }

    vector<int> selectSort(vector<int>& nums){
        int n = nums.size();
        for (int i=0; i<n; ++i){
            for (int j=i+1; j<n; ++j){
                if (nums[j] < nums[i]){
                    swap(nums[i], nums[j]);
                }
            }
        }
        return nums;
    }

// ---------------random quick sort------------------
    // vector<int> quickSort(vector<int>& nums) {
    //     srand((unsigned)time(NULL));
    //     randomized_quicksort(nums, 0, (int)nums.size()-1);
    //     return nums;
    // }

    // int partition(vector<int>& nums, int l, int r){
    //     int pivot = nums[r];                    // 取出主元
    //     int i = l - 1;                          // 
    //     for (int j=l; j<=r-1; ++j){
    //         if (nums[j] <= pivot){
    //             i = i + 1;
    //             swap(nums[i], nums[j]);
    //         }
    //     }
    //     swap(nums[i+1], nums[r]);
    //     return i+1;

    //     // while (l < r){
    //     //     while (l < r && nums[l] <= pivot){
    //     //         ++l;
    //     //     }
    //     //     while (l < r && nums[r] > pivot){
    //     //         --r;
    //     //     }
    //     //     if (l < r){
    //     //         swap(nums[l], nums[r]);
    //     //         ++l;
    //     //         --r;
    //     //     }
    //     // }
    //     // return l;
    // }

    // int randomized_partition(vector<int>& nums, int l, int r){
    //     int i = rand() % (r - l + 1) + l;
    //     swap(nums[i], nums[r]);             // 将主元放到最后
    //     return partition(nums, l, r);
    // }

    // void randomized_quicksort(vector<int>& nums, int l, int r){
    //     if (l < r){
    //         int pos = randomized_partition(nums, l, r);
    //         randomized_quicksort(nums, l, pos-1);
    //         randomized_quicksort(nums, pos+1, r);
    //     }
    // }
// ------------------------random quick sort end------------------
    vector<int> quickSort(vector<int>& nums){
        return _quickSort(nums, 0, nums.size()-1);
    }

    // 超时去掉返回值
    vector<int> _quickSort(vector<int>& nums, int l, int r){
        if (r <= l) return nums;
        int i = l, j = r + 1;

        // 随机取主元，否则大数组可能超时
        int pos = ((r - l + 1) >> 1) + l;
        swap(nums[pos], nums[l]);

        int key = nums[l];
        while (true){
            while (nums[++i] < key){
                if (i == r) break;
            }
            while (nums[--j] > key){
                if (j == l) break;
            }
            if (i >= j) break;

            swap(nums[i], nums[j]);
        }
        nums[l] = nums[j];      // j对应 <= key的值，与key交换不出错
        nums[j] = key;          // j位置排序完成
        _quickSort(nums, l, j-1);
        _quickSort(nums, j+1, r);
        return nums;
    }

};

int main(){
    Solution solution;
    vector<int> nums = {};
    // solution.selectSort(nums);
    solution.quickSort(nums);


    for (auto n:nums){
        cout << n << " ";
    }
    cout << endl;

    return 0;
}