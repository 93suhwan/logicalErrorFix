#include <bits/stdc++.h>
using namespace std;
using namespace std;
const double eps = 1e-6;
const int int_inf = 2 * 1e9;
const long long ll_inf = 8 * 1e18;
const long double PI = acosl(-1.0);
template <typename T>
using pair2 = pair<T, T>;
using pii = pair<int, int>;
using pli = pair<long long, int>;
using pll = pair<long long, long long>;
istream& operator>>(istream& in, pii& i) {
  in >> i.first >> i.second;
  return in;
}
template <class T>
istream& operator>>(istream& in, vector<T>& a) {
  for (auto& i : a) {
    in >> i;
  }
  return in;
}
template <class T>
ostream& operator<<(ostream& out, vector<T>& a) {
  for (auto i : a) {
    out << i << " ";
  }
  out << '\n';
  return out;
}
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
long long myRand(long long B) { return (unsigned long long)rng() % B; }
long long powmod(long long a, long long b, long long p) {
  a %= p;
  if (a == 0) return 0;
  long long product = 1;
  while (b > 0) {
    if (b & 1) {
      product *= a;
      product %= p;
      --b;
    }
    a *= a;
    a %= p;
    b /= 2;
  }
  return product;
}
long long MOD = 998244353;
long long factor[5007];
long long invfactor[5007];
long long inv(long long a, long long p) { return powmod(a, p - 2, p); }
long long C(long long n, long long k) {
  return (((factor[n] * invfactor[k]) % MOD) * invfactor[n - k]) % MOD;
}
long long nCk(long long n, long long k, long long p) {
  return ((factor[n] * inv(factor[k], p) % p) * inv(factor[n - k], p)) % p;
}
void precalc() {
  factor[0] = 1;
  factor[1] = 1;
  invfactor[0] = 1;
  invfactor[1] = 1;
  for (int i = 2; i < 5007; ++i) {
    factor[i] = (factor[i - 1] * i) % MOD;
    invfactor[i] = inv(factor[i], MOD);
  }
}
void solve() {
  int n, k;
  string s;
  cin >> n >> k >> s;
  vector<int> prefs(n + 1, 0);
  for (int i = 1; i < n + 1; ++i) {
    prefs[i] = prefs[i - 1] + (s[i - 1] == '1');
  }
  if (prefs[n] < k) {
    cout << 1 << '\n';
    return;
  }
  long long ans = 1;
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      int c1 = prefs[j + 1] - prefs[i];
      if (c1 > k) break;
      int c0 = j - i + 1 - c1;
      if (s[i] == '1') {
        c0--;
      } else {
        c1--;
      }
      if (s[j] == '1') {
        c0--;
      } else {
        c1--;
      }
      int len = c0 + c1;
      if (c0 >= 0 && c1 >= 0) ans += C(len, c1);
    }
  }
  cout << ans << '\n';
  return;
}
signed main() {
  ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  precalc();
  int tt = 1;
  while (tt--) {
    solve();
  }
  return 0;
}
