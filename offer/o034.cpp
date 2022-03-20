#include <bits/stdc++.h>

using namespace std;

// #include <unordered_map>
// #include <string>
// #include <vector>
// #include <cmath>


// class Solution {
// private:
//     unordered_map<char, int> myorder;
// public:
//     bool isAlienSorted(vector<string>& words, string order) {
//         setorder(order);
//         int len = words.size();
//         for (int i=0; i<len-1; ++i){
//             if (!cmp(words[i], words[i+1])){
//                 return false;
//             }
//         }
//         return true;
//     }

//     bool cmp(const string &w1, const string &w2){
//         int len = min(w1.size(), w2.size());
//         for (int i=0; i<len; ++i){
//             if (myorder[w1[i]] < myorder[w2[i]]){
//                 return true;
//             }else if (myorder[w1[i]] > myorder[w2[i]]){
//                 return false;
//             }
//         }
//         return w1.size() <= w2.size();
//     }

//     void setorder(const string &order){
//         int len = order.size();
//         for (int i=0; i<len; ++i){
//             myorder[order[i]] = i;
//         }
//     }
// };

// class Solution {
// public:
//     int countHillValley(vector<int>& nums) {
//         int len = nums.size();
//         int start = 0;
//         int cnt = 0;
//         while (start + 1 < len && nums[start] == nums[start+1]){
//             start++;
//         }
//         while (start < len){
//             int end = start + 1;
//             while(end < len && nums[end] >= nums[end-1]){
//                 ++end;
//             }
//             if (end < len && (nums[end] < nums[end-1]) && (end - start > 1)){
//                 ++cnt;
//             }
//             start = end;
//             while (start + 1 < len && nums[start] == nums[start+1]){
//                 start++;
//             }
//         }
//         start = 0;
//         while (start + 1 < len && nums[start] == nums[start+1]){
//             start++;
//         }
//         while (start < len){
//             int end = start + 1;
//             while(end < len && nums[end] <= nums[end-1]){
//                 ++end;
//             }
//             if (end < len && (nums[end] > nums[end-1]) && (end - start > 1)){
//                 ++cnt;
//             }
//             start = end;
//             while (start + 1 < len && nums[start] == nums[start+1]){
//                 start++;
//             }
//         }
//         return cnt;
//     }
// };

class Solution {
public:
    int countCollisions(string directions) {
        string new_dirs = "";
        int len = directions.size();
        int cnt = 0;
        while (new_dirs != directions){
            new_dirs = directions;
            for (int i=0; i<len-1; ++i){
                if (directions[i] == 'R' && directions[i+1] == 'L'){
                    cnt += 2;
                    directions[i] = 'S';
                    directions[i+1] = 'S';
                }
                else if (directions[i] == 'S' && directions[i+1] == 'L'){
                    cnt += 1;
                    directions[i+1] = 'S';
                }else if (directions[i] =='R' && directions[i+1] == 'S'){
                    cnt += 1;
                    directions[i] = 'S';
                }
            }
        }
        return cnt;
    }
};




int main(){
    Solution solution;
    // vector<string> words({"ubg","kwh"});

    // string order("qcipyamwvdjtesbghlorufnkzx");

    // cout << solution.isAlienSorted(words, order) << endl;;

    // vector<int> nums({1,1,1,1,1,1,1,57,57,57,50,50,50,50,22,22,22,86});

    // vector<int> nums({6,6,5,5,4,4,1});
    string dirs = "RLRSLL";

    cout << solution.countCollisions(dirs) << endl;

    return 0;
}