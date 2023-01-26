#include <bits/stdc++.h>
#pragma GCC optimize("O2,unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,mmx,avx,avx2")
using namespace std;
const long double PI = 3.14159265358979323846L;
const long double E = 2.71828182845904523536L;
const int INF = (1 << 30);
const long long LINF = 1e18;
const long double eps = 1e-10;
const int MAXN = 4e5 + 5;
int a[MAXN], b[MAXN];
const long long mod = 1e9 + 7;
struct Tree {
  int a, b, m;
  Tree *left = nullptr, *right = nullptr;
  long long x = 0;
  Tree(int na, int nb) {
    a = na;
    b = nb;
    m = (a + b) / 2;
    if (a != b) {
      left = new Tree(a, m);
      right = new Tree(m + 1, b);
    }
  }
  void add(int k, int v) {
    x = (x + v >= mod ? x + v - mod : x + v);
    if (a == b) {
      return;
    }
    if (k > m) {
      right->add(k, v);
    } else {
      left->add(k, v);
    }
  }
  long long qry(int l, int r) {
    if (l <= a && r >= b) {
      return x;
    }
    if (l > b || r < a) {
      return 0;
    }
    return (left->qry(l, r) + right->qry(l, r));
  }
};
int v[MAXN];
int d[MAXN];
Tree t(0, MAXN);
long long r[MAXN];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  std::cout << std::fixed << std::setprecision(20);
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i] >> b[i];
    v[a[i]] = i + n;
    v[b[i]] = i;
  }
  int m;
  cin >> m;
  long long ans = 0;
  for (int i = 0; i < m; i++) {
    int x;
    cin >> x;
    d[x] = 1;
  }
  int last = 0;
  for (int i = 1; i <= 2 * n; i++) {
    r[i] = r[i - 1] + 1;
    int k = v[i];
    if (k > n) {
      continue;
    }
    last = i;
    long long add = (t.qry(a[k], b[k]) + 1) % mod;
    r[i] = (r[i] + add) % mod;
    t.add(a[k], add);
  }
  int stop = 0;
  for (int i = 2 * n; i >= stop; i--) {
    int k = v[i];
    if (k > n) {
      continue;
    }
    long long add = (t.qry(a[k] + 1, b[k]) + 1) % mod;
    if (d[k]) {
      ans += t.qry(stop, a[k]);
      ans %= mod;
      stop = max(stop, a[k] + 1);
    }
    t.add(a[k], mod - add);
  }
  cout << ans << '\n';
}
