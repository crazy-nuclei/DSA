#include "../../../myHeaders.h"
using namespace std;

int rec(string &s1, string &s2, int n, int m, vector<vector<int>> &dp) {
    
    if(dp[n][m] != -1) {
        return dp[n][m];
    }

    if(n == 0 || m == 0) {
        return 0;
    }

    int a = INT_MIN, b = INT_MIN;
    if(s1[n-1] == s2[m-1]) {
        a = rec(s1, s2, n-1, m-1, dp)+1;
    }
    else {
        b = max(rec(s1, s2, n-1, m, dp), rec(s1, s2, n, m-1, dp));
    }
    
    return dp[n][m] = max(a, b);
}

void solve(string s1, string s2){
    vector<vector<int>> dp(s1.length()+1, vector<int> (s2.length()+1, -1));
    int ans = rec(s1, s2, s1.length(), s2.length(), dp);
    cout << "Length of LCS : " << ans << endl;
}

int main() {
    string s1, s2;
    cin >> s1 >> s2;

    solve(s1, s2);
}

/*
AGGTAB 
GXTXAYB

ABCDGH
AEDFHR
*/