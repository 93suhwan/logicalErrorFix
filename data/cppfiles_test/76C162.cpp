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
int mod = 1e9 + 7;
const int N = 1e6 + 5;
long long mp[200005];
void solve() {
  int n = read();
  mod = read();
  mp[1] = 1;
  long long sum = 0;
  for (int i = 2; i <= n; ++i) {
    sum += mp[i - 1];
    int sum2 = 0;
    for (int l = 2, r; l <= i; l = r + 1) {
      r = i / (i / l);
      int len = r - l + 1;
      sum2 += mp[i / l] * len % mod;
      sum2 %= mod;
    }
    mp[i] = (sum + sum2) % mod;
  }
  printf("%lld\n", mp[n]);
}
int main() {
  solve();
  return 0;
}
