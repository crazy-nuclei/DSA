#include "../../../myHeaders.h"
using namespace std;

void solve(vector<int> &coins, int sum) {
    
    vector<vector<int>> dp(sum+1, vector<int> (coins.size()+1, INT_MAX/2));

    for(int i = 0; i < dp[0].size(); i++) {
        dp[0][i] = 0;
    }

    for(int i = 1; i < dp.size(); i++) {
        for(int j = 1; j < dp[0].size(); j++) {
            if(coins[j-1] <= i) {
                dp[i][j] = min(dp[i-coins[j-1]][j] + 1, dp[i][j-1]);
            }
            else {
                dp[i][j] = dp[i][j-1];
            }
        }
    }

    cout << "Min coins : " << dp[sum][coins.size()] << endl;
}

int main() {

    int n; cin >> n;
    vector<int> coins(n);
    for(int i = 0; i < n; i++) {
        cin >> coins[i];
    }
    int sum; cin >> sum;

    solve(coins, sum);
}



/*

3
25 10 5
30

4
9 6 5 1
11

*/