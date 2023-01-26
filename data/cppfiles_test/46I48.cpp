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
constexpr ll MAX = 4e6 + 5;
void solve() {
  ll n;
  cin >> n;
  V<ll> c(n + 2, 0);
  for (ll i = (ll)(1); i < (ll)(n + 1); i++) cin >> c[i];
  ll ans = 0;
  for (ll i = (ll)(1); i < (ll)(n + 1); i++)
    if (i % 2) {
      ll cur = 0, mn = INF;
      for (ll j = (ll)(i); j < (ll)(n + 1); j++) {
        if (j % 2)
          cur += c[j];
        else {
          cur -= c[j];
          if (cur == 0)
            ans += min(c[i], c[j]);
          else if (cur > 0 && cur <= mn)
            ans += max(0LL, min(c[i] - cur, c[j]));
          else if (cur < 0 && -cur < c[j])
            ans += max(0LL, min({mn + 1, c[i], c[j] + cur}));
        }
        if (cur < 0) break;
        mn = min(mn, cur);
      }
    }
  cout << ans << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ll t = 1;
  for (ll i = (ll)(1); i < (ll)(t + 1); i++) solve();
}
