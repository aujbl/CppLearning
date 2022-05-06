#include <bits/stdc++.h>

using namespace std;

// class Solution {
// public:
//     int findTheWinner(int n, int k) {
//         if(k == 1) return n;
//         vector<int> visited(n, 0);
//         int cnt = 0;
//         int remove = 0;
//         int res = -1;
//         int i = 0;
//         while (remove < n-1){
//             if (visited[i] == 0){
//                 cnt++;
//                 if (cnt == k){
//                     cnt = 0;
//                     remove++;
//                     visited[i] = 1;
//                     while (visited[i] != 0){
//                         i++;
//                         i %= n;
//                     }
//                     res = i;
//                 }
//             }
//             i++;
//             i %= n;
//         }
//         return res;
//     }
// };

class Solution {
public:
    int findTheWinner(int n, int k) {
        if(k == 1) return n;

        int res = 1;
        int next = 0;

        while (n > 1){
            next = (next + k - 1) % n;
            res = next;  
            n--;
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    solution.findTheWinner(5, 2);

    return 0;
}
