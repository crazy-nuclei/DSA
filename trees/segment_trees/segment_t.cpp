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

    if(st > r || en < l ) {
        return 0; 
    }

    int mid = (st + en) / 2;
    int a = query(treeNode*2+1, st, mid, l, r, tree);
    int b = query(treeNode*2+2, mid+1, en, l, r, tree);

    return a+b;
}

int query_tree(int l, int r, vector<int> &tree, vector<int> & arr) {
    return query(0, 0, arr.size()-1, l, r, tree);
}

int update(int treeNode, int st, int en, int ind, int val, vector<int> &tree ) {
    
    if(st == en ) {
        if(st == ind) {
            tree[treeNode] = val;
        }
        return tree[treeNode];
    }
    
    if(ind < st || ind > en) {
        return tree[treeNode];
    }

    int mid = (st + en) /2 ;
    int a = update(treeNode*2 +1, st, mid, ind, val, tree);
    int b = update(treeNode*2 +2, mid+1, en, ind, val, tree);
    tree[treeNode] = a+b;

    return tree[treeNode];
}

void update_tree( int ind, int val, vector<int> &tree, vector<int> &arr) {
    arr[ind] = val; 
    update(0, 0, arr.size()-1, ind, val, tree);
}

int main () {

    int n; cin >> n;
    vector<int> arr(n);
    for(int i =0 ; i< n; i++) {
        cin >> arr[i];
    }

    vector<int> tree(4*n);

    build_tree(arr, tree);

    int ans = query_tree(1, 3, tree, arr);
    cout << ans << endl;
    update_tree( 2, 5, tree, arr );
    ans = query_tree(1, 3, tree, arr);
    cout << ans << endl;
}

/*
5 
1 2 3 4 5 
*/

