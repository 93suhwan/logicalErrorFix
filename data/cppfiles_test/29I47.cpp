#include <bits/stdc++.h>
using namespace std;
const long long inf = 1000000007;
const int maxn = 300010;
int vis[maxn], cnt[maxn];
long long sum[maxn];
int mod(int x, int u) {
  int ret = 0;
  for (int i = 2; i <= u; ++i)
    if (vis[i]) {
      ret += x % i;
    }
  return ret;
}
long long cal(int x) {
  long long ret = 0, xx = x;
  for (int i = 1;; ++i) {
    int d = x / (i + 1), u = x / i;
    if (u <= 300) {
      return ret + mod(x, u);
    }
    ret += xx * (cnt[u] - cnt[d]) - (sum[u] - sum[d]) * i;
  }
  return ret;
}
int main() {
  static int a[maxn];
  static long long p[maxn];
  int n, N = 300000;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }
  for (int i = 0; i < n; i += 500) {
    int j = min(n, i + 500);
    for (int k = i; k < j; ++k) {
      long long ak = a[k];
      p[k] = cal(a[k]) + ak * (cnt[N] - cnt[a[k]]);
      for (int kk = 0; kk < N; kk += a[k]) {
        int rig = min(kk + a[k] - 1, N);
        p[k] += (sum[rig] - sum[kk]) - ak * kk * (cnt[rig] - cnt[kk]);
      }
      for (int kk = i; kk < k; ++kk) {
        p[k] += a[kk] % a[k] + a[k] % a[kk];
      }
    }
    for (int k = i; k < j; ++k) {
      vis[a[k]] = 1;
    }
    for (int k = 1; k <= N; ++k) {
      cnt[k] = vis[k] + cnt[k - 1];
      sum[k] = vis[k] * k + sum[k - 1];
    }
  }
  long long pp = 0;
  for (int i = 0; i < n; ++i) {
    pp += p[i];
    printf("%lld ", pp);
  }
  puts("");
  return 0;
}
