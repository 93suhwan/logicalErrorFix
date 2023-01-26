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
ll f(ll x) {
  ll ret = 0;
  while (x) {
    ret += x & 1;
    x /= 2;
  }
  return ret % 2;
}
vector<P> v[n_], edge[n_];
ll A[n_], par[n_], dep[n_], checked[n_], checked2[n_], B[n_], C[n_];
ll find(ll x) {
  if (par[x] < 0) return x;
  return par[x] = find(par[x]);
}
void merge(ll x, ll y) {
  x = find(x), y = find(y);
  if (x == y) return;
  par[x] = y;
}
void dfs(ll x, ll par_) {
  for (auto nxt : v[x]) {
    if (nxt.first == par_) continue;
    if (A[x] == -1 || nxt.second == -1)
      A[nxt.first] = -1;
    else
      A[nxt.first] = A[x] ^ f(nxt.second);
    if (nxt.second != -1) {
      edge[x].push_back({nxt.first, f(nxt.second)});
      edge[nxt.first].push_back({x, f(nxt.second)});
    }
    dfs(nxt.first, x);
  }
}
bool dfs2(ll x) {
  bool ret = true;
  for (auto nxt : edge[x]) {
    if (B[nxt.first] == -1) {
      checked[nxt.first] = true;
      B[nxt.first] = B[x] ^ nxt.second;
      if (A[nxt.first] != -1 && A[nxt.first] != B[nxt.first]) return false;
      ret &= dfs2(nxt.first);
      continue;
    }
    if (B[nxt.first] != B[x] ^ nxt.second) return false;
    if (checked[nxt.first]) continue;
    checked[nxt.first] = true;
    ret &= dfs2(nxt.first);
  }
  return ret;
}
bool dfs3(ll x) {
  bool ret = true;
  for (auto nxt : edge[x]) {
    if (C[nxt.first] == -1) {
      checked2[nxt.first] = true;
      C[nxt.first] = C[x] ^ nxt.second;
      if (A[nxt.first] != -1 && A[nxt.first] != C[nxt.first]) return false;
      continue;
    }
    if (C[nxt.first] != C[x] ^ nxt.second) return false;
    if (checked2[nxt.first]) continue;
    checked2[nxt.first] = true;
    ret &= dfs2(nxt.first);
  }
  return ret;
}
void solve() {
  cin >> n >> m;
  vector<PP> ANS;
  for (int i = 0; i <= n; i++) A[i] = par[i] = B[i] = C[i] = -1;
  for (int i = 1; i < n; i++) {
    cin >> a >> b >> c;
    ANS.push_back({c, {a, b}});
    v[a].push_back({b, c});
    v[b].push_back({a, c});
  }
  A[1] = 0;
  dfs(1, 0);
  while (m--) {
    cin >> a >> b >> c;
    edge[a].push_back({b, c});
    edge[b].push_back({a, c});
  }
  bool ok = true;
  for (int i = 1; i <= n; i++) {
    if (checked[i]) continue;
    checked[i] = checked2[i] = true;
    if (A[i] != -1) {
      B[i] = A[i];
      if (dfs2(i)) {
        continue;
      } else
        ok = false;
    } else {
      A[i] = 0;
      B[i] = A[i];
      if (dfs2(i)) {
        continue;
      } else {
        A[i] = 1;
        C[i] = A[i];
        if (dfs3(i))
          continue;
        else
          ok = false;
      }
    }
  }
  if (ok) {
    cout << "YES" << '\n';
    for (auto nxt : ANS) {
      a = nxt.first, b = nxt.second.first, c = nxt.second.second;
      if (a != -1)
        cout << b << ' ' << c << ' ' << a << '\n';
      else
        cout << b << ' ' << c << ' ' << (B[b] ^ B[c]) << '\n';
    }
  } else
    cout << "NO" << '\n';
  for (int i = 0; i <= n; i++)
    v[i].clear(), edge[i].clear(), checked[i] = checked2[i] = 0;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  cin >> tc;
  while (tc--) solve();
}
