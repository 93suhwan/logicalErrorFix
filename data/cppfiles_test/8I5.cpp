#include<bits/stdc++.h>
using namespace std;
#define int long long
#define N 100010
int n, l;
vector<int> adj[N];
int timer = 0;
vector<int> tin(N), tout(N), height(N), B(N), index(N), ill(N);
vector<vector<int>> up;
vector<int> calcd(N, 0), bit(N, 0);

int waste = 1;
void dfs(int v, int p, int h){
    tin[v] = timer++;
    up[v][0] = p;
    height[v] = h++;
    B[v] = 1;
    index[v] = waste++;
    for (int i = 1; i <= l; i++){
        up[v][i] = up[up[v][i - 1]][i - 1];
    }
    for (int u : adj[v]){
        if (u != p){
            dfs(u, v, h);
            B[v] += B[u];
        }
    }
    tout[v] = timer++;
}

bool is_ancestor(int u, int v){
    return tin[v] >= tin[u] && tout[v] <= tout[u];
}

int lca(int u, int v){
    if (is_ancestor(u, v)) return u;
    if (is_ancestor(v, u)) return v;
    for (int i = l; i >= 0; i--){
        if (!is_ancestor(up[u][i], v)) u = up[u][i];
    }
    return up[u][0];
}

int dist(int v, int u){
    int an = lca(u, v);
    return height[u] + height[v] - 2 * height[an];
}

void preprocess(int root){
    timer = 0;
    l = ceil(log2(n));
    up.assign(n + 1, vector<int>(l + 1));

    dfs(root, root, 0);
}

int k_ancestor(int v, int k){
    for (int i = l; i >= 0; i--){
        if (k >= (1 << i)){
            v = up[v][i];
            k -= (1 << i);
        }
    }
    return v;
}

void add(int idx, int val) {
    for (++idx; idx < n; idx += idx & -idx)
        bit[idx] += val;
}

void range_add(int l, int r, int val) {
    add(l, val);
    add(r + 1, -val);
}

int point_query(int idx) {
    int ret = 0;
    for (++idx; idx > 0; idx -= idx & -idx)
        ret += bit[idx];
    return ret;
}

void makeft(int v, int p){
    calcd[v] = (v == p ? 0 : calcd[p]) + ill[v];
    for (int u : adj[v]){
        if (u != p){
            makeft(u, v);
        }   
    }
}

int pathsum(int v){
    return calcd[v] + point_query(index[v]);
}

int32_t main()
{
    int q; cin >> n >> q;
    
    for (int i = 1; i <= n; i++){
        cin >> ill[i];
        ill[i] = abs(ill[i]);
    }

    for (int i = 0; i < n - 1; i++){
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    preprocess(1);
    makeft(1, 1);


    for (int i = 0; i < q; i++){
        int t; cin >> t;
        if (t == 1){
            int u, c;
            cin >> u >> c;
            c = abs(c);
            range_add(index[u], index[u] + B[u] - 1, c - ill[u]);
            ill[u] = c;
        }
        else{
            int u, v; cin >> u >> v;
            int anc = lca(u, v);
            int pv = pathsum(v), pu = pathsum(u), pa = pathsum(anc);
            cout << 2 * (pv + pu - 2 * pa + ill[anc]) - ill[v] - ill[u] << endl;
        }
    }
}