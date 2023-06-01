#include "../../myHeaders.h"
using namespace std;

int mcm(vector<int> &arr, int i, int j, vector<vector<int>> &dp) {
    
    if(dp[i][j] != -1) return dp[i][j];

    if(i >= j) return 0;

    int ans = INT_MAX;

    for(int k = i; k < j; k++) {
        int p = mcm(arr, i, k, dp) + mcm(arr, k+1, j, dp) + arr[i-1]*arr[k]*arr[j];
        ans = min(ans, p);
    }

    return dp[i][j] = ans;
}

void solve(vector<int> &arr) {

    vector<vector<int>> dp(arr.size(), vector<int> (arr.size(), -1));

    int ans = mcm(arr, 1, arr.size()-1, dp);

    cout << "The min no of multiplications required : " << ans << endl;
}

int main() {
    int n; cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    solve(arr);
}

/*

5
40 20 30 10 30

5
1 2 3 4 3

*/