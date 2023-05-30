#include "../myHeaders.h"
using namespace std;


int find(vector<int> &parent, int u ) {
    if(parent[u] != u) {
        parent[u] = find(parent, parent[u]);
    }
    return parent[u];
}

void Union(vector<int> &parent, vector<int> &rank, int u, int v) {

    int a = find(parent, u);
    int b = find(parent, v);

    if( a == b) return;

    if(rank[a] < rank[b]) {
        parent[a] = b;
    }
    else if(rank[b] < rank[a]) {
        parent[b] = a;
    }
    else {
        parent[a] = b;
        rank[b] += 1;
    }
}

void query(vector<int> &parent ) {
    int u, v; cin >> u >> v;

    int a = find(parent, u);
    int b = find(parent, v);

    if(a == b) {
        cout << "They are in same set" << endl;
    }
    else {
        cout << "They are not in same set" << endl;
    }
}

int main() {

    int n; cin >> n; 

    vector<int> rank(n,0), parent(n);

    for(int i = 0; i < n; i++) {
        parent[i] = i;
    }

    int num; cin >> num;

    for(int i = 0; i < num; i++) {
        int u,v; cin >> u >> v;
        Union(parent, rank, u, v);
    }

    query(parent);
}

/*
5

3
0 1
1 2
3 4

1 4

*/