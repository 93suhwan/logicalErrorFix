#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,fma")
using namespace std;
long long inv[601010];
long long p[601010];
long long num[601010];
long long arr[601010];
long long find(long long x) {
  if (p[x] == x) return x;
  return p[x] = find(p[x]);
}
long long uni(long long a, long long b) {
  a = find(a);
  b = find(b);
  if (a == b) return -1;
  if (num[a] > num[b]) swap(a, b);
  p[a] = b;
  inv[a] = 0;
  return b;
}
void solve() {
  long long Q;
  cin >> Q;
  long long i;
  long long cnt = 0;
  long long t, a, b;
  for (i = 1; i <= Q; i++) {
    cin >> t >> a;
    if (t == 2) cin >> b;
    if (t == 1) {
      cnt++;
      p[cnt] = cnt;
      num[cnt] = 1;
      if (inv[a]) {
        p[cnt] = inv[a];
        num[inv[a]]++;
      } else {
        arr[cnt] = a;
        inv[a] = cnt;
      }
    } else {
      if (a == b) continue;
      if (inv[a] == 0) continue;
      if (inv[b]) {
        long long x = inv[a];
        long long y = inv[b];
        long long u = uni(x, y);
        inv[a] = 0;
        inv[b] = u;
        arr[u] = b;
      } else {
        long long x = inv[a];
        arr[x] = b;
        inv[a] = 0;
        inv[b] = x;
      }
    }
  }
  for (i = 1; i <= cnt; i++) {
    long long x = find(i);
    cout << arr[x] << ' ';
  }
  cout << '\n';
}
void init() {}
signed main() {
  ios::sync_with_stdio(false), cin.tie(0);
  long long T;
  T = 1;
  while (T--) {
    init();
    solve();
  }
}
