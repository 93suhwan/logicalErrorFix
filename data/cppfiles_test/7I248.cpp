#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
inline long long ab(long long x) { return x < 0 ? -x : x; }
inline long long gcd(long long a, long long b) {
  return b == 0 ? a : gcd(b, a % b);
}
long long a[N], dt[N];
struct sgt {
  long long g[N << 4];
  void bld(int u, int l, int r) {
    if (l == r) {
      g[u] = ab(dt[l]);
      return;
    }
    int mid = l + r >> 1;
    bld(u << 1, l, mid);
    bld(u << 1 | 1, mid + 1, r);
    g[u] = gcd(g[u << 1], g[u << 1 | 1]);
  }
  long long qry(int u, int l, int r, int ql, int qr) {
    if (ql <= l && r <= qr) return g[u];
    int mid = l + r >> 1;
    long long a = 0, b = 0;
    if (ql <= mid) a = qry(u << 1, l, mid, ql, qr);
    if (mid < qr) b = qry(u << 1 | 1, mid + 1, r, ql, qr);
    if (a < b) swap(a, b);
    return gcd(a, b);
  }
} T;
int n;
bool chk(int x) {
  for (int i = 1; i + x - 1 <= n; ++i)
    if (T.qry(1, 1, n, i, i + x - 1) != 1) return 1;
  return 0;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int _;
  cin >> _;
  while (_--) {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
      cin >> a[i];
    }
    if (n == 1) {
      cout << "1\n";
      continue;
    } else if (n == 2) {
      if (ab(a[2] - a[1]) == 1)
        cout << "1\n";
      else
        cout << "2\n";
      continue;
    }
    for (int i = 1; i < n; ++i) dt[i] = a[i + 1] - a[i];
    --n;
    T.bld(1, 1, n);
    int l = 1, r = n, mid;
    while (l != r) {
      mid = l + r + 1 >> 1;
      if (chk(mid))
        l = mid;
      else
        r = mid - 1;
    }
    cout << l + 1 << '\n';
  }
  return 0;
}
