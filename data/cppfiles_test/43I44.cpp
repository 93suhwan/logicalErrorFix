#include <bits/stdc++.h>
using namespace std;

template <typename T = int>
class tree {
  public:
    struct edge {
        int from;
        int to;
        T cost;
    };

    int n;
    vector<edge> edges;
    vector<vector<int>> g;
    vector<int> pv;
    vector<int> pe;
    vector<int> depth;
    vector<int> pos;
    vector<int> end;
    int root;
    int tim;
    
    int h;
    vector<vector<int>> anc;
    
    tree() { }

    tree(int _n) : n(_n) {
        g.resize(n);
        root = -1;
    }

    void add(int from, int to, T cost = 1) {
        assert(0 <= from && from < n && 0 <= to && to < n);
        int id = edges.size();
        assert(id < n - 1);
        g[from].push_back(id);
        g[to].push_back(id);
        edges.push_back({from, to, cost});
    }

    void init() {
        pv = vector<int>(n, -1);
        pe = vector<int>(n, -1);
        depth = vector<int>(n, -1);
        tim = 0;
        pos = vector<int>(n, -1);
        end = vector<int>(n, -1);
    }

    void dfs_from(int v) {
        init();
        root = v;
        pv[v] = -1;
        pe[v] = -1;
        depth[v] = 0;
        dfs(v);
    }
    
    bool is_anc(int a, int b) const {
        return pos[a] <= pos[b] && end[b] <= end[a];
    }

    void prec_kth_anc() {
        assert(!pv.empty());
        int max_depth = *max_element(depth.begin(), depth.end());
        for (h = 1; (1 << (h + 1)) <= max_depth; h++);
        anc.resize(n);
        for (int i = 0; i < n; i++) {
            anc[i].resize(h);
            anc[i][0] = pv[i];
        }
        for (int j = 1; j < h; j++) {
            for (int i = 0; i < n; i++) {
                anc[i][j] = (anc[i][j - 1] == -1 ? -1 : anc[anc[i][j - 1]][j - 1]);
            }
        }
    }

    int go_up(int v, int up) {
        assert(!anc.empty());
        up = min(up, (1 << h) - 1);
        for (int j = h - 1; j >= 0; j--) {
            if (up & (1 << j)) {
                v = anc[v][j];
                if (v == -1) break;
            }
        }
        return v;
    }

    int lca(int a, int b) {
        if (depth[a] < depth[b]) swap(a, b);
        a = go_up(a, depth[a] - depth[b]);
        if (a == b) return a;
        for (int i = h - 1; i >= 0; i--) {
            if (anc[a][i] != anc[b][i]) {
                a = anc[a][i];
                b = anc[b][i];
            }
        }
        return anc[a][0]; 
    }

  private:
    void dfs(int v) {
        pos[v] = tim++;
        for (int id : g[v]) {
            if (id == pe[v]) continue;
            edge &e = edges[id];
            int to = e.from ^ e.to ^ v;
            pv[to] = v;
            pe[to] = id;
            depth[to] = depth[v] + 1;
            dfs(to);
        }
        end[v] = tim - 1;
    }
};

tree t;
vector<vector<int>> mx;

void build_path_queries() {
    if (t.anc.empty()) {
        t.prec_kth_anc();
    }
    mx = vector<vector<int>>(t.n);
    for (int i = 0; i < t.n; i++) {
        mx[i].resize(t.h);
        mx[i][0] = (t.pe[i] == -1 ? 0 : t.edges[t.pe[i]].cost);
    }
    for (int j = 1; j < t.h; j++) {
        for (int i = 0; i < t.n; i++) {
            mx[i][j] = mx[i][j - 1];
            if (t.anc[i][j - 1] != -1) {
                mx[i][j] = max(mx[i][j], mx[t.anc[i][j - 1]][j - 1]);
            }
        }
    }
}

int path_max(int v, int u) {
    int maximum = 0;
    for (int i = t.h - 1; i >= 0; i--) {
        if (t.anc[v][i] != -1 && !t.is_anc(t.anc[v][i], u)) {
            maximum = max(maximum, mx[v][i]);
            v = t.anc[v][i];
        }
        if (t.anc[u][i] != -1 && !t.is_anc(t.anc[u][i], v)) {
            maximum = max(maximum, mx[u][i]);
            u = t.anc[u][i];
        }
    }
    if (!t.is_anc(v, u)) maximum = max(maximum, mx[v][0]);
    if (!t.is_anc(u, v)) maximum = max(maximum, mx[u][0]);
    return maximum;
}

struct dsu {
    vector<int> id;
    vector<int> mx;
    vector<int> v;
    vector<int> mx_in;

    dsu(int n, const vector<int> &val) {
        id = vector<int>(n, -1);
        mx = val;
        v = vector<int>(n);
        iota(v.begin(), v.end(), 0);
        mx_in = vector<int>(n, 0);
    }

    int find(int a) {
        while (id[a] >= 0) {
            if (id[id[a]] >= 0) id[a] = id[id[a]];
            a = id[a];
        }
        return a;
    }

    bool unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return false;
        if (id[a] > id[b]) {
            swap(a, b);
        }
        id[a] += id[b];
        id[b] = a;
        if (mx[a] == mx[b]) {
            int max_in_path = path_max(v[a], v[b]);
            mx_in[a] = max({mx_in[a], mx_in[b], max_in_path});
        } else if (mx[a] < mx[b]) {
            mx_in[a] = mx_in[b];
            v[a] = v[b];
        }
        mx[a] = max(mx[a], mx[b]);
        return true;
    }
};

void foo() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> values;
    t = tree(n);
    vector<int> edge_cap;
    for (int i = 0; i < n - 1; i++) {
        int x, y, c, tl;
        cin >> x >> y >> c >> tl;
        x--; y--;
        t.add(x, y, tl);
        edge_cap.push_back(c);
        values.push_back(c);
    }
    t.dfs_from(0);
    build_path_queries();
    vector<int> qv(q), qc(q);
    for (int i = 0; i < q; i++) {
        cin >> qc[i] >> qv[i];
        qv[i]--;
        values.push_back(qc[i]);
    }
    
    sort(values.begin(), values.end());
    values.erase(unique(values.begin(), values.end()), values.end());
    const int M = values.size();
    vector<vector<int>> ce(M);
    for (int i = 0; i < n - 1; i++) {
        edge_cap[i] = lower_bound(values.begin(), values.end(), edge_cap[i]) - values.begin();
        ce[edge_cap[i]].push_back(i);
    }
    vector<vector<int>> cq(M);
    for (int i = 0; i < q; i++) {
        qc[i] = lower_bound(values.begin(), values.end(), qc[i]) - values.begin();
        cq[qc[i]].push_back(i);
    }
    
    vector<pair<int,int>> ans(q);
    dsu d(n, a);
    for (int i = M - 1; i >= 0; i--) {
        for (int id : ce[i]) {
            const tree<int>::edge &e = t.edges[id];
            d.unite(e.from, e.to);
        }
        for (int id : cq[i]) {
            const int p = d.find(qv[id]);
            ans[id] = make_pair(d.mx[p], max(d.mx_in[p], path_max(qv[id], d.v[p])));
        }
    }
    for (const auto &[x, y] : ans) {
        cout << x << ' ' << y << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    foo();
}
