#include <bits/stdc++.h>
using namespace std;
bool debug;
template <typename T>
struct TreePathQuery {
  vector<int> tin, tout;
  int n, root;
  vector<T> nodeVal;
  vector<int> depth;
  vector<vector<int>> adj;
  TreePathQuery(int n, int root, T (*op)(const T &a, const T &b), T sentinel)
      : n(n), root(root), adj(n), SENTINEL(sentinel), depth(n) {
    this->op = op;
  }
  void addEdge(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  T queryEx(int a, int b) {
    assert(isBuilt);
    if (a == b) return SENTINEL;
    if (isAncestor(a, b)) return dist(b, a);
    if (isAncestor(b, a)) return dist(a, b);
    int ca = lca(a, b);
    return op(dist(a, ca), dist(b, ca));
  }
  T queryIn(int a, int b) {
    assert(isBuilt);
    if (a == b) return nodeVal[a];
    if (isAncestor(a, b)) return op(nodeVal[a], dist(b, a));
    if (isAncestor(b, a)) return op(nodeVal[b], dist(a, b));
    int ca = lca(a, b);
    return op(nodeVal[ca], op(dist(a, ca), dist(b, ca)));
  }
  int nthAncestor(int u, int nth) {
    assert(isBuilt);
    for (int i = 0; nth; ++i) {
      if (nth & 1) {
        u = anc[u][i];
      }
      nth >>= 1;
    }
    return u;
  }
  int lca(int a, int b) {
    assert(isBuilt);
    if (isAncestor(a, b)) return a;
    if (isAncestor(b, a)) return b;
    for (int i = l; i >= 0; i--)
      if (!isAncestor(anc[a][i], b)) a = anc[a][i];
    return anc[a][0];
  }
  void build(vector<T> &nodeVal) {
    this->nodeVal = nodeVal;
    assert(nodeVal.size() == n);
    isBuilt = true;
    tin.resize(n);
    tout.resize(n);
    timer = 0;
    l = ceil(log2(n));
    anc.assign(n, vector<int>(l + 1));
    dp.assign(n, vector<T>(l + 1));
    dfs(root, root, 0);
  }
  bool isAncestor(int a, int b) {
    return assert(isBuilt), tin[a] <= tin[b] && tout[a] >= tout[b];
  }

 private:
  int l, timer;
  bool isBuilt = false;
  T SENTINEL = 0;
  vector<vector<int>> anc;
  vector<vector<T>> dp;
  T(*op)
  (const T &a, const T &b);
  void dfs(int u, int p, int dep) {
    depth[u] = dep;
    tin[u] = ++timer;
    anc[u][0] = p;
    dp[u][0] = nodeVal[u];
    for (int i = 1; i <= l; ++i) {
      anc[u][i] = anc[anc[u][i - 1]][i - 1];
      dp[u][i] = op(dp[anc[u][i - 1]][i - 1], dp[u][i - 1]);
    }
    for (int v : adj[u])
      if (v != p) dfs(v, u, dep + 1);
    tout[u] = ++timer;
  }
  T dist(int u, int ancestor) {
    if (u == ancestor) return nodeVal[u];
    T sum = SENTINEL;
    for (int i = l; i >= 0; i--)
      if (!isAncestor(anc[u][i], ancestor)) {
        sum = op(sum, dp[u][i]);
        u = anc[u][i];
      }
    sum = op(sum, dp[u][0]);
    return sum;
  }
};
template <typename T>
T opSum(const T &a, const T &b) {
  return a + b;
}
template <typename T>
T opMin(const T &a, const T &b) {
  return min(a, b);
}
template <typename T>
T opMax(const T &a, const T &b) {
  return max(a, b);
}
template <typename T>
T opGcd(const T &a, const T &b) {
  return __gcd(a, b);
}
template <typename T>
struct FenwickTreeSum {
 public:
  vector<T> ft;
  FenwickTreeSum(int n) { ft.assign(n + 1, 0); }
  FenwickTreeSum(vector<T> arr) {
    int n = arr.size();
    ft.assign(n + 1, 0);
    for (int i = 0; i < n; i++) update(i, arr[i]);
  }
  T query(int b) {
    b++;
    T sum = 0;
    for (; b; b -= LSOne(b)) sum = op(sum, ft[b]);
    return sum;
  }
  T rangeQuery(int a, int b) {
    return invOp(query(b), (a == 0 ? 0 : query(a - 1)));
  }
  void update(int k, T v) {
    k++;
    for (; k < ft.size(); k += LSOne(k)) ft[k] = op(ft[k], v);
  }

