#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
using ll = long long;
using ld = double;
const ll mod = 1000000007;
ll gcd(ll a, ll b) {
  a = abs(a);
  b = abs(b);
  if (a == 0 or b == 0) return a + b;
  return gcd(b, a % b);
}
ll sum(ll a, ll b) {
  a += b;
  a %= mod;
  return a;
}
ll sub(ll a, ll b) {
  a += mod - b;
  a %= mod;
  return a;
}
inline ll mul(ll a, ll b) {
  if (a * b < mod) return a * b;
  return a * b % mod;
}
inline ll pew(ll a, ll b) {
  ll res = 1;
  while (b) {
    if (b & 1) res = mul(res, a);
    a = mul(a, a);
    b /= 2;
  }
  return res;
}
int parent[1200001];
int rnk[1200001];
void make_set(int v) {
  parent[v] = v;
  rnk[v] = 0;
}
int find_set(int v) {
  if (v == parent[v]) return v;
  return parent[v] = find_set(parent[v]);
}
void union_sets(int a, int b) {
  a = find_set(a);
  b = find_set(b);
  if (a != b) {
    if (rnk[a] < rnk[b]) swap(a, b);
    parent[b] = a;
    if (rnk[a] == rnk[b]) ++rnk[a];
  }
}
ll t[2200000];
void build() {
  for (ll i = 0; i < 2200000; i++) t[i] = 0;
}
void upd(ll v, ll tl, ll tr, ll p, ll d) {
  t[v] = (t[v] + d) % mod;
  if (tl == tr) return;
  ll tm = (tl + tr) / 2;
  if (p <= tm)
    upd(v * 2, tl, tm, p, d);
  else
    upd(v * 2 + 1, tm + 1, tr, p, d);
}
ll get(ll v, ll tl, ll tr, ll l, ll r) {
  if (tl >= l and tr <= r) return t[v];
  ll tm = (tl + tr) / 2;
  ll x = 0;
  if (l <= tm) x += get(v * 2, tl, tm, l, r);
  if (r > tm) x += get(v * 2 + 1, tm + 1, tr, l, r);
  x %= mod;
  return x;
}
bool cmp(pair<pair<ll, ll>, ll> a, pair<pair<ll, ll>, ll> b) {
  return a.first.second < b.first.second;
}
int main() {
  ios_base::sync_with_stdio(false);
  ll n;
  cin >> n;
  vector<pair<pair<ll, ll>, ll>> a(n);
  for (ll i = 0; i < n; i++) cin >> a[i].first.first >> a[i].first.second;
  ll k;
  cin >> k;
  for (ll i = 0; i < k; i++) {
    ll x;
    cin >> x;
    x--;
    a[x].second = 1;
  }
  sort(a.begin(), a.end(), cmp);
  vector<ll> dp(n);
  build();
  vector<pair<ll, ll>> p;
  for (ll i = 0; i < n; i++) {
    if (a[i].second == 1) p.push_back({a[i].first.first, i});
  }
  vector<ll> pr(n + 1);
  for (ll i = 0; i < n; i++) {
    ll x = get(1, 0, 2 * n, a[i].first.first, 2 * n);
    dp[i] = (x + 1) % mod;
    upd(1, 0, 2 * n, a[i].first.first, dp[i]);
    pr[i + 1] = (pr[i] + dp[i]) % mod;
  }
  sort(p.begin(), p.end());
  {
    vector<pair<ll, ll>> q;
    for (ll i = 0; i < p.size(); i++) {
      while (q.size() > 0) {
        if (a[q.back().second].first.second < a[p[i].second].first.second)
          q.pop_back();
        else
          break;
      }
      q.push_back(p[i]);
    }
    p = q;
  }
  ll S = 0;
  vector<pair<pair<ll, ll>, ll>> b(n);
  for (ll i = 0; i < n; i++) {
    b[i] = a[i];
    b[i].second = i;
  }
  sort(b.begin(), b.end());
  build();
  for (ll i = 0; i < n; i++) {
    if (b[i].first.second <= a[p[0].second].first.second) {
      upd(1, 0, 2 * n, b[i].first.first, dp[b[i].second]);
    }
  }
  ll d = 0;
  ll j = 0;
  for (ll i = 0; i < p.size(); i++) {
    S += get(1, 0, 2 * n, d, a[p[i].second].first.second) + mod -
         dp[p[i].second] + 1;
    S %= mod;
    d = a[p[i].second].first.first + 1;
    while (j < n and b[j].first.first < d) {
      if (b[j].first.second <= p[0].second) {
        upd(1, 0, 2 * n, b[j].first.first, mod - dp[b[j].second]);
      }
      j++;
    }
  }
  cout << S << endl;
}
