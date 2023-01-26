#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline void smin(T &a, T b) {
  a = a < b ? a : b;
}
template <typename T>
inline void smax(T &a, T b) {
  a = a > b ? a : b;
}
void err(istream_iterator<string> it) { cout << endl; }
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
  cerr << *it << " = " << a << ", ";
  err(++it, args...);
}
template <typename T>
inline void Int(T &n) {
  n = 0;
  int f = 1;
  register int ch = getchar();
  for (; !isdigit(ch); ch = getchar())
    if (ch == '-') f = -1;
  for (; isdigit(ch); ch = getchar()) n = (n << 3) + (n << 1) + ch - '0';
  n = n * f;
}
template <typename T, typename TT>
inline void Int(T &n, TT &m) {
  Int(n);
  Int(m);
}
template <typename T, typename TT, typename TTT>
inline void Int(T &n, TT &m, TTT &l) {
  Int(n, m);
  Int(l);
}
const int mod = (int)1e9 + 7;
inline int add(int a, int b) {
  a += b;
  return a >= mod ? a - mod : a;
}
inline int sub(int a, int b) {
  a -= b;
  return a < 0 ? a + mod : a;
}
inline int mul(int a, int b) { return (long long)a * b % mod; }
const int inf = (int)2e9 + 5;
const long long Inf = (long long)2e18 + 5;
const int N = (int)2e5 + 5;
int bit[N];
void update(int n, int x, int val) {
  while (x <= n) {
    bit[x] += val;
    x += (x & -x);
  }
}
int query(int x) {
  int ans = 0;
  while (x > 0) {
    ans += bit[x];
    x -= (x & -x);
  }
  return ans;
}
int solve() {
  int n;
  Int(n);
  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; ++i) {
    bit[i] = 0;
    Int(a[i]);
  }
  long long ans = 0;
  std::vector<pair<int, int> > tem;
  for (int i = 1; i <= n; ++i) {
    tem.push_back({a[i], i});
  }
  sort(tem.begin(), tem.end());
  int cur = 1;
  for (int i = 0; i < n; ++i) {
    if (i > 0 and tem[i].first != tem[i - 1].first) ++cur;
    a[tem[i].second] = cur;
  }
  for (int i = 1; i <= n; ++i) {
    int x = query(a[i] - 1);
    int y = query(n) - query(a[i]);
    ans += min(x, y);
    update(n, a[i], 1);
  }
  printf("%lld\n", ans);
  return 0;
}
int main() {
  int test = 1, tc = 0;
  Int(test);
  while (test--) {
    solve();
  }
  return 0;
}
