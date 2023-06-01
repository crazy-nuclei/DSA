#include "../../../myHeaders.h"
using namespace std;

void knap(vector<int> &wei, vector<int> &val, vector<vector<int>> &dp, int w, int n) {
    
    for(int i = 0;i <= n; i++) {
        dp[i][0] = 0; 
    }

    for(int i = 0; i <= w; i++) {
        dp[i][0] = 0;
    }

    for(int i = 1; i <= w; i++) {
        for(int j = 1; j <= n; j++) {
            if(wei[j] <= i) {
                dp[i][j] = max(dp[i-wei[j]][j-1]+val[j], dp[i][j-1]);
            }
            else {
                dp[i][j] = dp[i][j-1];
            }
        }
    }
}

int main() {

    int n; cin >> n;
    vector<int> wei(n), val(n);
    for(int i =0; i < n; i++) {
        cin >> wei[i];
    }
    for(int i =0; i < n; i++) {
        cin >> val[i];
    }
    int w; cin >> w;

    vector<vector<int>> dp(w+1, vector<int> (n+1, -1));

    knap(wei, val, dp, w, n);

    int ans = dp[w][n];

    cout << ans << endl;
}

/*

3
1 2 3 
60 100 120
5

*/