#include <bits/stdc++.h>
using namespace std;
template <class T>
bool umin(T& a, const T& b) {
  return a > b ? a = b, true : false;
}
template <class T>
bool umax(T& a, const T& b) {
  return a < b ? a = b, true : false;
}
template <long long sz>
using tut = array<long long, sz>;
void usaco(string s) {
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
const long long N = 3e5 + 5;
const long long mod = (119 << 23) + 1;
const long long inf = 1e18;
const double Pi = acos(-1);
const double eps = 1e-13;
void add(long long& a, long long b, long long mod = ::mod) {
  a = (a + b) % mod;
}
void sub(long long& a, long long b, long long mod = ::mod) {
  a = ((a - b) % mod + mod) % mod;
}
void mul(long long& a, long long b, long long mod = ::mod) {
  a = (a * 1ll * b) % mod;
}
long long n, m, k, t, q, ans, res, a[N];
long long rr[N];
struct tree {
  long long tree[N + 1];
  void add(long long i, long long v) {
    for (i++; i <= N; i += (i & -i)) tree[i] += v;
  }
  long long get(long long i) {
    long long rr = 0;
    for (i++; i > 0; i -= (i & -i)) rr += tree[i];
    return rr;
  }
  long long get(long long l, long long r) {
    return get(r) - (l ? get(l - 1) : 0);
  }
} tree, cnt;
void solve(long long t_case) {
  cin >> n;
  for (long long i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (long long i = 1; i <= n; i++) {
    long long ans = 0;
    for (long long j = 0; j < N; j += a[i]) {
      long long k = min(N, j + a[i]) - 1;
      ans += tree.get(j, k) - cnt.get(j, k) * j;
    }
    tree.add(a[i], a[i]), cnt.add(a[i], 1);
    rr[i] = ans;
  }
  memset(tree.tree, 0, sizeof tree.tree);
  for (long long i = 1; i <= n; i++) {
    for (long long j = 0; j < N; j += a[i]) {
      long long k = min(N, j + a[i]);
      tree.add(j, j);
      tree.add(k, -j);
    }
  }
  for (long long i = n; i > 0; i--) {
    rr[i] += a[i] * i - tree.get(0, a[i]);
    for (long long j = 0; j < N; j += a[i]) {
      long long k = min(N, j + a[i]);
      tree.add(j, -j);
      tree.add(k, j);
    }
  }
  for (long long i = 1; i <= n; i++) {
    rr[i] += rr[i - 1];
    cout << rr[i] << " ";
  }
  cout << "\n";
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  if (0) {
    long long t;
    cin >> t;
    for (long long t_case = 1; t_case <= t; t_case++) solve(t_case);
  } else
    solve(1);
  return 0;
}
