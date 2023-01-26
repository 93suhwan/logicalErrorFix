#include <bits/stdc++.h>
std::mt19937 rng(
    (unsigned int)std::chrono::steady_clock::now().time_since_epoch().count());
using namespace std;
struct segtree {
  int treesize;
  vector<pair<long long int, long long int> > values;
  vector<long long int> operations;
  long long int IDENTITY_ELEMENT = 0;
  long long int NO_OPERATION = 0;
  void build(int x, int l, int r, vector<int> &a) {
    if (l == r) {
      if (l < a.size()) {
        values[x] = make_pair(a[l], l);
      } else {
        values[x] = make_pair(IDENTITY_ELEMENT, -1);
      }
      return;
    }
    int mid = (l + r) / 2;
    build(2 * x + 1, l, mid, a);
    build(2 * x + 2, mid + 1, r, a);
    values[x] = calc_op(values[2 * x + 1], values[2 * x + 2]);
  }
  void init(int n, vector<int> &a) {
    treesize = 1;
    while (treesize < n) {
      treesize *= 2;
    }
    operations.assign(2 * treesize, NO_OPERATION);
    values.resize(2 * treesize);
    build(0, 0, treesize - 1, a);
  }
  inline pair<long long int, long long int> modify_op(
      pair<long long int, long long int> a, long long int b,
      long long int len) {
    return make_pair(a.first + b, a.second);
  }
  inline pair<long long int, long long int> calc_op(
      pair<long long int, long long int> a,
      pair<long long int, long long int> b) {
    return a.first >= b.first ? a : b;
  }
  inline void apply_modify_op(pair<long long int, long long int> &a,
                              long long int b, long long int len) {
    a = modify_op(a, b, len);
  }
  inline void propagate(int x, int l, int r) {
    if (x >= treesize - 1) return;
    int mid = (l + r) / 2;
    operations[2 * x + 1] += operations[x];
    operations[2 * x + 2] += operations[x];
    apply_modify_op(values[2 * x + 1], operations[x], mid - l + 1);
    apply_modify_op(values[2 * x + 2], operations[x], r - mid);
    operations[x] = NO_OPERATION;
  }
  void modify(long long int val, int ql, int qr, int curr, int l, int r) {
    propagate(curr, l, r);
    if (l > qr || ql > r) {
      return;
    }
    if (l >= ql && r <= qr) {
      operations[curr] += val;
      apply_modify_op(values[curr], val, r - l + 1);
      return;
    }
    int mid = (l + r) / 2;
    modify(val, ql, qr, 2 * curr + 1, l, mid);
    modify(val, ql, qr, 2 * curr + 2, mid + 1, r);
    values[curr] = calc_op(values[2 * curr + 1], values[2 * curr + 2]);
  }
  void modify(long long int val, int ql, int qr) {
    modify(val, ql, qr, 0, 0, treesize - 1);
  }
  pair<long long int, long long int> calc(int ql, int qr, int curr, int l,
                                          int r) {
    propagate(curr, l, r);
    if (l > qr || ql > r) {
      return make_pair(IDENTITY_ELEMENT, -1);
    }
    if (l >= ql && r <= qr) {
      return values[curr];
    }
    int mid = (l + r) / 2;
    pair<long long int, long long int> m1 = calc(ql, qr, 2 * curr + 1, l, mid);
    pair<long long int, long long int> m2 =
        calc(ql, qr, 2 * curr + 2, mid + 1, r);
    pair<long long int, long long int> res = calc_op(m1, m2);
    return res;
  }
  pair<long long int, long long int> calc(int ql, int qr) {
    return calc(ql, qr, 0, 0, treesize - 1);
  }
};
void solve(int ttt) {
  int n, k;
  cin >> n >> k;
  vector<vector<int> > adj(n);
  for (long long int i = 0; i < n - 1; i++) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  vector<int> inTime(n), outTime(n);
  vector<int> par(n);
  par[0] = -1;
  vector<int> depths(n);
  int t = 0;
  int d = 1;
  vector<bool> vis(n, false);
  function<void(int)> dfs = [&](int x) {
    vis[x] = true;
    inTime[x] = t;
    depths[x] = d;
    d++;
    t++;
    for (auto &i : adj[x]) {
      if (!vis[i]) {
        par[i] = x;
        dfs(i);
      }
    }
    outTime[x] = t - 1;
    d--;
  };
  dfs(0);
  segtree st;
  vector<int> tmpDepths(n);
  vector<int> invInTime(n);
  for (long long int i = 0; i < n; i++) invInTime[inTime[i]] = i;
  for (long long int i = 0; i < n; i++) {
    tmpDepths[inTime[i]] = depths[i];
  }
  st.init(n, tmpDepths);
  vector<int> mxValues(n);
  vector<bool> marked(n, false);
  int c = 0;
  for (int i = 0; i < n; i++) {
    pair<long long int, long long int> cur = st.values[0];
    if (cur.first == 0) {
      mxValues[i] = c;
      continue;
    }
    vector<int> ancest;
    int x = invInTime[cur.second];
    c += cur.first;
    while (x != -1 && !marked[x]) {
      marked[x] = true;
      ancest.push_back(x);
      x = par[x];
    }
    while (!ancest.empty()) {
      int b = ancest.back();
      ancest.pop_back();
      st.modify(-1, inTime[b], outTime[b]);
    }
    mxValues[i] = c;
  }
  long long int res = -(long long int)(n / 2) * (n - n / 2);
  for (long long int i = 0; i < k; i++) {
    long long int r = (i + 1);
    long long int b = min(n - mxValues[i], n / 2);
    long long int w = n - r - b;
    res = max(res, w * (r - b));
  }
  cout << res << "\n";
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int ttt;
  ttt = 1;
  for (long long int i = 0; i < ttt; i++) solve(i);
}
