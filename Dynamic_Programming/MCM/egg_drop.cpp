#include "../../myHeaders.h"
using namespace std;

int mcm(int n, int k, vector<vector<int>> &dp) {

    if(dp[n][k] != -1) {
        return dp[n][k];
    }

    if( n == 1) {
        return k;
    }
    if(k == 1 || k == 0) {
        return k;
    }

    int ans = INT_MAX;

    for(int i = 1 ; i <= k; i++) {
        int p = 1 + max(mcm(n-1, i-1, dp), mcm(n, k-i, dp));
        ans = min(ans, p);
    }

    return dp[n][k] = ans;
}

void solve(int n, int k) {

   vector<vector<int>> dp(n+1, vector<int> (k+1, -1));
   int ans = mcm(n, k, dp);

   cout << "Maximum number of attempts required is : " << ans << endl;
}

int main() {
    int n, k; cin >> n >> k; 
    solve(n, k);
}

/*

2 4

2 10 

*/