#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
class FenwickTree {
 private:
  vector<int> fen;
  int sz;

 public:
  FenwickTree(const int &n, const int &val) {
    fen.resize(n, val);
    sz = n - 1;
  }
  void update(int pos, int val) {
    for (int i = pos; i <= sz; i += i & -i) fen[i] += val;
  }
  int getsum(int pos) {
    int ans = 0;
    for (int i = pos; i; i &= i - 1) ans += fen[i];
    return ans;
  }
};
struct Node {
  int L, R, minval, idx;
  Node(int _L = 0, int _R = 0, int _minval = 0, int _idx = 0) {
    L = _L;
    R = _R;
    minval = _minval;
    idx = _idx;
  }
};
class SegmentTree {
 private:
  vector<Node> st;
  vector<int> lazy;
  Node take_min(const Node &nd1, const Node &nd2) {
    Node nd;
    nd.L = nd1.L;
    nd.R = nd2.R;
    nd.minval = min(nd1.minval, nd2.minval);
    if (nd1.minval < nd2.minval)
      nd.idx = nd1.idx;
    else
      nd.idx = nd2.idx;
    return nd;
  }
  void build_tree(int x, int l, int r, const vector<int> &V) {
    st[x].L = l;
    st[x].R = r;
    if (l == r) {
      st[x].minval = V[l];
      st[x].idx = l;
      return;
    }
    int mid = (l + r) / 2;
    build_tree(2 * x, l, mid, V);
    build_tree(2 * x + 1, mid + 1, r, V);
    st[x] = take_min(st[2 * x], st[2 * x + 1]);
  }
  void propagate(int x) {
    if (lazy[x] == 0) return;
    int &t = lazy[x];
    for (int i = 0; i < 2; ++i) {
      st[2 * x + i].minval += t;
      lazy[2 * x + i] += t;
    }
    t = 0;
  }
  Node getmin(int u, int v, int x = 1) {
    if (u > st[x].R || v < st[x].L) return Node(0, 0, INF, -1);
    if (u <= st[x].L && st[x].R <= v) return st[x];
    propagate(x);
    return take_min(getmin(u, v, 2 * x), getmin(u, v, 2 * x + 1));
  }

 public:
  SegmentTree(const vector<int> &V) {
    int sz = V.size();
    st.resize(4 * sz);
    lazy.resize(4 * sz);
    build_tree(1, 0, sz - 1, V);
  }
  void update(int u, int v, int val, int x = 1) {
    if (u > st[x].R || v < st[x].L) return;
    if (u <= st[x].L && st[x].R <= v) {
      st[x].minval += val;
      lazy[x] += val;
      return;
    }
    propagate(x);
    update(u, v, val, 2 * x);
    update(u, v, val, 2 * x + 1);
    st[x] = take_min(st[2 * x], st[2 * x + 1]);
  }
  int getposmin(int u, int v, int x = 1) {
    Node ans = getmin(u, v);
    return ans.idx;
  }
};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    vector<int> oA(n + 1);
    vector<pair<int, int>> A(n + 1);
    for (int i = 1; i <= n; ++i) {
      cin >> oA[i];
      A[i] = {oA[i], i};
    }
    vector<int> B(m + 1);
    for (int i = 1; i <= m; ++i) {
      cin >> B[i];
    }
    sort(A.begin() + 1, A.end());
    sort(B.begin() + 1, B.end());
    vector<int> pref(n + 1, 1), state(n + 1, 1);
    pref[0] = state[0] = 0;
    for (int i = 1; i <= n; ++i) pref[i] += pref[i - 1];
    SegmentTree segt(pref);
    int idx1 = 0, idx2 = 0;
    vector<int> opt_pos(m + 1, 0);
    for (int cur = 1; cur <= m; ++cur) {
      while (idx1 < n && A[idx1 + 1].first < B[cur]) {
        int p = A[++idx1].second;
        if (p > opt_pos[cur - 1]) {
          segt.update(p, n, -state[p] - 1);
          state[p] = -1;
        }
      }
      while (idx2 < n && A[idx2 + 1].first <= B[cur]) {
        ++idx2;
        if (A[idx2].first == B[cur]) {
          int p = A[idx2].second;
          if (p > opt_pos[cur - 1]) {
            segt.update(p, n, -state[p]);
            state[p] = 0;
          }
        }
      }
      assert(opt_pos[cur - 1] <= n);
      opt_pos[cur] = segt.getposmin(opt_pos[cur - 1], n);
    }
    vector<pair<int, int>> final_arr;
    final_arr.reserve(n + m);
    int idx = 1;
    for (int i = 1; i <= m; ++i) {
      while (idx <= opt_pos[i])
        final_arr.push_back({oA[idx++], final_arr.size() + 1});
      final_arr.push_back({B[i], final_arr.size() + 1});
    }
    while (idx <= n) final_arr.push_back({oA[idx++], final_arr.size() + 1});
    sort(final_arr.begin(), final_arr.end());
    FenwickTree fen(n + m + 1, 0);
    int64_t ans = 0;
    for (int i = int(final_arr.size()) - 1; i >= 0; --i) {
      ans += fen.getsum(final_arr[i].second);
      fen.update(final_arr[i].second, 1);
    }
    cout << ans << '\n';
  }
  return 0;
}
