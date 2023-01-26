#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5;
const int mod = 1e9 + 7, inv = 5e8 + 4;
int T, fac[maxn * 2 + 5], n;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  fac[0] = 1;
  for (int i = (1); i <= (maxn * 2); i++) fac[i] = 1ll * fac[i - 1] * i % mod;
  cin >> T;
  while (T--) {
    cin >> n;
    cout << 1ll * fac[n * 2] * inv % mod << '\n';
  }
  return 0;
}