 private:
  int LSOne(int x) { return x & (-x); }
  T op(const T &a, const T &b) { return a + b; }
  T invOp(const T &a, const T &b) { return a - b; }
};
template <typename T>
struct SqrtLCASum {
 public:
  SqrtLCASum(const vector<T> &v)
      : n((int)v.size()), lg(log2Up(n)), v(v), clz(1 << lg), onLayer(lg + 1) {
    clz[0] = 0;
    for (int i = 1; i < (int)clz.size(); i++) clz[i] = clz[i >> 1] + 1;
    int tlg = lg;
    while (tlg > 1) {
      onLayer[tlg] = (int)layers.size();
      layers.push_back(tlg);
      tlg = (tlg + 1) >> 1;
    }
    for (int i = lg - 1; i >= 0; i--)
      onLayer[i] = max(onLayer[i], onLayer[i + 1]);
    pref.assign(layers.size(), vector<T>(n));
    suf.assign(layers.size(), vector<T>(n));
    between.assign(layers.size(), vector<T>(1 << lg));
    build(0, 0, n);
  }
  inline T query(int l, int r) {
    if (l == r) return v[l];
    if (l + 1 == r) return op(v[l], v[r]);
    int layer = onLayer[clz[l ^ r]];
    int bSzLog = (layers[layer] + 1) >> 1;
    int bCntLog = layers[layer] >> 1;
    int lBound = (l >> layers[layer]) << layers[layer];
    int lBlock = ((l - lBound) >> bSzLog) + 1;
    int rBlock = ((r - lBound) >> bSzLog) - 1;
    T ans = suf[layer][l];
    if (lBlock <= rBlock) {
      ans = op(ans, between[layer][lBound + (lBlock << bCntLog) + rBlock]);
    }
    ans = op(ans, pref[layer][r]);
    return ans;
  }

