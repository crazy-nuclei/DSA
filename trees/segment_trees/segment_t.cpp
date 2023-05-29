#include "../../myHeaders.h"
using namespace std;

void build(int treeNode, int st, int en, vector<int> &arr, vector<int> &tree) {

    if(st == en) {
        tree[treeNode] = arr[st];
    }
    else {
        int mid = (st+en)/2 ; 
        build(treeNode*2+1, st, mid, arr, tree);
        build(treeNode*2+2, mid+1, en, arr, tree);

        tree[treeNode] = tree[treeNode*2+1] + tree[treeNode*2+2];
    }
}

void build_tree(vector<int> &arr, vector<int> &tree) {
    build(0, 0, arr.size()-1, arr, tree );
}

int query(int treeNode, int st, int en, int l, int r, vector<int> &tree ) {
    
    if(l <= st && en <= r) {
        return tree[treeNode];
    }

    if(st >= r || en <= l ) {
        return 0; 
    }

    int mid = (st + en) / 2;
    int a = query(treeNode*2+1, st, mid, l, r, tree);
    int b = query(treeNode*2+2, mid+1, en, l, r, tree);

    return a+b;
}

int query_tree(vector<int> &tree, int l, int r, int n) {
    return query(0, 0, n-1, l, r, tree);
}

int main () {

    int n; cin >> n;
    vector<int> arr(n);
    for(int i =0 ; i< n; i++) {
        cin >> arr[i];
    }

    vector<int> tree(4*n);

    build_tree(arr, tree);

    int ans = query_tree(tree, 1, 3, arr.size()- 1);

    cout << ans << endl;
}

/*
5 
1 2 3 4 5 
*/