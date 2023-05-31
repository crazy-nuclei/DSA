#include "../../myHeaders.h"
using namespace std;

void solve(vector<int> &nums, int sum) {

    vector<vector<int>> dp(sum +1, vector<int> (nums.size()+1, 0));

    for(int i = 0; i < dp[0].size(); i++) {
        dp[0][i] = 1;
    }

    for(int i = 1; i < dp.size(); i++) {
        for(int j = 1; j < dp[0].size(); j++){
            if(nums[j-1] <= i) {
                dp[i][j] = dp[i-nums[j-1]][j-1] + dp[i][j-1];
            }
            else {
                dp[i][j] = dp[i][j-1];
            }
        }
    }

    

    int ans = dp[sum][nums.size()];
    cout << ans << endl;
}

int main() {
    int n; cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++ ) {
        cin >> nums[i];
    }
    int sum; cin >> sum;

    solve(nums, sum);
}


/*
4
1 2 3 3
6
*/