 private:
  int n, lg;
  vector<T> v, clz, layers, onLayer;
  vector<vector<T>> pref, suf, between;
  void build(int layer, int lBound, int rBound) {
    if (layer >= (int)layers.size()) return;
    int bSzLog = (layers[layer] + 1) >> 1;
    int bCntLog = layers[layer] >> 1;
    int bSz = 1 << bSzLog;
    int bCnt = 0;
    for (int l = lBound; l < rBound; l += bSz) {
      bCnt++;
      int r = min(l + bSz, rBound);
      pref[layer][l] = v[l];
      for (int i = l + 1; i < r; i++)
        pref[layer][i] = op(pref[layer][i - 1], v[i]);
      suf[layer][r - 1] = v[r - 1];
      for (int i = r - 2; i >= l; i--)
        suf[layer][i] = op(v[i], suf[layer][i + 1]);
      build(layer + 1, l, r);
    }
    for (int i = 0; i < bCnt; i++) {
      T ans;
      for (int j = i; j < bCnt; j++) {
        T add = suf[layer][lBound + (j << bSzLog)];
        ans = (i == j) ? add : op(ans, add);
        between[layer][lBound + (i << bCntLog) + j] = ans;
      }
    }
  }
  inline int log2Up(int n) {
    int res = 0;
    while ((1 << res) < n) res++;
    return res;
  }
  T op(const T &a, const T &b) { return min(a, b); }
};
template <typename T, typename RSQ>
struct TreePathQuerySum {
 public:
  int n, root;
  vector<T> nodeVal;
  TreePathQuerySum(vector<T> nodeVal, int root)
      : n(nodeVal.size()),
        root(root),
        adj(n),
        first(n),
        inOrder(n),
        last(n),
        revOrder(n),
        isBuilt(false) {
    this->nodeVal = nodeVal;
    euler.reserve(2 * n);
  }
  void addEdge(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  int getLCA(int a, int b) {
    if (!isBuilt) {
      build();
    }
    int l = first[a], r = first[b];
    if (l > r) swap(l, r);
    return revOrder[sqt->query(l, r)];
  }
  T queryIn(int a, int b) {
    int lca = getLCA(a, b);
    T lKeA = rsq->rangeQuery(first[lca], first[a]);
    T lKeB = rsq->rangeQuery(first[lca], first[b]);
    return lKeA - nodeVal[lca] + lKeB;
  }
  T queryEx(int a, int b) {
    int lca = getLCA(a, b);
    T lKeA = rsq->rangeQuery(first[lca], first[a]);
    T lKeB = rsq->rangeQuery(first[lca], first[b]);
    return lKeA - 2 * nodeVal[lca] + lKeB;
  }
  void update(int u, T val) {
    nodeVal[u] += val;
    rsq->update(first[u], val);
    rsq->update(last[u] + 1, -val);
  }
  void set(int u, T val) {
    T diff = val - nodeVal[u];
    nodeVal[u] = val;
    rsq->update(first[u], diff);
    rsq->update(last[u] + 1, -diff);
  }
  void build() {
    isBuilt = true;
    visited.assign(n, false);
    wkt = 0;
    rsq = new RSQ(vector<T>(2 * n, 0));
    dfs(root);
    sqt = new SqrtLCASum<int>(euler);
  }

 private:
  SqrtLCASum<int> *sqt;
  RSQ *rsq;
  bool isBuilt;
  vector<int> euler, first, inOrder, revOrder, last;
  vector<vector<int>> adj;
  int wkt;
  vector<bool> visited;
  void dfs(int u) {
    visited[u] = true;
    inOrder[u] = wkt++;
    first[u] = euler.size();
    rsq->update(first[u], nodeVal[u]);
    last[u] = first[u];
    revOrder[inOrder[u]] = u;
    euler.push_back(inOrder[u]);
    for (int v : adj[u])
      if (!visited[v]) {
        dfs(v);
        last[u] = euler.size();
        euler.push_back(inOrder[u]);
      }
    rsq->update(last[u] + 1, -nodeVal[u]);
  }
};
int main(int argc, char *argv[]) {
  debug = argc > 1;
  int n, q;
  scanf("%d%d", &n, &q);
  TreePathQuery<long long> graph(n, 0, opMax<long long>, 0);
  vector<long long> nodeVal(n);
  for (int i = 0; i < n; i++) {
    int x;
    scanf("%d", &x);
    nodeVal[i] = abs(x);
  }
  vector<pair<int, int>> edges;
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    u--, v--;
    graph.addEdge(u, v);
    edges.emplace_back(u, v);
  }
  graph.build(nodeVal);
  TreePathQuerySum<long long, FenwickTreeSum<long long>> tpq(nodeVal, 0);
  for (auto [a, b] : edges) {
    tpq.addEdge(a, b);
  }
  tpq.build();
  if (debug) {
    cout << "graph.depth"
         << ": ";
    for (auto i : graph.depth) {
      cout << i << ' ';
    }
    cout << endl;
  }
  int c, u, v;
  while (q--) {
    scanf("%d%d%d", &c, &u, &v);
    if (c == 1) {
      tpq.set(u - 1, abs(v));
    } else {
      u--, v--;
      if (debug) {
        cout << "u"
             << ": " << u << endl;
      }
      if (debug) {
        cout << "v"
             << ": " << v << endl;
      }
      int lca = tpq.getLCA(u, v);
      if (debug) {
        cout << "lca"
             << ": " << lca << endl;
      }
      long long ans = -1;
      if (lca == v) {
        swap(u, v);
      }
      if (u == v) {
        ans = 0;
      } else if (lca == u) {
        if (u == graph.nthAncestor(v, 1)) {
          ans = tpq.queryIn(u, v);
          if (debug) {
            cout << "ans"
                 << ": " << ans << endl;
          }
        } else {
          int step = graph.depth[v] - graph.depth[u];
          int parentV = graph.nthAncestor(v, 1);
          int childU = graph.nthAncestor(v, step - 1);
          ans = tpq.queryIn(u, v) + tpq.queryIn(childU, parentV);
        }
      } else {
        ans = tpq.queryIn(u, v) +
              tpq.queryIn(graph.nthAncestor(u, 1), graph.nthAncestor(v, 1));
      }
      printf("%lld\n", ans);
    }
  }
  return 0;
}
