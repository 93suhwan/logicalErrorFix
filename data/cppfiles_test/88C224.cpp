#include <bits/stdc++.h>
#pragma GCC optimize("O2")
const long long N = 3e2 + 3, inf = 1e18, mod = 1e9 + 7;
typedef long long Array[N];
using namespace std;
ostream &operator<<(ostream &os, const pair<long long, long long> &Pair) {
  os << "(" << Pair.first << "," << Pair.second << ")";
  return os;
}
long long n, m;
pair<long long, long long> a[N * N];
long long b[N * N];
long long taken[N][N];
void solve() {
  cin >> n >> m;
  memset(taken, 0, sizeof(taken));
  for (long long i = 1; i <= m * n; i++) {
    cin >> a[i].first;
    a[i].second = i;
    b[i] = a[i].first;
  }
  sort(a + 1, a + n * m + 1);
  map<long long, vector<pair<long long, long long>>> mp;
  long long times = 0;
  for (long long i = 1; i <= n; i++)
    for (long long j = 1; j <= m; j++) mp[a[++times].first].push_back({i, j});
  for (auto &[key, v] : mp) {
    sort(v.begin(), v.end(),
         [&](const pair<long long, long long> &x,
             const pair<long long, long long> &y) {
           if (x.first == y.first) return x.second < y.second;
           return x.first > y.first;
         });
  }
  long long res = 0;
  for (long long i = 1; i <= n * m; i++) {
    auto [x, y] = mp[b[i]].back();
    mp[b[i]].pop_back();
    for (long long j = 1; j <= y; j++) res += taken[x][j];
    taken[x][y] = 1;
  }
  cerr << "res"
       << " = " << res << '\n';
  cout << res << '\n';
}
int main() {
  if (fopen("inp"
            ".inp",
            "r"))
    freopen(
        "inp"
        ".inp",
        "r", stdin);
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long TEST;
  cin >> TEST;
  while (TEST--) solve();
}
