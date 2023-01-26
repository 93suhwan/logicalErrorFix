#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
using PP = pair<ll, P>;
const ll n_ = 2e5 + 100, inf = (ll)2e9 * (ll)1e9 + 7, mod = 1e9 + 7,
         sqrtN = 320;
ll dy[4] = {-1, 0, 1, 0}, dx[4] = {0, 1, 0, -1};
ll n, m, k, tc = 1, a, b, c, d, sum, x, y, z, base, ans, q;
ll gcd(ll x, ll y) {
  if (!y) return x;
  return gcd(y, x % y);
}
ll tree[n_];
ll f(ll l, ll r) {
  l--;
  ll ret = 0;
  for (; l; l -= l & -l) ret -= tree[l];
  for (; r; r -= r & -r) ret += tree[r];
  return ret;
}
void update(ll i, ll val) {
  for (; i <= n; i += i & -i) tree[i] += val;
}
vector<P> v[n_];
ll par[n_], A[n_], C[n_];
ll f(ll x) {
  ll ret = 0;
  while (x) {
    ret += x % 2;
    x /= 2;
  }
  return ret % 2;
}
void dfs(ll x, ll y, ll cost) {
  for (auto nxt : v[x]) {
    if (nxt.first == y) continue;
    par[nxt.first] = x;
    if (nxt.second == -1)
      cost = -1;
    else
      cost ^= nxt.second;
    if (cost == -1)
      A[nxt.first] = -1;
    else
      A[nxt.first] = f(cost);
    dfs(nxt.first, x, cost);
  }
}
void dfs2(ll x, ll y, ll cost) {
  for (auto nxt : v[x]) {
    if (nxt.first == y || nxt.second == -1) continue;
    par[nxt.first] = x;
    if (nxt.second == -1)
      cost = -1;
    else
      cost ^= nxt.second;
    if (cost == -1)
      A[nxt.first] = -1;
    else
      A[nxt.first] = f(cost);
    dfs(nxt.first, x, cost);
  }
}
void solve() {
  cin >> n >> m;
  vector<PP> query;
  for (int i = 1; i < n; i++) {
    cin >> a >> b >> c;
    query.push_back({a, {b, c}});
    v[a].push_back({b, c});
    v[b].push_back({a, c});
  }
  dfs(1, 0, 0);
  bool ok = true;
  while (m--) {
    cin >> a >> b >> c;
    if (c == 1) {
      if (A[a] != -1 && A[b] != -1) {
        if (c != A[a] ^ A[b]) {
          ok = false;
        }
      } else if (A[a] == -1) {
        A[a] = c ^ A[b];
        dfs2(a, 0, A[a]);
      } else {
      }
    } else {
    }
  }
  if (ok)
    cout << "YES";
  else
    cout << "NO";
  for (int i = 1; i <= n; i++) v[i].clear();
  cout << '\n';
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  cin >> tc;
  while (tc--) solve();
}
