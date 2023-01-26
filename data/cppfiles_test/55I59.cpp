#include <bits/stdc++.h>
using namespace std;
string to_string(const string& s) { return '"' + s + '"'; }
string to_string(const char* s) { return to_string((string)s); }
string to_string(bool b) { return (b ? "true" : "false"); }
template <typename A, typename B>
string to_string(const pair<A, B>& p);
template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p);
template <typename T>
string to_string(const vector<T>& v) {
  string res = "{";
  for (int i = 0; i < static_cast<int>(v.size()); i++) {
    if (i > 0) res += ", ";
    res += to_string(v[i]);
  }
  res += "}";
  return res;
}
template <size_t N>
string to_string(bitset<N> v) {
  string res = "";
  for (size_t i = 0; i < N; i++) {
    res += static_cast<char>('0' + v[i]);
  }
  return res;
}
template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto& x : v) {
    if (!first) res += ", ";
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}
template <typename A, typename B>
string to_string(const pair<A, B>& p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " +
         to_string(get<2>(p)) + ")";
}
void debug_out() { cerr << '\n'; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}
const int N = 3e5 + 5;
const int MAX = 1e9;
struct SegmentTree {
  struct Node {
    pair<int, int> val, lazy;
  };
  const Node NIL{{0, N}, {0, N}};
  vector<Node> st;
  int n;
  int L(int x) { return (x << 1) + 1; }
  int R(int x) { return (x << 1) + 2; }
  int Mid(int s, int e) { return s + (e - s) / 2; }
  SegmentTree(int n) : n(n) { st.resize(n << 2, NIL); }
  Node merge(const Node& a, const Node& b) {
    return {max(a.val, b.val), NIL.lazy};
  }
  void addLazy(Node cur, pair<int, int> lazy) {
    cur.lazy = max(cur.lazy, lazy);
  }
  void push_down(int cur, int s, int e) {
    st[cur].val = max(st[cur].val, st[cur].lazy);
    if (s != e) {
      addLazy(st[L(cur)], st[cur].lazy);
      addLazy(st[R(cur)], st[cur].lazy);
    }
  }
  void increase(int cur, int s, int e, int i, int j, pair<int, int> newVal) {
    push_down(cur, s, e);
    if (s > j || e < i) return;
    if (s >= i && e <= j) {
      st[cur].lazy = newVal;
      push_down(cur, s, e);
      return;
    }
    int mid = Mid(s, e);
    increase(L(cur), s, mid, i, j, newVal);
    increase(R(cur), mid + 1, e, i, j, newVal);
    st[cur] = merge(st[L(cur)], st[R(cur)]);
  }
  void increase(int l, int r, pair<int, int> newVal) {
    increase(0, 0, n - 1, l, r, newVal);
  }
  Node query(int cur, int s, int e, int i, int j) {
    push_down(cur, s, e);
    if (s > j || e < i) return NIL;
    if (s >= i && e <= j) return st[cur];
    int mid = Mid(s, e);
    return merge(query(L(cur), s, mid, i, j), query(R(cur), mid + 1, e, i, j));
  }
  Node query(int l, int r) { return query(0, 0, n - 1, l, r); }
  void print(int cur, int s, int e) {
    if (s == e) {
      cout << st[cur].val.first << " ";
      return;
    }
    print(L(cur), s, Mid(s, e));
    print(R(cur), Mid(s, e) + 1, e);
  }
  void print() {
    print(0, 0, n - 1);
    cout << '\n';
  }
};
int n, m;
vector<pair<int, int>> row[N];
pair<int, int> ans[N];
int exist[N];
int main() {
  scanf("%d%d", &n, &m);
  map<int, int> id;
  for (int i = 0; i < m; i++) {
    int idx, l, r;
    cin >> idx >> l >> r;
    row[--idx].push_back({--l, --r});
    id[l];
    id[r];
  }
  int curId = 0;
  for (auto& x : id) {
    x.second = curId++;
  }
  for (int i = 0; i < n; i++) {
    for (auto& x : row[i]) {
      x.first = id[x.first];
      x.second = id[x.second];
    }
  }
  SegmentTree segTree(2 * m);
  for (int i = n - 1; i >= 0; i--) {
    ans[i] = {0, n};
    for (int j = 0; j < ((int)(row[i]).size()); j++) {
      auto q = segTree.query(row[i][j].first, row[i][j].second).val;
      q.first++;
      ans[i] = max(ans[i], q);
    }
    for (int j = 0; j < ((int)(row[i]).size()); j++) {
      segTree.increase(row[i][j].first, row[i][j].second, {ans[i].first, i});
    }
  }
  int st = max_element(ans, ans + n) - ans;
  int cnt = n;
  for (int cur = st; cur < n; cur = ans[cur].second) {
    exist[cur] = 1;
    cnt--;
  }
  printf("%d\n", cnt);
  for (int i = 0; i < n; i++) {
    if (!exist[i]) {
      printf("%d ", i + 1);
    }
  }
  printf("\n");
  return 0;
}
