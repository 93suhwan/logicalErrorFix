#include <bits/stdc++.h>
using namespace std;
const int N = 1E6 + 5, M = 1e3 + 5, mod = 998244353, INF = 0x3f3f3f3f;
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
long long qpow(long long a, long long b) {
  long long c = 1;
  while (b) {
    if (b & 1) c = (c * a) % mod;
    a = (a * a) % mod;
    b >>= 1;
  }
  return c % mod;
}
long long inv(long long x) { return qpow(x, mod - 2); }
string s[N];
int l[N];
int n, m;
int st[N];
void bfs() {
  queue<int> q;
  for (int i = 0; i < n * m; i++) {
    l[i] = i % m;
    if (i % m == 0) {
      q.push(i);
    }
  }
  while (q.size()) {
    int x = q.front() / m, y = q.front() % m;
    q.pop();
    if (s[x][y] == 'X') continue;
    int tx = x + 1, ty = y;
    if (tx < n) {
      if (l[tx * m + ty] > l[x * m + y]) {
        l[tx * m + ty] = l[x * m + y];
        q.push(tx * m + ty);
      }
    }
    tx = x, ty = y + 1;
    if (ty < m) {
      if (l[tx * m + ty] > l[x * m + y]) {
        l[tx * m + ty] = l[x * m + y];
        q.push(tx * m + ty);
      }
    }
  }
}
void bfs1() {
  queue<int> q;
  for (int i = 0; i < n * m; i++) {
    if (i / m == 0 || i % m == 0) {
      int x = i / m, y = i % m;
      q.push(i), st[i] = 1;
    }
  }
  while (q.size()) {
    int x = q.front() / m, y = q.front() % m;
    q.pop();
    if (s[x][y] == 'X') continue;
    int tx = x + 1, ty = y;
    if (tx < n) {
      if (!st[tx * m + ty]) {
        st[tx * m + ty] = 1;
        q.push(tx * m + ty);
      }
    }
    tx = x, ty = y + 1;
    if (ty < m) {
      if (!st[tx * m + ty]) {
        st[tx * m + ty] = 1;
        q.push(tx * m + ty);
      }
    }
  }
}
int h[N];
int hh[N];
int main() {
  int _ = 1;
  while (_--) {
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> s[i];
    bfs();
    bfs1();
    for (int i = 0; i < n * m; i++) hh[i] = 1;
    for (int i = 0; i < n * m; i++) {
      int y = i % m;
      h[y] = max(h[y], l[i]);
      hh[y] = min(hh[y], st[i]);
    }
    int q;
    cin >> q;
    while (q--) {
      int x1, x2;
      scanf("%d%d", &x1, &x2);
      x1--, x2--;
      if (h[x2] > x1 && !hh[x2])
        puts("NO");
      else
        puts("YES");
    }
  }
}
