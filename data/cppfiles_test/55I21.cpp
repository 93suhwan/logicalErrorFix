#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
const ll MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
template <typename T>
void print(T &&t) {
  cout << t << "\n";
}
template <typename T, typename... Args>
void print(T &&t, Args &&...args) {
  cout << t << " ";
  print(forward<Args>(args)...);
}
int GCD(int a, int b) {
  while (b) {
    a %= b;
    swap(a, b);
  }
  return a;
}
int GCD_extended(int a, int b, int &x, int &y) {
  x = 1, y = 0;
  int x1 = 0, y1 = 1, a1 = a, b1 = b;
  while (b1) {
    int q = a1 / b1;
    tie(x, x1) = make_tuple(x1, x - q * x1);
    tie(y, y1) = make_tuple(y1, y - q * y1);
    tie(a1, b1) = make_tuple(b1, a1 - q * b1);
  }
  return a1;
}
int LCM(int a, int b) { return (a * b) / GCD(a, b); }
ll modpow(ll x, int n, ll m) {
  ll res = 1;
  while (n > 0) {
    if (n & 1) res = (res * x) % m;
    x = (x * x) % m;
    n >>= 1;
  }
  return res;
}
ll modinv(ll x, ll m = MOD) { return modpow(x, m - 2, m); }
ll cei(ll a, ll b) {
  ll val = (a / b) + ((a % b) != 0);
  return val;
}
void solve() {
  ll n;
  cin >> n;
  ll ans = modpow(4, (1 << n) - 2, MOD);
  ans = (ans * 6) % MOD;
  cout << ans << "\n";
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ll tc = 1;
  for (ll t = 1; t <= tc; t++) {
    solve();
  }
}
