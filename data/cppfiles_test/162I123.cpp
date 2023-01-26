#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pld = pair<ld, ld>;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int d4x[4] = {1, 0, -1, 0};
int d4y[4] = {0, 1, 0, -1};
int d8x[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int d8y[8] = {1, 1, 0, -1, -1, -1, 0, 1};
template <class X, class Y>
bool minimize(X &x, const Y &y) {
  if (x > y) {
    x = y;
    return true;
  }
  return false;
}
template <class X, class Y>
bool maximize(X &x, const Y &y) {
  if (x < y) {
    x = y;
    return true;
  }
  return false;
}
const int MOD = 1e9 + 7;
template <class X, class Y>
void add(X &x, const Y &y) {
  x = (x + y);
  if (x >= MOD) x -= MOD;
}
template <class X, class Y>
void sub(X &x, const Y &y) {
  x = (x - y);
  if (x < 0) x += MOD;
}
const ll INF = 1e9;
const int N = 2e5 + 10;
ll a[N], b[N];
void solve() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  auto ok = [&](ll x) -> bool {
    for (int i = 1; i <= n; i++) b[i] = a[i];
    for (int i = n; i >= 3; i--) {
      if (a[i] > x) {
        ll c = a[i] - x;
        c = c / 3;
        b[i] -= 3 * c;
        b[i - 1] += c;
        b[i - 2] += 2 * c;
      }
    }
    for (int i = 1; i <= n; i++) {
      if (b[i] < x) return false;
    }
    return true;
  };
  int L = 1, R = 1e9, ans = 0;
  while (L <= R) {
    int mid = (L + R) >> 1;
    if (ok(mid)) {
      ans = mid;
      L = mid + 1;
    } else
      R = mid - 1;
  }
  cout << ans << '\n';
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int tc = 1, ddd = 0;
  cin >> tc;
  while (tc--) {
    solve();
  }
}
