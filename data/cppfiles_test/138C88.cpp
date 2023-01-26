#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")
using namespace std;
using ll = long long;
using db = long double;
using pi = pair<int, int>;
using pl = pair<ll, ll>;
using pd = pair<db, db>;
using vi = vector<int>;
using vb = vector<bool>;
using vl = vector<ll>;
using vd = vector<db>;
using vs = vector<string>;
using vpi = vector<pi>;
using vpl = vector<pl>;
using vpd = vector<pd>;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 rng64(chrono::steady_clock::now().time_since_epoch().count());
const int MAXN = 1e6 + 5;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const ll INF64 = ll(4e18) + 5;
const db EPS = 1e-9;
const db PI = acos((db)-1);
int uf[MAXN];
int qtd[MAXN];
ll maxx[MAXN];
ll pre[MAXN];
ll ans = 0;
ll query(ll i, ll j) { return pre[j] - (i ? pre[i - 1] : 0ll); }
int find(int x) {
  if (uf[x] == x) return x;
  return uf[x] = find(uf[x]);
}
void uni(int a, int b) {
  int aa = find(a);
  int bb = find(b);
  uf[aa] = bb;
  maxx[bb] = max(maxx[bb], maxx[aa]);
  ll v1 = query(maxx[aa] - qtd[aa] + 1, maxx[aa]);
  ll v2 = query(maxx[bb] - qtd[bb] - qtd[aa] + 1, maxx[bb] - qtd[bb]);
  ans += v2 - v1;
  qtd[bb] += qtd[aa];
}
void solve() {
  int n;
  cin >> n;
  int m, q;
  cin >> m >> q;
  vpl a(n + m);
  for (int i = 0; i < n; i++) {
    cin >> a[i].first;
    a[i].second = 1;
  }
  for (int i = 0; i < m; i++) {
    cin >> a[i + n].first;
    a[i + n].second = 0;
  }
  sort(a.begin(), a.end());
  for (int i = 0; i < n + m; i++) {
    uf[i] = i;
    qtd[i] = a[i].second;
    maxx[i] = i;
    pre[i] = a[i].first + (i ? pre[i - 1] : 0);
    if (a[i].second == 1) {
      ans += a[i].first;
    }
  }
  priority_queue<pl, vpl, greater<pl>> pqg;
  for (int i = n + m - 2; i >= 0; i--) {
    ll dif = a[i + 1].first - a[i].first;
    pqg.push(make_pair(dif, -i));
  }
  vl ansf(q);
  for (int i = 0; i < q; i++) {
    int k;
    cin >> k;
    pqg.push(make_pair(k, i + 1));
  }
  while (!pqg.empty()) {
    pl top = pqg.top();
    pqg.pop();
    if (top.second >= 1) {
      ansf[top.second - 1] = ans;
    } else {
      int i = -top.second;
      uni(i, i + 1);
    }
  }
  for (int i = 0; i < q; i++) {
    cout << ansf[i] << '\n';
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
