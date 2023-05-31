#include "../../../myHeaders.h"
using namespace std;

int knapsack(vector<int> &wei, vector<int> &val, int w, int n) {

    if(w <= 0 || n == 0) {
        return 0;
    }

    int a = INT_MIN, b = INT_MIN;
    if(wei[n-1] <= w) {
        a = knapsack(wei, val, w-wei[n-1], n-1) + val[n-1];
    }
    else {
        b = knapsack(wei, val, w, n-1);
    }

    return max(a, b);
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

    int ans = knapsack(wei, val, w, n);
    cout << ans << endl;
}

/*

3
1 2 3 
60 100 120
5

*/