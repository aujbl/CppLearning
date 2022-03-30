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
        _quickSort(nums, 0, nums.size()-1);
        return nums;
    }

    void _quickSort(vector<int>& nums, int l, int r){
    if (r <= l) return;
    int pos = ((r - l + 1) >> 1) + l;
    int key = nums[pos];
    swap(nums[l], nums[pos]);
    int i = l, j = r + 1;                   // i = l,因为l位置保存了主元的值       
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
    swap(nums[l], nums[j]);
    _quickSort(nums, l, j-1);
    _quickSort(nums, j+1, r);
    }

    // // 超时去掉返回值
    // vector<int> _quickSort(vector<int>& nums, int l, int r){
    //     if (r <= l) return nums;
    //     int i = l, j = r + 1;

    //     // 随机取主元，否则大数组可能超时
    //     int pos = ((r - l + 1) >> 1) + l;
    //     swap(nums[pos], nums[l]);

    //     int key = nums[l];
    //     while (true){
    //         while (nums[++i] < key){
    //             if (i == r) break;
    //         }
    //         while (nums[--j] > key){
    //             if (j == l) break;
    //         }
    //         if (i >= j) break;

    //         swap(nums[i], nums[j]);
    //     }
    //     nums[l] = nums[j];      // j对应 <= key的值，与key交换不出错
    //     nums[j] = key;          // j位置排序完成
    //     _quickSort(nums, l, j-1);
    //     _quickSort(nums, j+1, r);
    //     return nums;
    // }
    void mergeSort(vector<int>& nums){
        _mergeSort(nums, 0, nums.size() - 1);
    }

    void _mergeSort(vector<int>& nums, int l, int r){
        if (l >= r) return;
        int mid = (l + r) >> 1;             // l + ((r - l) >> 1)
        _mergeSort(nums, l, mid);
        _mergeSort(nums, mid+1, r);
        vector<int> tmp(r - l + 1);
        int i = l, j = mid + 1;
        int cnt = 0;
        while (i <= mid && j <= r){
            if (nums[i] <= nums[j]){
                tmp[cnt++] = nums[i++];
            }else{
                tmp[cnt++] = nums[j++];
            }
        }
        while (i <= mid){
            tmp[cnt++] = nums[i++];
        }
        while (j <= r){
            tmp[cnt++] = nums[j++];
        }
        for (int i=0; i<r-l+1; ++i){
            nums[i+l] = tmp[i];
        }
    }

    void maxHeapify(vector<int>& nums, int l, int r){
        int dad = l;
        int son = (dad << 1) + 1;
        while (son <= r){
            // 父节点最大，子节点哪个大不确定
            if (son + 1 <= r && nums[son] < nums[son+1]){
                ++son;              // 让son指向较大的值
            }
            if (nums[dad] > nums[son]){
                return;
            }else{
                swap(nums[dad], nums[son]);
                dad = son;
                son = (dad << 1) + 1;
            }
        }
    }

    void _heapSort(vector<int>& nums, int len){
        // 从最后一个父节点len / 2 - 1开始调整，调整后形成大根堆
        for (int i=len/2-1; i>=0; --i){
            maxHeapify(nums, i, len-1);         // 得到一个最大值，保存在nums[0]，i~len-1是调整好的部分
        }
        for (int i=len-1; i>0; --i){
            swap(nums[i], nums[0]);             // 把nums[0]处的最大值移到最后
            maxHeapify(nums, 0, i-1);           // 向下调整，直到父节点比两个子节点都大
        }
    }

    void heapSort(vector<int>& nums){
        _heapSort(nums, nums.size());
    }




};



int main(){
    Solution solution;
    // vector<int> nums = {1,4,5,41246,7,7432,9,9,1341233,71341234,6213,4,3,3,5,6,7,8,8,6};
    vector<int> nums = {5, 2, 3, 1};
    // solution.selectSort(nums);
    // solution.quickSort(nums);
    // solution.mergeSort(nums);
    solution.heapSort(nums);


    for (auto n:nums){
        cout << n << " ";
    }
    cout << endl;

    return 0;
}




