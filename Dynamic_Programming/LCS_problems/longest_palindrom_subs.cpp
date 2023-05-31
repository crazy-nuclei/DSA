#include "../../myHeaders.h"
using namespace std;

string rev(string s) {
    string an; 
    for(int i = s.length()-1; i >= 0; i--) {
        an += s[i];
    }
    return an;
}

void print_pal(string s1, string s2, vector<vector<int>> &dp) {
    int i = s1.length();
    int j = s2.length();

    string lc;
    while(i > 0 && j > 0) {
        if(s1[i-1] == s2[j-1]) {
            lc += s1[i-1];
            i--;
            j--;
        }
        else {
            if(dp[i-1][j] > dp[i][j-1]) {
                i--;
            }
            else {
                j--;
            }
        }
    }
    lc = rev(lc);

    cout << "The palindrome is : " << lc << endl;
}

void solve(string s1) {
    int n = s1.length();
    string s2 = rev(s1);

    vector<vector<int>> dp(n+1, vector<int> (n+1, 0));

    for(int i = 1; i < dp.size(); i++){
        for(int j = 1; j < dp[0].size(); j++ ) {
            if(s1[i-1] == s2[j-1]) {
                dp[i][j] = max(dp[i-1][j-1]+1, max(dp[i-1][j], dp[i][j-1]));
            }
            else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    int ans = dp[n][n];

    cout << "Length of the longest palindromic subsequence is : " << ans << endl;

    print_pal(s1, s2, dp);

}

int main() {
    string s; cin >> s;
    solve(s);
}

/*
bbbab

geeksforgeeks
*/