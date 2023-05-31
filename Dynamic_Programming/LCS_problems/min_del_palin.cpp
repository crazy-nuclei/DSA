#include "../../myHeaders.h"
using namespace std;

string rev(string s1) {
    string s;
    for(int i = s1.length()-1; i >=0; i--) {
        s += s1[i];
    }

    return s;
}

void solve(string s1) {
    int n = s1.length();
    string s2 = rev(s1);

    vector<vector<int>> dp(n+1, vector<int> (n+1, 0));

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

    int ans = n - dp[n][n];

    cout << "Min number of deletions to make it a palindorme is : " << ans << endl;
}

int main() {
    string s; cin >> s;
    solve(s);
}

/*

aebcbda

geeksforgeeks

*/