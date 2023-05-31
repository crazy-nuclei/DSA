#include "../../myHeaders.h"
using namespace std;

int gets(vector<int> &nums) {
    int sum = 0;
    for(int i = 0; i < nums.size(); i++) {
        sum += nums[i];
    }
    return sum;
}

void solve(vector<int> &nums, int diff) {
    
    int sum = gets(nums);
    int x = sum + diff;

    if(x & 1) {
        cout << "Count : " << 0 << endl;
        return;
    }
    x /= 2;
    vector<vector<int>> dp(x+1, vector<int> (nums.size()+1, 0));

    for(int i = 0; i < dp[0].size(); i++){
        dp[0][i] = 1;
    }
    for(int i = 1; i < dp.size(); i++) {
        for(int j = 1; j < dp[0].size(); j++) {
            if(nums[j-1] <= i) {
                dp[i][j] = dp[i-nums[j-1]][j-1] + dp[i][j-1];
            }
            else {
                dp[i][j] = dp[i][j-1];
            }
        }
    }

    cout << "Count : " << dp[x][nums.size()] << endl; 
}

int main() {
    int n; cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }
    int diff; cin >> diff;
    solve(nums, diff);
}

/*
4
1 1 2 3
1
*/