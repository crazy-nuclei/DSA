#include "../../myHeaders.h"
using namespace std;

int gets(vector<int> &nums){
    int sum = 0;
    for(int i = 0; i< nums.size(); i++){
        sum += nums[i];
    }
    return sum;
}

void check(vector<vector<int>> &dp, int sum) {
    int ans = INT_MAX;
    for(int i = 0; i < dp.size(); i++ ) {
        if(dp[i][dp[0].size()-1] == 0) continue; 
        ans = min(ans , abs(2*i- sum));
    }

    cout << "MIN DIFF : " << ans << endl;
}

void solve(vector<int> &nums) {

    int sum = gets(nums);
    vector<vector<int>> dp(sum+1, vector<int> (nums.size()+1, 0)); 

    for(int i = 0; i < dp[0].size(); i++) {
        dp[0][i] = 1;
    }

    for(int i = 1; i < dp.size(); i++){
        for(int j = 1; j < dp[0].size(); j++){
            if(nums[j-1] <= i) {
                dp[i][j] = dp[i-nums[j-1]][j-1] || dp[i][j-1];
            } 
            else dp[i][j] = dp[i][j-1];
        }
    }

    check(dp, sum);
}

int main() {

    int n; cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    solve(nums);
}


/*
4
1 6 11 5
*/