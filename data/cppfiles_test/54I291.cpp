#include <bits/stdc++.h>
using namespace std;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
struct custom_hash {
  static uint64_t splitmix64(uint64_t x) {
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
  }
  size_t operator()(uint64_t x) const {
    static const uint64_t FIXED_RANDOM =
        chrono::steady_clock::now().time_since_epoch().count();
    return splitmix64(x + FIXED_RANDOM);
  }
};
void _print() { cout << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v) {
  cout << t;
  if (sizeof...(v)) cout << ", ";
  _print(v...);
}
using ll = long long int;
using ld = long double;
template <typename T, typename V>
using P = pair<T, V>;
template <typename T>
using V = vector<T>;
constexpr ll MOD = 1e9 + 7;
constexpr ll INF = 0x3f3f3f3f;
constexpr ld PI = 3.1415926535897932384626;
constexpr ld EPS = 1e-9;
constexpr ll MAX = 1e5 + 5;
ll power(ll a, ll b) {
  ll ans = 1;
  while (b > 0) {
    if (b % 2) (ans *= a) %= MOD;
    (a *= a) %= MOD, b >>= 1;
  }
  return ans;
}
void solve() {
  ll n, k;
  cin >> n >> k;
  if (n % 2) {
    ll ans = (power(2, k) - 1 + MOD) % MOD;
    ans = (ans * power(2, n - 1)) % MOD;
    ans = (ans + 1) % MOD;
    cout << ans << '\n';
  } else {
    ll ans = 0;
    for (ll x = (ll)(0); x < (ll)(k + 1); x++) {
      ll lef = (power(2, x * (n - 1)) - 1 + MOD) % MOD;
      lef %= MOD;
      ll rit = power(2, n * (k - x - 1));
      ans += (max(lef, 1LL) * max(rit, 1LL)) % MOD;
      ans %= MOD;
    }
    cout << ans << '\n';
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ll t = 1;
  cin >> t;
  for (ll i = (ll)(1); i < (ll)(t + 1); i++) solve();
}
