#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll maxn = 1e6 + 10;
ll a[maxn], b[maxn], p[maxn];
ll n, m;
map<ll, ll> dic;
ll bits[2 * maxn];
ll lowbit(ll x) { return x & (-x); }
void update(ll x, ll pos) {
  while (pos < maxn) {
    bits[pos] += x;
    pos += lowbit(pos);
  }
}
ll query(ll pos) {
  ll res = 0;
  while (pos) {
    res += bits[pos];
    pos -= lowbit(pos);
  }
  return res;
}
void insert(ll lb, ll rb, ll la, ll ra) {
  if (lb > rb || la > ra) return;
  ll nowb = b[(lb + rb) / 2];
  ll less = 0;
  for (ll pos = la; pos < ra; ++pos) {
    if (a[pos] < nowb) ++less;
  }
  ll pick = la, ans = less;
  ll now = la;
  while (now < ra) {
    if (a[now] != nowb) {
      if (a[now] < nowb)
        --less;
      else
        ++less;
    }
    ++now;
    if (ans > less) {
      ans = less;
      pick = now;
    }
  }
  p[(lb + rb) / 2] = pick;
  insert(lb, (lb + rb) / 2 - 1, la, pick);
  insert((lb + rb) / 2 + 1, rb, pick, ra);
}
void solve() {
  dic.clear();
  cin >> n >> m;
  for (ll i = 1; i <= n; ++i) cin >> a[i];
  for (ll i = 1; i <= m; ++i) cin >> b[i];
  for (ll i = 1; i <= m + n + 2; ++i) bits[i] = 0;
  sort(b + 1, b + m + 1);
  insert(1, m, 1, n + 1);
  vector<ll> discrete;
  for (ll i = 1; i <= n; ++i) {
    discrete.emplace_back(a[i]);
  }
  for (ll i = 1; i <= m; ++i) {
    discrete.emplace_back(b[i]);
  }
  sort(discrete.begin(), discrete.end());
  discrete.erase(unique(discrete.begin(), discrete.end()), discrete.end());
  for (ll i = 0; i < discrete.size(); ++i) {
    dic[discrete[i]] = i + 1;
  }
  ll la = 1, lb = 1;
  ll ans = 0;
  ll cnt = 0;
  while (la <= n && lb <= m) {
    ++cnt;
    if (p[lb] <= la) {
      ll rk = dic[b[lb]];
      update(1, rk);
      ++lb;
      ans += cnt - query(rk);
    } else {
      ll rk = dic[a[la]];
      update(1, rk);
      ++la;
      ans += cnt - query(rk);
    }
  }
  while (la <= n) {
    ++cnt;
    ll rk = dic[a[la]];
    update(1, rk);
    ++la;
    ans += cnt - query(rk);
  }
  while (lb <= m) {
    ++cnt;
    ll rk = dic[b[lb]];
    update(1, rk);
    ++lb;
    ans += cnt - query(rk);
  }
  cout << ans << '\n';
}
signed main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  ll t;
  cin >> t;
  while (t--) {
    solve();
  }
}
