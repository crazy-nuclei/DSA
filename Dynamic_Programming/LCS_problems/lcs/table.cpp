#include "../../../myHeaders.h"
using namespace std;

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