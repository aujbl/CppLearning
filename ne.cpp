#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,p,x;
    cin>>n>>p>>x;
    int count=0;
    vector<int > nums(n,0);
    for(int i=0;i<n;i++)
    {
        cin>>nums[i];
    }
    
    int sum = accumulate(nums.begin(),nums.end(), 0);
    int remain = sum % x;
    if (remain == 0){
        remain = x;
    }
    int cnt = 0;
    for(int i =0;i<n;i++)
    {
        // int n_remain = nums[i] % x;
        cnt = p / x;
        while (x - remain - (nums[i] % x) + x*cnt > p){
            cnt--;
        }
        if ((nums[i] % x == x - remain) && nums[i] <= p){
            cnt--;
        }
        count += cnt;

        // int sum_temp = sum-nums[i];
        // for(int j=1;j<=p;j+=x)
        // {
        //     if((sum_temp+j)%x==0&&nums[i]!=j)
        //     {
        //         count++;
        //     }
        // }
    }
    cout <<count<<endl; 
}