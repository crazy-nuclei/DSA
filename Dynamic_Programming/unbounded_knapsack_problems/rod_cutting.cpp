#include "../../../myHeaders.h"
using namespace std;

void solve(vector<int> &wei, vector<int> &val, int w) {

    vector<vector<int>> dp(w+1, vector<int> (wei.size()+1, 0));

    for(int i = 1; i < dp.size(); i++ ) {
        for(int j = 1; j < dp[0].size(); j++) {
            if(wei[j-1] <= i) {
                dp[i][j] = max(dp[i-wei[j-1]][j] + val[j-1], dp[i][j-1]);
            } 
            else {
                dp[i][j] = dp[i][j-1];
            }
        }
    }

    cout << "Max val : " << dp[w][wei.size()] << endl;
}

int main() {

    int n; cin >> n;
    vector<int> wei(n), val(n);
    for(int i = 0; i < n; i++) {
        cin >> wei[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> val[i];
    }
    int w; cin >> w;

    solve(wei, val, w);
}

/*
8
1   2   3   4   5   6   7   8 
1   5   8   9  10  17  17  20
8

8
1   2   3   4   5   6   7   8 
3   5   8   9  10  17  17  20
8
*/