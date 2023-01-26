#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int sum[N], a[N], b[N], c[N];
const int mod = 998244353;
int main() {
  int n;
  cin >> n;
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i] >> b[i] >> c[i];
    int pos = lower_bound(a + 1, a + i + 1, b[i]) - a;
    int g = (1ll * a[i] - b[i] + sum[i - 1] - sum[pos - 1] + mod) % mod;
    if (c[i] == 1) ans += g;
    sum[i] = sum[i - 1] + g;
    sum[i] %= mod;
  }
  cout << (1ll * ans + a[n] + 1) % mod;
  return 0;
}
