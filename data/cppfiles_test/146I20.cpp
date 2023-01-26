#include <bits/stdc++.h>
using namespace std;
template <class T>
void minn(T& a, T b) {
  if (a > b) a = b;
}
template <class T>
void maxx(T& a, T b) {
  if (a < b) a = b;
}
void debug() { return; }
template <class H, class... T>
void debug(H a, T... b) {
  cerr << a;
  debug(b...);
}
void is() { return; }
template <class H, class... T>
void is(H& a, T&... b) {
  cin >> a;
  is(b...);
}
void os() { return; }
template <class H, class... T>
void os(H a, T... b) {
  cout << a;
  os(b...);
}
const int mod = 1e9 + 7;
const int N = 2e5 + 5;
int n, q;
int nx[N], pr[N], nx300[N], pr300[N];
void sw(int x, int y) {
  swap(nx[x], nx[y]);
  int k;
  k = nx[pr300[x]];
  for (int i = 1; i <= 300; i++) {
    nx300[k] = nx[x];
    pr300[nx[x]] = k;
    x = nx[x];
    k = nx[k];
  }
  k = nx[pr300[y]];
  for (int i = 1; i <= 300; i++) {
    nx300[k] = nx[y];
    pr300[nx[y]] = k;
    y = nx[y];
    k = nx[k];
  }
}
void solve() {
  is(n, q);
  for (int i = 1; i <= n; i++) {
    is(nx[i]);
  }
  for (int i = 1; i <= n; i++) {
    int k = i;
    for (int j = 1; j <= 300; j++) {
      k = nx[k];
    }
    nx300[i] = k;
    pr300[k] = i;
  }
  while (q--) {
    int t, x, y;
    is(t, x, y);
    if (t == 2) {
      int k = x;
      while (y >= 300) {
        y -= 300;
        k = nx300[k];
      }
      while (y--) k = nx[k];
      os(k, '\n');
    } else {
      sw(x, y);
    }
  }
}
signed main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  int T = 1;
  while (T--) {
    solve();
  }
}
