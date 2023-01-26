#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
using pii = pair<int, int>;
void debug() { cout << "\n"; };
template <typename T, typename... Targs>
void debug(T t, Targs... args) {
  cout << t << " ";
  debug(args...);
}
template <typename T1, typename T2>
inline ostream& operator<<(ostream& os, const pair<T1, T2>& p) {
  return os << "(" << p.first << ", " << p.second << ")";
}
template <typename T>
inline ostream& operator<<(ostream& os, const vector<T>& v) {
  for (auto& t : v) {
    os << t << " ";
  }
  return os;
}
template <typename T>
inline ostream& operator<<(ostream& os, const vector<vector<T>>& m) {
  for (auto& v : m) {
    for (auto& t : v) {
      os << t << " ";
    }
    os << "\n";
  }
  return os;
}
template <typename T>
inline ostream& operator<<(ostream& os, const set<T>& v) {
  for (auto& t : v) {
    os << t << " ";
  }
  return os;
}
template <typename K, typename V>
inline ostream& operator<<(ostream& os, const map<K, V>& m) {
  for (auto& p : m) {
    os << p.first << " -> " << p.second << "\n";
  }
  return os;
}
template <typename NType, typename DType>
class PURQ {
 public:
  PURQ(int N_, const vector<DType>& data) : N(N_), st(4 * N_) {
    build(1, 1, N, data);
  }
  NType query(int lo, int hi) { return query(1, 1, N, lo, hi); }
  void update(int pos, DType d) { update(1, 1, N, pos, d); }

 private:
  int N;
  vector<NType> st;
  void build(int v, int tl, int tr, const vector<DType>& data) {
    if (tl >= tr) {
      st[v] = NType(tl, data[tl]);
      return;
    }
    int tm = tl + (tr - tl) / 2;
    build(2 * v, tl, tm, data);
    build(2 * v + 1, tm + 1, tr, data);
    st[v] = st[2 * v] * st[2 * v + 1];
  }
  NType query(int v, int tl, int tr, int lo, int hi) {
    if (lo > hi) {
      return NType();
    }
    if (tl == lo && tr == hi) {
      return st[v];
    }
    int tm = tl + (tr - tl) / 2;
    NType left = query(2 * v, tl, tm, lo, min(tm, hi));
    NType right = query(2 * v + 1, tm + 1, tr, max(lo, tm + 1), hi);
    return left * right;
  }
  void update(int v, int tl, int tr, int pos, DType d) {
    if (tl >= tr) {
      st[v] = NType(pos, d);
      return;
    }
    int tm = tl + (tr - tl) / 2;
    if (pos <= tm) {
      update(2 * v, tl, tm, pos, d);
    } else {
      update(2 * v + 1, tm + 1, tr, pos, d);
    }
    st[v] = st[2 * v] * st[2 * v + 1];
  }
};
const int INF = 2 * 1e9;
struct Node {
  int min_val, min_idx;
  Node(int i, int x) : min_idx(i), min_val(x) {}
  Node() : min_idx(-1), min_val(INF) {}
};
Node operator*(const Node& l, const Node& r) {
  Node ret;
  ret.min_val = min(l.min_val, r.min_val);
  ret.min_idx = l.min_val <= r.min_val ? l.min_idx : r.min_idx;
  return ret;
}
using SegTree = PURQ<Node, int>;
int N;
vector<int> A, B;
vector<vector<int>> G;
vector<int> dist, jump;
void solve() {
  dist.assign(N + 1, INF);
  jump.assign(N + 1, INF);
  SegTree st(N, A);
  queue<int> q;
  for (int u = 1; u <= (int)N; u++) {
    if (A[u] <= 0) {
      dist[u] = 1;
      jump[u] = 0;
      q.push(u);
      st.update(u, INF);
    }
  }
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int v : G[u]) {
      Node node = st.query(v + 1, N);
      int val = node.min_val;
      int idx = node.min_idx;
      while (val <= v) {
        dist[idx] = dist[u] + 1;
        jump[idx] = v;
        q.push(idx);
        st.update(idx, INF);
        node = st.query(v + 1, N);
        val = node.min_val;
        idx = node.min_idx;
      }
    }
  }
}
void print_path() {
  int u = N;
  while (u != 0) {
    u = jump[u];
    cout << u << " ";
    u += B[u];
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N;
  A.assign(N + 1, 0);
  B.assign(N + 1, 0);
  G.assign(N + 1, vector<int>());
  for (int i = 1; i <= (int)N; i++) {
    cin >> A[i];
    A[i] = i - A[i];
  }
  for (int i = 1; i <= (int)N; i++) {
    cin >> B[i];
    G[i + B[i]].push_back(i);
  }
  solve();
  int ans = dist[N];
  debug(ans < INF ? ans : -1);
  if (ans < INF) {
    print_path();
    debug();
  }
}
