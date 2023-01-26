#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
const int MOD = 1e9 + 7;
ll modpow(ll a, ll n) {
  ll r = 1;
  while (n) {
    if (n & 1) r = (r * a) % MOD;
    a = (a * a) % MOD;
    n /= 2;
  }
  return r;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m, k, r, c;
  cin >> n >> m >> k >> r >> c;
  int ax, ay, bx, by;
  cin >> ax >> ay >> bx >> by;
  ll ans = modpow(k, 1LL * n * m - 1LL * r * c);
  if (tie(ax, ay) == tie(bx, by)) ans = (ans * modpow(k, 1LL * r * c)) % MOD;
  cout << ans;
}
