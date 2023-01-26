#include <bits/stdc++.h>
using namespace std;
inline void chmax(long long &x, long long y) { x = max(x, y); }
inline void chmin(long long &x, long long y) { x = min(x, y); }
inline void pls(long long &x, long long y, long long Mod) {
  x = (x + y >= Mod) ? (x + y - Mod) : (x + y);
}
inline void sub(long long &x, long long y, long long Mod) {
  x = (x - y < 0) ? (x - y + Mod) : (x - y);
}
long long max(long long a, long long b) { return a > b ? a : b; }
long long min(long long a, long long b) { return a < b ? a : b; }
long long lowbit(long long x) { return x & (-x); }
long long prime(long long x) {
  if (x <= 1) return 0;
  for (int i = 2; i <= int(sqrt(x)); i++) {
    if (x % i == 0) return 0;
  }
  return 1;
}
bool cmp(long long a, long long b) { return a > b; }
long long gcd(long long a, long long b) {
  long long r;
  while (b > 0) {
    r = a % b;
    a = b;
    b = r;
  }
  return a;
}
long long powmod(long long a, long long b, long long mod) {
  long long res = 1;
  a %= mod;
  assert(b >= 0);
  for (; b; b >>= 1) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
  }
  return res;
}
inline int readint() {
  int f = 1, x = 0;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch <= '9' && ch >= '0') x = x * 10 + ch - '0', ch = getchar();
  return f * x;
}
inline long long readll() {
  long long f = 1, x = 0;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch <= '9' && ch >= '0') x = x * 10 + ch - '0', ch = getchar();
  return f * x;
}
void fl(string name) {
  freopen((name + ".in").c_str(), "r", stdin);
  freopen((name + ".out").c_str(), "w", stdout);
}
const int dx[8] = {-1, 1, 0, 0, -1, 1, -1, 1},
          dy[8] = {0, 0, -1, 1, -1, -1, 1, 1};
int main() {
  long long q;
  cin >> q;
  while (q--) {
    long long n;
    cin >> n;
    long long a[n + 1], b[n + 1];
    long long res = 0, t1[n + 1], t2[n + 1];
    for (int i = 1; i <= n; i++) t1[i] = t2[i] = 0;
    res = n * (n - 1) * (n - 2) / 6;
    for (int i = 1; i <= n; i++) {
      cin >> a[i] >> b[i];
      t1[a[i]]++;
      t2[b[i]]++;
    }
    for (int i = 1; i <= n; i++) {
      res = res - (t1[a[i]] - 1) * (t2[b[i]] - 1);
    }
    cout << res << endl;
  }
  return 0;
}
