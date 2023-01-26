#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 100;
const int N = 1e5 + 7;
const int mod = 1e9 + 7;
int prim[maxn], pn = 0, vis[maxn], phi[maxn];
void Phi() {
  for (int i = 2; i <= N; i++) {
    if (!vis[i]) prim[++pn] = i, phi[i] = i - 1;
    for (int j = 1; j <= pn && i * prim[j] <= N; j++) {
      vis[i * prim[j]] = 1;
      if (i % prim[j] == 0) {
        phi[i * prim[j]] = phi[i] * prim[j];
        break;
      } else
        phi[i * prim[j]] = phi[i] * (prim[j] - 1);
    }
  }
}
int a[200050];
long long ans[200050];
vector<int> fac[200050];
int sum[200050];
long long solve(int n, int T) {
  long long ans = 0;
  for (int i = T; i <= n; i += T) {
    for (auto p : fac[a[i]]) {
      ans = (ans - 1ll * phi[p] * sum[p] * sum[p] % mod);
      if (ans < mod) ans += mod;
      sum[p]++;
      ans = (ans + 1ll * phi[p] * sum[p] * sum[p] % mod);
      if (ans > mod) ans -= mod;
    }
  }
  for (int i = T; i <= n; i += T) {
    for (auto p : fac[a[i]]) {
      sum[p]--;
    }
  }
  return ans;
}
int main() {
  Phi();
  phi[1] = 1;
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
  for (int i = 1; i <= 100000; ++i) {
    for (int j = i; j <= 100000; j += i) {
      fac[j].push_back(i);
    }
  }
  long long res = 0;
  for (int i = 1; i <= n; ++i) {
    ans[i] = phi[i];
    ans[i] = ans[i] * solve(n, i) % mod;
    res += ans[i];
    if (res > mod) res -= mod;
  }
  printf("%lld", res);
}
