#include <bits/stdc++.h>
using namespace std;
long long read() {
  long long x;
  scanf("%lld", &x);
  return x;
}
int m;
int add(int a, int b) { return a + b < (m) ? a + b : a + b - (m); }
void dadd(int &a, int b) { a = add(a, b); }
int sub(int a, int b) { return a >= b ? a - b : a - b + (m); }
void dsub(int &a, int b) { a = sub(a, b); }
int mul(int a, int b) { return (long long)a * b % (m); }
void dmul(int &a, int b) { a = mul(a, b); }
int ksm(int a, int b) {
  int ans = 1;
  while (b) {
    if (b & 1) dmul(ans, a);
    b >>= 1;
    dmul(a, a);
  }
  return ans;
}
int inv(int a) { return ksm(a, (m)-2); }
int ceil(int a, int b) { return (a - 1) / b + 1; }
const int N = 202;
const int K = 25;
int n;
int fr[N];
int ifr[N];
void init() {
  for (int i = (int)(0); i <= (int)(n); i++) fr[i] = i ? mul(fr[i - 1], i) : 1;
  for (int i = (int)(0); i <= (int)(n); i++) ifr[i] = inv(fr[i]);
}
bool done[K][N][K * (N + 1)];
int dp[K][N][K * (N + 1)];
int dfs(int a1, int x, int mn, int s) {
  if (x == n) return fr[n];
  if (mn > n + 1) return 0;
  if (a1 * (n + 1) < s + mn * (n - x)) return 0;
  bool &ok = done[n + 1 - mn][x][x * (n + 1) - s];
  int &aans = dp[n + 1 - mn][x][x * (n + 1) - s];
  if (ok) return aans;
  int ans = 0;
  ok = true;
  if (x == 0) {
    int t = s;
    for (int y = (int)(x + 1); y <= (int)(n); y++) {
      t += a1;
      if (t > a1 * a1) break;
      dadd(ans, mul(ifr[y - x], dfs(a1, y, a1 + 1, t)));
    }
  } else {
    for (int v = (int)(mn); v <= (int)(n + 1); v++) {
      int t = s;
      for (int y = (int)(x + 1); y <= (int)(n); y++) {
        t += v;
        if (t > a1 * v) break;
        dadd(ans, mul(ifr[y - x], dfs(a1, y, v + 1, t)));
      }
    }
  }
  aans = ans;
  return ans;
}
int calc(int a1) {
  memset(done, false, sizeof(done));
  return dfs(a1, 0, a1, 0);
}
bool check(int a1) {
  int ax = a1;
  int sum = a1;
  for (int k = (int)(2); k <= (int)(n); k++) {
    while (a1 * ax < sum + ax && ax <= n + 1) ax++;
    sum += ax;
  }
  return ax <= n + 1;
}
int main() {
  n = read();
  m = read();
  init();
  int ans = 0;
  for (int j = (int)(1); j <= (int)(n + 1); j++)
    if (check(j)) dadd(ans, calc(j));
  printf("%d\n", ans);
  return 0;
}
