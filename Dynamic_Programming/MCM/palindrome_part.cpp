#include "../../myHeaders.h"
using namespace std;

bool palin(string s, int i, int j) {
    while(i <= j) {
        if(s[i++] != s[j--]) {
            return false;
        }
    }
    return true;
}

int mcm(string s, int i, int j, vector<vector<int>> &dp, vector<vector<int>> &cuts) {

    if(dp[i][j] != -1 ) return dp[i][j];

    if(i >= j || palin(s, i, j)) {
        return dp[i][j] = 0;
    }

    int ans = INT_MAX;

    for(int k = i; k < j; k++) {
        int p = mcm(s, i, k, dp, cuts) + mcm(s, k+1, j, dp, cuts) + 1;
        if(p < ans) {
            ans = p;
            cuts[i][j] = k;
        }
    }

    return dp[i][j] = ans;
}

void print_recurr(string s, vector<vector<int>> &cuts, int i, int j) {
    if(cuts[i][j] == -1) {
        for(int k = i; k <= j; k++){
            cout << s[k] << " ";
        } 
    }
    else {
        print_recurr(s, cuts, i, cuts[i][j]);
        cout << " | ";
        print_recurr(s, cuts, cuts[i][j] + 1, j);
    }
}

void print(string s, vector<vector<int>> &cuts) {
    print_recurr(s, cuts, 0, s.length()-1);
    cout << endl;
}

void solve(string s) {

    vector<vector<int>> dp(s.length(), vector<int> (s.length(), -1));
    vector<vector<int>> cuts(s.length(), vector<int> (s.length(), -1));

    int ans = mcm(s, 0, s.length()-1, dp, cuts);

    print(s, cuts);

    cout << "The number of cuts required is : " << ans << endl;
}

int main() {
    string s; cin >> s;
    solve(s);
}

/*

ababbbabbababa

geek

aaaa

abcde

abbac

*/