#include <bits/stdc++.h>
using namespace std;
const int N = 4e6 + 10;
long long f[N];
long long c[N], n, mod;
int main() {
  cin >> n >> mod;
  f[n] = 1;
  for (int i = n; i >= 1; i--) {
    f[i] = f[i] + c[i + 1] - c[n + 1];
    for (int j = i + 1, l, r; j <= n; j = r + 1) {
      l = j, r = (j / i + 1) * i - 1;
      r = min(1ll * r, n);
      f[i] = (f[i] + 1ll * j / i * (c[l] - c[r + 1]));
      if (f[i] > 1e18) f[i] %= mod;
    }
    for (int j = i + 1, l, r; j <= n; j = r + 1) {
      l = j, r = (j / (i + 1) + 1) * (i + 1) - 1;
      r = min(1ll * r, n);
      f[i] = (f[i] - 1ll * j / (i + 1) * (c[l] - c[r + 1]));
      if (f[i] > 1e18) f[i] %= mod;
    }
    if (f[i] > 1e18) f[i] %= mod;
    c[i] = (c[i + 1] + f[i]) % mod;
  }
  cout << (f[1] + mod) % mod << endl;
  return 0;
}
