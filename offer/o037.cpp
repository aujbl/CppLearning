#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> res;
        int tmp;
        for (auto a : asteroids){
            if (res.size() == 0){
                res.emplace_back(a);
            }else{
                while (a != 0){
                    tmp = res.back();
                    res.pop_back();
                    if ((a > 0 && tmp > 0) || (a < 0 && tmp < 0) || (tmp < 0 && a > 0)){
                        res.emplace_back(tmp);
                        res.emplace_back(a);
                        a = 0;
                    }
                    else{
                        while (tmp > 0 && a < 0){
                            if (tmp < abs(a)){
                                if (res.size() > 0){
                                    tmp = res.back();
                                    res.pop_back();
                                }else{
                                    res.emplace_back(a);
                                    a = 0;
                                }

                            }else if (tmp > abs(a)){
                                a = 0;
                                res.emplace_back(tmp);
                            }else if (tmp + a == 0){
                                a = 0;
                            }
                        }
                        if (tmp < 0 && a < 0){
                            res.emplace_back(tmp);
                            res.emplace_back(a);
                            a = 0;
                        }
                    } 
                }
            }
        }
        return res;
    }
};


int main(){
    Solution solution;

    vector<int> asteroids({1, -2, -2, -2});

    vector<int> res = solution.asteroidCollision(asteroids);

    for (auto n : res){
        cout << n;
    }

    return 0;
}