#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const long long maxN = 300005;
const long long oo = 1e18 + 7;
long long n, a[maxN];
long long x, y, z, k;
vector<long long> vc[maxN];
long long par[maxN];
long long h[maxN];
long long find(long long i) {
  if (par[i] == i)
    return i;
  else
    return par[i] = find(par[i]);
}
void unite(long long i, long long j) { par[find(i)] = find(j); }
void dfs_intern(long long node, long long pare, long long hei) {
  h[node] = hei;
  par[node] = pare;
  ++hei;
  for (long long cc : vc[node])
    if (cc != pare) {
      dfs_intern(cc, node, hei);
    }
}
vector<long long> qrym[maxN];
bool isswap[maxN];
bool xr[maxN];
bool used[maxN];
long long cnt = 0;
long long o;
void safe_game() {
  cout << "YES\n";
  for (long long i = 1; i <= o; ++i) {
    if (isswap[i]) reverse(qrym[i].begin(), qrym[i].end());
    cout << qrym[i].size() << "\n";
    for (long long cc : qrym[i]) cout << cc << " ";
    cout << "\n";
  }
}
bool dfs_con(long long node) {
  used[node] = 1;
  long long cn = 0;
  for (long long cc : vc[node])
    if (!used[cc]) {
      ++cn;
      dfs_con(cc);
    }
  if (cn & 1) {
    cnt -= cn / 2;
    return 0;
  } else {
    cnt -= cn / 2;
    ++cnt;
    return 1;
  }
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n >> z;
  for (long long i = 1; i <= n; ++i) par[i] = i;
  memset(xr, 0, sizeof(xr));
  while (z--) {
    cin >> x >> y;
    if (find(x) != find(y)) {
      vc[x].push_back(y);
      vc[y].push_back(x);
      unite(x, y);
    }
  }
  dfs_intern(1, 0, 0);
  cin >> o;
  for (long long i = 1; i <= o; ++i) {
    cin >> x >> y;
    if (h[x] < h[y]) {
      swap(x, y);
      isswap[i] = 1;
    } else
      isswap[i] = 0;
    vector<long long> v1, v2;
    while (h[x] > h[y]) {
      v1.push_back(x);
      xr[x] = !xr[x];
      x = par[x];
    }
    while (x != y) {
      v1.push_back(x);
      v2.push_back(y);
      xr[x] = !xr[x];
      xr[y] = !xr[y];
      x = par[x];
      y = par[y];
    }
    qrym[i] = v1;
    reverse(v2.begin(), v2.end());
    qrym[i].push_back(x);
    for (long long cc : v2) qrym[i].push_back(cc);
  }
  for (long long i = 1; i <= n; ++i) vc[i].clear();
  for (long long i = 2; i <= n; ++i)
    if (xr[i]) {
      vc[i].push_back(par[i]);
      vc[par[i]].push_back(i);
    }
  memset(used, 0, sizeof(used));
  for (long long i = 1; i <= n; ++i)
    if (!used[i]) {
      if (dfs_con(i)) --cnt;
    }
  if (cnt)
    cout << "NO\n" << cnt << "\n";
  else
    safe_game();
}
