#include <bits/stdc++.h>
using ll = long long int;
const int INF = (1 << 30);
const ll INFLL = (1ll << 60);
const ll MOD = (ll)(1e9 + 7);
void mul_mod(ll& a, ll b) {
  a *= b;
  a %= MOD;
}
void add_mod(ll& a, ll b) {
  a = (a < MOD) ? a : (a - MOD);
  b = (b < MOD) ? b : (b - MOD);
  a += b;
  a = (a < MOD) ? a : (a - MOD);
}
std::string s;
int a[334334];
int main(void) {
  int t, n, q, i, l, r;
  std::cin >> t;
  while (t--) {
    std::cin >> n >> q;
    std::cin >> s;
    for (i = 0; i < n; ++i) {
      if ((s[i] == '+') ^ (i % 2)) {
        a[i + 1] = a[i] + 1;
      } else {
        a[i + 1] = a[i] - 1;
      }
    }
    for (i = 0; i < q; ++i) {
      std::cin >> l >> r;
      --l;
      if (a[r] - a[l] == 0) {
        std::cout << 0 << std::endl;
      } else {
        std::cout << (2 - std::abs(a[r] - a[l]) % 2) << std::endl;
      }
    }
  }
  return 0;
}
