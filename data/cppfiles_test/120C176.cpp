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
long long factor[35];
long long inv(long long a, long long p) { return powmod(a, p - 2, p); }
long long nCk(long long n, long long k, long long p) {
  return ((factor[n] * inv(factor[k], p) % p) * inv(factor[n - k], p)) % p;
}
const int SIZE = 2 * 1e5 + 8;
vector<vector<int>> prefs;
void solve() {
  int r, l;
  cin >> l >> r;
  vector<int> curr = prefs[r];
  vector<int> curl = prefs[l - 1];
  int ans = 1e9;
  for (int i = 0; i < 32; ++i) {
    ans = min(ans, curr[i] - curl[i]);
  }
  cout << ans << '\n';
  return;
}
int main() {
  ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  prefs.resize(SIZE, vector<int>(33, 0));
  for (int i = 1; i < 2 * 1e5 + 3; ++i) {
    prefs[i] = prefs[i - 1];
    for (int j = 0; j <= 31; ++j) {
      if ((i & (1 << j)) == 0) {
        prefs[i][j]++;
      }
    }
  }
  int tt = 1;
  cin >> tt;
  while (tt--) {
    solve();
  }
  return 0;
}
