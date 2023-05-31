#include "../../myHeaders.h"
using namespace std;


int gets(vector<int> &nums) {
    int sum = 0;
    for(int i = 0; i < nums.size(); i++) {
        sum += nums[i];
    }
    return sum;
}

bool check(vector<int> &nums) {
   
   int sum = gets(nums);

    if(sum&1) return false;
    else return true;
}

void sol(vector<int> &nums, vector<vector<int>> &dp) {

    for(int i = 0; i < dp[0].size(); i++) {
        dp[0][i] = 1;
    }

    for(int i = 1; i < dp.size(); i++) {
        for(int j = 1; j < dp[0].size(); j++) {
            if(nums[j] <= i) {
                dp[i][j] = dp[i-nums[j]][j-1] || dp[i][j-1];
            } 
            else {
                dp[i][j] = dp[i][j-1];
            }
        }
    }
}


void solve(vector<int> &nums) {
    bool ch = check(nums);

    if(ch == false) {
        cout << "False" << endl;
        return;
    }

    int sum = gets(nums);
    sum /= 2;

    vector<vector<int>> dp(sum+1, vector<int> (nums.size()+1, 0));

    sol(nums, dp);

    if(dp[sum][nums.size()]) cout << "True" << endl;
    else cout << "False" << endl;
}

int main() {
    int n; cin >> n;
    vector<int> nums(n);
    for(int i =0; i <n; i++) {
        cin >> nums[i];
    }

    solve(nums);
}

/*
4
1 5 11 5

3
1 5 3 
*/
