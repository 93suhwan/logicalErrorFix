#include <bits/stdc++.h>
using namespace std;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
const long long maxn = 2e5 + 20;
const long long mod = 998244353;
const long long base = 1e9 + 100;
multiset<long long> st[maxn];
multiset<long long, greater<long long>> st1[maxn];
pair<long long, long long> a[maxn];
long long val[maxn];
long long ans = 0;
long long par[maxn];
long long find_par(long long u) {
  if (u == par[u]) return par[u];
  return par[u] = find_par(par[u]);
}
void dsu(long long x, long long y) {
  x = find_par(x);
  y = find_par(y);
  if (x == y) return;
  if (st[x].size() + st1[x].size() < st[y].size() + st1[y].size()) swap(x, y);
  for (auto to : st[y]) {
    st[x].insert(to);
  }
  for (auto to : st1[y]) {
    st1[x].insert(to);
  }
  st[y].clear();
  st1[y].clear();
  while (st[x].size() && st1[x].size() &&
         (*st[x].begin()) < (*st1[x].begin())) {
    long long h = (*st[x].begin());
    long long h1 = (*st1[x].begin());
    ans = (ans - h + h1);
    st[x].erase(st[x].begin());
    st1[x].erase(st1[x].begin());
    st[x].insert(h1);
    st1[x].insert(h);
  }
  par[y] = x;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  if (fopen("t.inp", "r")) {
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
  }
  long long n, m, q;
  cin >> n >> m >> q;
  for (int i = 1; i <= n; i++) {
    cin >> a[i].first;
    ans += a[i].first;
    a[i].second = 0;
  }
  for (int i = n + 1; i <= n + m; i++) {
    cin >> a[i].first;
    a[i].second = 1;
  }
  sort(a + 1, a + n + m + 1);
  n += m;
  long long pos1 = -1;
  long long pos = -1;
  vector<pair<long long, pair<long long, long long>>> vt;
  for (int i = n; i >= 1; i--) {
    par[i] = i;
    if (a[i].second)
      st1[i].insert(a[i].first);
    else
      st[i].insert(a[i].first);
    if (pos != -1) {
      vt.push_back(make_pair(a[pos].first - a[i].first, make_pair(i, pos)));
    }
    if (pos1 != -1) {
      vt.push_back(make_pair(a[pos1].first - a[i].first, make_pair(i, pos1)));
    }
    if (a[i].second == 0)
      pos = i;
    else
      pos1 = i;
  }
  sort(vt.begin(), vt.end());
  vector<pair<long long, long long>> vt1;
  vt1.push_back(make_pair(0, ans));
  for (int i = 0; i < vt.size(); i++) {
    long long j = i;
    while (j < vt.size() && vt[i].first == vt[j].first)
      dsu(vt[j].second.first, vt[j].second.second), j++;
    j--;
    vt1.push_back(make_pair(vt[i].first, ans));
    i = j;
  }
  while (q--) {
    long long k;
    cin >> k;
    long long pos = lower_bound(vt1.begin(), vt1.end(), make_pair(k, base)) -
                    vt1.begin() - 1;
    cout << vt1[pos].second << "\n";
  }
}
