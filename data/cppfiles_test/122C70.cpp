#include <bits/stdc++.h>
using namespace std;
template <class T>
void _R(T &x) {
  cin >> x;
}
void _R(int &x) { scanf("%d", &x); }
void _R(int64_t &x) { scanf("%lld", &x); }
void _R(double &x) { scanf("%lf", &x); }
void _R(char &x) { scanf(" %c", &x); }
void _R(char *x) { scanf("%s", x); }
void R() {}
template <class T, class... U>
void R(T &head, U &...tail) {
  _R(head);
  R(tail...);
}
template <class T>
void _W(const T &x) {
  cout << x;
}
void _W(const int &x) { printf("%d", x); }
void _W(const int64_t &x) { printf("%lld", x); }
void _W(const double &x) { printf("%.16f", x); }
void _W(const char &x) { putchar(x); }
void _W(const char *x) { printf("%s", x); }
template <class T, class U>
void _W(const pair<T, U> &x) {
  _W(x.first);
  putchar(' ');
  _W(x.second);
}
template <class T>
void _W(const vector<T> &x) {
  for (auto i = x.begin(); i != x.end(); _W(*i++))
    if (i != x.cbegin()) putchar(' ');
}
void W() {}
template <class T, class... U>
void W(const T &head, const U &...tail) {
  _W(head);
  putchar(sizeof...(tail) ? ' ' : '\n');
  W(tail...);
}
int MOD = 1e9 + 7;
void ADD(long long &x, long long v) {
  x = (x + v) % MOD;
  if (x < 0) x += MOD;
}
const int SIZE = 1 << 18;
struct Union_Find {
  int d[1234567], num[1234567], dif[1234567];
  void init(int n) {
    for (int i = 0; i < n; i++) {
      d[i] = i;
      num[i] = 1;
      dif[i] = 0;
    }
  }
  bool is_root(int x) { return d[x] == x; }
  int get_val(int x) {
    int v = 0;
    while (x != d[x]) {
      v ^= dif[x];
      x = d[x];
    }
    return v;
  }
  bool uu(int x, int y, int v) {
    while (x != d[x]) {
      v ^= dif[x];
      x = d[x];
    }
    while (y != d[y]) {
      v ^= dif[y];
      y = d[y];
    }
    if (x == y) {
      return !v;
    }
    if (num[x] > num[y]) {
      swap(x, y);
    }
    num[y] += num[x];
    dif[x] = v;
    d[x] = y;
    return 1;
  }
} U;
int n, m;
vector<pair<int, int> > e[SIZE];
int val[SIZE], par[SIZE];
void dfs(int x, int lt) {
  for (auto &[y, v] : e[x]) {
    if (y == lt) continue;
    val[y] = v;
    par[y] = x;
    if (v != -1) U.uu(x, y, __builtin_popcount(v) % 2);
    dfs(y, x);
  }
}
int a[SIZE], b[SIZE], p[SIZE];
void solve() {
  U.init(n + 1);
  dfs(1, 1);
  for (int i = 0; i < (m); ++i) {
    if (!U.uu(a[i], b[i], __builtin_popcount(p[i]) % 2)) {
      W("NO");
      return;
    }
  }
  W("YES");
  for (int i = (2); i <= (n); ++i) {
    if (val[i] != -1)
      W(i, par[i], val[i]);
    else {
      int v = U.get_val(i) ^ U.get_val(par[i]);
      W(i, par[i], v);
    }
  }
}
void input() {
  R(n, m);
  for (int i = (1); i <= (n); ++i) e[i].clear();
  for (int i = (1); i < (n); ++i) {
    int x, y, v;
    R(x, y, v);
    e[x].push_back({y, v});
    e[y].push_back({x, v});
  }
  for (int i = 0; i < (m); ++i) {
    R(a[i], b[i], p[i]);
  }
}
int main() {
  int ___T;
  scanf("%d", &___T);
  for (int cs = 1; cs <= ___T; cs++) {
    input();
    solve();
  }
  return 0;
}
