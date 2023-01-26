#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
using ull = unsigned long long int;
using ld = long double;
constexpr ll MAX = 2000000000000000000;
constexpr ld PI = 3.14159265358979;
constexpr ll MOD = 0;
ld dotorad(ld K) { return PI * K / 180.0; }
ld radtodo(ld K) { return K * 180.0 / PI; }
mt19937 mt;
void randinit() {
  srand((unsigned)time(NULL));
  mt = mt19937(rand());
}
ll c(ll N, ll i) {
  N++;
  ll p = (1LL << i), q = (1LL << (i + 1));
  ll ans = N / q * p;
  N %= q;
  ans += min(N, p);
  return ans;
}
int main() {
  ll T;
  cin >> T;
  for (ll t = 0; t < T; t++) {
    ll L, R;
    cin >> L >> R;
    ll ans = MAX;
    for (ll i = 0; i < 20; i++) {
      ans = min(ans, c(R, i) - c(L - 1, i));
    }
    cout << ans << endl;
  }
}
