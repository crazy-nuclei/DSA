#include "../../myHeaders.h"
using namespace std;

void solve(string &s1, string &s2) {
    int m = s1.length();
    int n = s2.length();
    vector<vector<int>> dp(m+1, vector<int> (n+1, 0));

    int ans = INT_MIN;

    for(int i = 1; i < dp.size(); i++) {
        for(int j = 1; j < dp[0].size(); j++) {
            if(s1[i-1] == s2[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
                ans = max(ans, dp[i][j]);
            }
            else {
                dp[i][j] = 0;
            }
        }
    }

    cout << "Longest substring : " << ans << endl;
}

int main() {
    
    string s1, s2; cin >> s1 >> s2;
    solve(s1, s2);
}

/*
GeeksforGeeks
GeeksQuiz

abcdxyz
xyzabcd

zxabcdezy
yzabcdezx
*/