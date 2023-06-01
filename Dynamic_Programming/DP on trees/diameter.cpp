#include "../../myHeaders.h"
using namespace std;

struct node {
    int data;
    struct node *left, *right;
};

int hei(node* nd, unordered_map<node*, int> &heigh) {
    if(nd == NULL) return 0;

    if(heigh.find(nd) != heigh.end()) {
        return heigh[nd];
    }

    return heigh[nd] = max(hei(nd->left, heigh), hei(nd->right, heigh)) + 1;
}

int sol(struct node* nd, unordered_map<node*, int> &heigh) {
    if(nd == NULL) return 0;

    int lh = hei(nd->left, heigh);
    int rh = hei(nd->right, heigh);

    int ans = lh+rh+1;
    
    return max(ans, max(sol(nd->left, heigh), sol(nd->right, heigh)));
}

void solve(node *root) {
    unordered_map<node*, int> heig;

    int dia = sol(root, heig);

    cout << "Diameter of the tree is : " << dia << endl;
}

int main() {
    struct node* root;

    solve(root);
}

/*
https://leetcode.com/problems/diameter-of-binary-tree/
*/