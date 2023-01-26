#include <bits/stdc++.h>
using namespace std;
const int64_t INF = 0x3f3f3f3f;
const int64_t INFLL = 0x3f3f3f3f3f3f3f3f;
const int64_t MOD = 1e9 + 7;
const double EPS = 1e-9;
const double PI = acos(-1);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int64_t rand(int64_t x, int64_t y) {
  return uniform_int_distribution<int64_t>(x, y)(rng);
}
int64_t mul(int64_t a, int64_t b) {
  int64_t ret = (1ll * (a % MOD) * (b % MOD)) % MOD;
  return (ret + MOD) % MOD;
}
int64_t add(int64_t a, int64_t b) {
  int64_t ret = (1ll * (a % MOD) + (b % MOD)) % MOD;
  return (ret + MOD) % MOD;
}
int64_t pow_exp(int64_t n, int64_t p) {
  if (!p) return 1;
  if (p & 1) return mul(n, pow_exp(n, p - 1));
  int64_t tmp = pow_exp(n, p / 2);
  return mul(tmp, tmp);
}
const int64_t MAX = 2e5 + 10;
const int64_t NMAX = 2e5 + 10;
const int64_t MMAX = 2e5 + 10;
const int64_t LOG_MAX = ceil(log2(double(NMAX)));
const int64_t BLOCK = ceil(sqrt(double(NMAX)));
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int64_t t;
  cin >> t;
  while (t--) {
    int64_t n;
    cin >> n;
    string str;
    cin >> str;
    bool found = false;
    for (int64_t i = 1; i < n; i++) {
      if (str[i - 1] != str[i]) {
        cout << i << ' ' << i + 1 << '\n';
        found = true;
        break;
      }
    }
    if (!found) {
      cout << "-1 -1" << '\n';
    }
  }
}
