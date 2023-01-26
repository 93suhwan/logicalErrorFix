#include <bits/stdc++.h>
using namespace std;
constexpr int log2(int x) { return x == 0 ? 0 : 31 - __builtin_clz(x); }
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());
template <class T>
bool umin(T& a, const T& b) {
  return b < a ? a = b, 1 : 0;
}
template <class T>
bool umax(T& a, const T& b) {
  return a < b ? a = b, 1 : 0;
}
using ll = long long;
using ld = long double;
using str = string;
const int inf = (int)1e9 + 5;
const ll infl = (ll)1e18 + 5;
const int MOD = 1e9 + 7;
const int N = 2e5 + 10;
const int d4i[4] = {-1, 0, 1, 0}, d4j[4] = {0, 1, 0, -1};
const int d8i[8] = {-1, -1, 0, 1, 1, 1, 0, -1},
          d8j[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int n, k;
ll go(vector<int>& v) {
  sort((v).begin(), (v).end());
  int n1 = (int)(v).size(), t = 0;
  ll ans = 0;
  for (int i = 0; i < (n1 - k); ++i) {
    if (++t == k || i == n1 - k - 1) {
      ans += 1ll * 2 * v[i];
      t = 0;
    }
  }
  if (n1) ans += v[n1 - 1];
  return ans;
}
void solve() {
  cin >> n >> k;
  vector<int> a, b;
  for (int i = 0; i < (n); ++i) {
    int t;
    cin >> t;
    if (t > 0)
      a.emplace_back(t);
    else if (t < 0)
      b.emplace_back(-t);
  }
  ll ans = go(a) + go(b);
  if ((int)(a).size() && (int)(b).size()) {
    ans += min(a.back(), b.back());
  }
  cout << ans << '\n';
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) solve();
}
