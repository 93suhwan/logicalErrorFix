#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
using PP = pair<ll, P>;
const ll n_ = 2e5 + 100, inf = 1e18 + 1, mod = 1e9 + 7, sqrtN = 333, p = 27;
ll dy[4] = {-1, 0, 1, 0}, dx[4] = {0, 1, 0, -1};
ll n, m, k, tc = 1, a, b, c, sum, x, y, z, w, base, ans;
ll gcd(ll x, ll y) {
  if (!y) return x;
  return gcd(y, x % y);
}
vector<ll> v[n_];
ll A[n_];
void dfs(ll x, ll par) {
  ll ret = 0;
  for (auto nxt : v[x]) {
    if (nxt == par) continue;
    if (A[nxt] == 1) ret++;
    dfs(nxt, x);
  }
  if (ret) ans += ret - 1;
}
void solve() {
  cin >> n;
  ans = 0;
  memset(A, sizeof(A), 0);
  for (int i = 1; i < n; i++) {
    cin >> a >> b;
    v[a].push_back(b);
    v[b].push_back(a);
    A[a]++;
    A[b]++;
  }
  dfs(1, 0);
  for (int i = 1; i <= n; i++) A[i] = 0, v[i].clear();
  ans++;
  ans = max(ans, 1ll);
  cout << ans << '\n';
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  cin >> tc;
  while (tc--) solve();
}
