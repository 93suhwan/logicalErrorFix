#include <bits/stdc++.h>
const long long ds = 1e18;
const double eps = 1e-8;
long long read() {
  long long x = 0, f = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') x = (x << 1) + (x << 3) + c - '0', c = getchar();
  return f * x;
}
void print(long long x) {
  if (x < 0) {
    putchar('-');
    x = -x;
  }
  if (x / 10) print(x / 10);
  putchar(x % 10 + '0');
}
using namespace std;
long long mod = 1e9 + 7;
const int N = 1e6 + 5;
long long mp[200005];
long long dfs(int n) {
  if (mp[n] != -1) return mp[n];
  long long res = (dfs(n - 1) + mp[1]) % mod;
  for (long long i = 2; i < n; ++i) {
    res = (res + dfs(n - i) + dfs(n / i)) % mod;
  }
  mp[n] = res;
  return res;
}
void solve() {
  int n = read();
  mod = read();
  memset(mp, -1, sizeof mp);
  mp[0] = 0;
  mp[1] = 1;
  dfs(n);
}
int main() {
  solve();
  return 0;
}
