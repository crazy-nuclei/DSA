#include "../../myHeaders.h"
using namespace std;

int gets(vector<int> &nums ) {
    int sum = 0;
    for(int i = 0; i < nums.size(); i++) {
        sum += nums[i];
    }

    return sum;
}

void solve(vector<int> &nums, int sum ) {
    
    int su = gets(nums);
    int x = sum + su;

    if( x&1) cout << "Count : " << 0 << endl;
    x /= 2;

    vector<vector<int>> dp(x+1, vector<int> (nums.size()+1, 0));

    for(int i = 0; i < dp[0].size(); i++) {
        dp[0][i] = 1;
    }

    for(int i = 1; i < dp.size(); i++) {
        for(int j = 1; j < dp[0].size(); j++){
            if(nums[j-1] <= i) {
                dp[i][j] = dp[i-nums[j-1]][j-1] + dp[i][j-1];
            }
            else {
                dp[i][j]= dp[i][j-1];
            }
        }
    }

    cout << "Count : " << dp[x][nums.size()] << endl;
}

int main(){
    int n; cin>> n; 
    vector<int> nums(n);
    for(int i = 0; i < nums.size(); i++) {
        cin >> nums[i];
    }
    int sum; cin >> sum;

    solve(nums, sum);
}

/*
You have to give addition or subtration operator to eact element in nums arr

5
1 1 1 1 1
3

4 
1 1 2 3
1
*/