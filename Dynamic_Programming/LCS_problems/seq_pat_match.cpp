#include "../../myHeaders.h"
using namespace std;

void solve(string s1, string s2) {
    int n = s1.length();
    int m = s2.length();

    vector<vector<int>> dp(n+1, vector<int> (m+1, 0));

    for(int i = 1; i < dp.size(); i++) {
        for(int j = 1; j < dp[0].size(); j++) {
            if(s1[i-1] == s2[j-1]) {
                dp[i][j] = max(dp[i-1][j-1] + 1, max(dp[i-1][j], dp[i][j-1]));
            }
            else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    if(dp[n][m] == n) {
        cout << "Given string is subsequence of the other" << endl;
    }
    else {
        cout << "It is not a subsequence of the other string" << endl;
    }
}

int main() {
    string s1, s2; cin >> s1 >> s2;
    solve(s1, s2);
}

/*
abc
ahbgdc
*/