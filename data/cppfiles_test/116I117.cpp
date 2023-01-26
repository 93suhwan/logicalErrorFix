#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
mt19937 rng((int)chrono::steady_clock::now().time_since_epoch().count());
const int MOD = 998244353;
const int MAXN = 2e5 + 5;
const ll INF = 2e18;
void add(ll &a, ll b) {
  a += b;
  if (a >= MOD) a -= MOD;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int &x : v) cin >> x;
    vector<ll> cnt(n + 5), inv(n + 5);
    ll ans = 0;
    for (int i = 0; i < n; i++) {
      if (v[i] == 0) {
        add(ans, cnt[0] + 1);
        add(cnt[0], cnt[0] + 1);
      } else if (v[i] == 1) {
        add(ans, cnt[0]);
        add(ans, cnt[1]);
        add(ans, inv[1] + 1);
        add(inv[1], inv[1] + 1);
        add(cnt[1], cnt[1]);
        add(cnt[1], cnt[0]);
      } else {
        add(ans, inv[v[i]]);
        add(ans, cnt[v[i] - 2]);
        add(ans, cnt[v[i] - 1]);
        add(ans, cnt[v[i]]);
        add(cnt[v[i]], cnt[v[i]]);
        add(cnt[v[i]], cnt[v[i] - 1]);
        add(inv[v[i]], inv[v[i]]);
        add(inv[v[i]], cnt[v[i] - 2]);
      }
    }
    cout << ans << '\n';
  }
  return 0;
}
