#include "../../myHeaders.h"
using namespace std;

struct node {
    int data;
    struct node *left, *right;
};

int weig(node* nd, unordered_map<node*, int> & wei) {
    if(nd == NULL) return 0;

    if(wei.find(nd) != wei.end()) {
        return wei[nd];
    }

    int lw = weig(nd->left, wei);
    int rg = weig(nd->right, wei);

    int ma = max(lw, rg);
    int ans = nd->data;
    if(ma > 0 ) ans += ma;

    return wei[nd] = ans;
}

int sol(node *nd, unordered_map<node*, int> &wei) {
    if(nd == NULL) return 0;

    int lw = weig(nd->left, wei);
    int rg = weig(nd->right, wei);

    int ans = 0; 

    if(lw > 0 ) ans += lw;
    if(rg > 0 ) ans += rg;

    ans += nd->data;
    
    return max(ans, max(sol(nd->left, wei), sol(nd->right,wei)));
    
}

void solve(node * root) {

    unordered_map<node*, int> wei;
    int ans = sol(root, wei);

    cout << "The maximum path sum is : " << ans << endl;
}

int main() {
    struct node* root;
    solve(root);
}

/*
https://leetcode.com/problems/binary-tree-maximum-path-sum/
*/