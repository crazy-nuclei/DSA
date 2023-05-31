#include "../../../myHeaders.h"
using namespace std;

string rev(string lc) {
    string ans;
    for(int i = lc.size()-1; i >=0; i--) {
        ans += lc[i];
    }
    return ans;
}

void print_lcs(string s1, string s2, vector<vector<int>> &dp){
    int i = s1.length(), j = s2.length();

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

    cout << "LCS of the strings is : " << lc << endl;
}

void solve(string &s1, string &s2) {

    vector<vector<int>> dp(s1.length()+1, vector<int> (s2.length()+1, 0));

    for(int i = 1; i < dp.size(); i++) {
        for(int j = 1; j < dp[0].size(); j++) {
            if(s1[i-1] == s2[j-1]){
                dp[i][j] = max(dp[i-1][j-1]+1, max(dp[i-1][j], dp[i][j-1]));
            }
            else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    int ans = dp[s1.length()][s2.length()];

    cout << "Length of LCS is : " << ans << endl;

    print_lcs(s1, s2, dp);
    
}

int main() {

    string s1, s2; cin >> s1 >> s2;

    solve(s1, s2);
}


/*
AGGTAB 
GXTXAYB

ABCDGH
AEDFHR
*/