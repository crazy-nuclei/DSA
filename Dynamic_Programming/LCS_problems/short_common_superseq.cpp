#include "../../myHeaders.h"
using namespace std;

string rev(string an) {
    string ans;
    for(int i = an.length()-1; i >= 0; i--) {
        ans += an[i];
    }

    return ans;
}

void print_scs(string s1, string s2, vector<vector<int>> &dp) {
    int i = dp.size();
    int j = dp[0].size();

    string ans;

    while(i > 0 && j > 0 ) {
        if(s1[i-1] == s2[j-1]) {
            ans += s1[i-1];
            i--;
            j--;
        }
        else {
            if(dp[i-1][j] > dp[i][j-1]) {
                ans += s1[i-1];
                i--;
            }
            else {
                ans += s2[j-1];
                j--;
            }
        }
    }
    while(i > 0) {
        ans += s1[i-1];
        i -= 1;
    }
    while(j > 0) {
        ans += s2[j-1];
        j -= 1;
    }
    ans = rev(ans);

    cout << "Shortest common superscript is : " << ans << endl;
}

void solve(string s1, string s2) {
    int n = s1.length();
    int m = s2.length();

    vector<vector<int>> dp(n+1, vector<int> (m+1, 0));

    for(int i = 1; i < dp.size(); i++) {
        for(int j = 1; j < dp[0].size(); j++) {
            if(s1[i-1] == s2[j-1]) {
                dp[i][j] = max(dp[i-1][j-1]+1, max(dp[i-1][j], dp[i][j-1]));
            }
            else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    int ans = n + m - dp[n][m];
    
    cout << "Length of shorest common superscript : " << ans << endl;

    print_scs(s1, s2, dp);
}

int main() {
    string s1, s2; cin >> s1 >> s2;
    
    solve(s1, s2);
}

/*
geek
eke

AGGTAB
GXTXAYB
*/