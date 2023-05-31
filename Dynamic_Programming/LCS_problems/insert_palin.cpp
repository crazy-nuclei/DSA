#include "../../myHeaders.h"
using namespace std;

string rev(string a) {
    string b;
    for(int i = a.size()-1; i >= 0; i--){
        b += a[i];
    }

    return b;
}

void get_lcs(string s1, string s2, vector<vector<int>> &dp) {
    int i = dp.size()-1;
    int j = dp[0].size()-1;

    string ans;

    while( i > 0 && j > 0) {
        if(s1[i-1] == s2[j-1] ) {
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
    while(i>0) {
        ans += s1[i-1];
        i--;
    }
    while(j > 0) {
        ans += s2[j-1];
        j--;
    }

    ans = rev(ans);
    int num = ans.size() - s1.size();

    cout << "Number of insertions required is : " << num << endl;
    cout << "The palindrome is : " << ans << endl;
}

void solve(string s1) {
    int n = s1.length();
    string s2 = s1;

    s2 = rev(s1);

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

    get_lcs(s1, s2, dp);
}

int main() {
    string s; cin >> s;
    solve(s);
}

/*

ab

aa

abcd

abcda

abcde

*/