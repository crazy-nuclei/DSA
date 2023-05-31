#include "../../myHeaders.h"
using namespace std;

void solve(vector<int> &nums, vector<vector<int>> &dp) {

    for(int i = 0; i < dp[0].size(); i++) {
        dp[0][i] = 1;
    }

    for(int i = 1; i < dp.size(); i++) {
        for(int j = 1; j < dp[0].size(); j++) {
            if(nums[j-1] <= i) {
                dp[i][j] = dp[i-nums[j-1]][j-1] || dp[i][j-1];
            }
            else {
                dp[i][j] = dp[i][j-1];
            }
        }
    }
}

int main() {

    int n; cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    int sum; cin >> sum;

    vector<vector<int>> dp(sum+1, vector<int> (n+1,0));

    solve(nums, dp);

    int ans = dp[sum][n];
    cout << ans << endl;
}

/*
6
3 34 4 12 5 2
9

6
3 34 4 12 5 2
30
*/