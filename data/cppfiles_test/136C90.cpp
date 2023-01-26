#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using str = string;
using pi = pair<int, int>;
using pl = pair<ll, ll>;
using pd = pair<ld, ld>;
template <class T>
using V = vector<T>;
using vi = V<int>;
using vb = V<bool>;
using vl = V<ll>;
using vd = V<ld>;
using vs = V<str>;
using vpi = V<pi>;
using vpl = V<pl>;
using vpd = V<pd>;
template <class T>
int lwb(V<T>& a, const T& b) {
  return int(lower_bound(begin(a), end(a), b) - bg(a));
}
template <class T>
int upb(V<T>& a, const T& b) {
  return int(upper_bound(begin(a), end(a), b) - bg(a));
}
const int MOD = 1e9 + 7;
const int MX = 1e5 + 5;
const ll BIG = 1e18;
const int dx[4]{1, 0, -1, 0}, dy[4]{0, 1, 0, -1};
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());
template <class T>
using pqg = priority_queue<T, vector<T>, greater<T>>;
constexpr int pct(int x) { return __builtin_popcount(x); }
constexpr int bits(int x) { return x == 0 ? 0 : 31 - __builtin_clz(x); }
constexpr int p2(int x) { return 1 << x; }
ll cdiv(ll a, ll b) { return a / b + ((a ^ b) > 0 && a % b); }
ll fdiv(ll a, ll b) { return a / b - ((a ^ b) < 0 && a % b); }
template <class T>
bool ckmin(T& a, const T& b) {
  return b < a ? a = b, 1 : 0;
}
template <class T>
bool ckmax(T& a, const T& b) {
  return a < b ? a = b, 1 : 0;
}
template <class T>
ll gcd(T& a, T& b) {
  if (a > b) swap(a, b);
  while (a) {
    b -= a;
    if (a > b) swap(a, b);
  }
  return b;
}
template <class T>
ll power(T& a, T& b) {
  ll ans = 1;
  while (b) {
    if (b & 1) ans *= a;
    a *= a;
    b >>= 1;
  }
  return ans;
}
void solve() {
  int n;
  cin >> n;
  int b[n], a[n];
  ll sum = 0;
  for (int i = (0); i < (n); ++i) {
    cin >> b[i];
    sum += b[i];
  }
  ll cnt = n * 1ll * (n + 1) / 2;
  if (sum % cnt != 0) {
    cout << "NO\n";
    return;
  }
  for (int i = (n)-1; i >= (0); --i) {
    ll res = b[i] - b[(i + 1) % n] + (sum / cnt);
    if (res % n != 0 || res <= 0) {
      cout << "NO\n";
      return;
    }
    a[(i + 1) % n] = res / n;
  }
  cout << "YES\n";
  for (int i = (0); i < (n); ++i) cout << a[i] << " ";
  cout << "\n";
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) solve();
}
