#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
const int N = 500000;
int a[N + 5];
long long sum[N + 5], f[N + 5];
int main() {
  stack<array<int, 4>> s;
  s.push({0, 0, 0, 0});
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
  long long tot = 0;
  f[0] = 1;
  for (int i = 1; i <= n; i++) {
    int left = i;
    long long temp = 0;
    while (!s.empty() && s.top()[0] >= a[i]) {
      auto now = s.top();
      s.pop();
      tot = (tot - now[3] + mod) % mod;
      temp = (temp +
              (long long)a[i] * (sum[now[2]] - sum[now[1] - 1] + mod) % mod) %
             mod;
      left = now[1];
    }
    long long coef = i % 2 ? mod - 1 : 1;
    temp = (temp + (long long)a[i] * coef % mod * f[i - 1] % mod) % mod;
    s.push({a[i], left, i, (int)temp});
    tot = (tot + temp) % mod;
    f[i] = tot * coef % mod;
    sum[i] = (sum[i - 1] + f[i - 1] * coef % mod) % mod;
  }
  printf("%lld", f[n]);
  return 0;
}
