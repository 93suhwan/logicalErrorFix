#include <bits/stdc++.h>
using namespace std;
const double pi = 3.1415926535897932384626433832795;
const int inf = 1e9;
const long long inf2 = 1e18;
const int mod = 1e9 + 7;
void boost() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
const int M = 1e6 + 5;
bool mpx[M], mpy[M];
void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  int x, y;
  vector<int> a1(n), a2(m);
  for (int i = 0; i < n; ++i) {
    cin >> x;
    a1[i] = x;
    mpx[x] = true;
  }
  for (int i = 0; i < m; ++i) {
    cin >> y;
    a2[i] = y;
    mpy[y] = true;
  }
  vector<pair<int, int>> p(k);
  for (int i = 0; i < k; ++i) cin >> p[i].first >> p[i].second;
  long long ans = 0;
  sort(p.begin(), p.end(), [&](pair<int, int> &p1, pair<int, int> &p2) {
    if (p1.second == p2.second) return p1.first < p2.first;
    return p1.second < p2.second;
  });
  int cnt = 0, i, j;
  i = 0;
  map<int, int> mm;
  while (i < k) {
    j = i;
    while (j + 1 < k && p[j + 1].second == p[i].second) j++;
    y = p[i].second;
    for (int l = i; l <= j; l++) {
      x = p[l].first;
      if (mpx[x] && mpy[y] == false) {
        ans += cnt - (mm[x]);
      }
      if (!mpy[y]) {
        mm[x]++;
        cnt++;
      }
    }
    if (mpy[y]) {
      cnt = 0;
      mm.clear();
    }
    i = j + 1;
  }
  cnt = 0;
  i = 0;
  sort(p.begin(), p.end(), [&](pair<int, int> &p1, pair<int, int> &p2) {
    if (p1.first == p2.first) return p1.second < p2.second;
    return p1.first < p2.first;
  });
  mm.clear();
  while (i < k) {
    j = i;
    while (j + 1 < k && p[j + 1].first == p[i].first) j++;
    x = p[i].first;
    for (int l = i; l <= j; l++) {
      y = p[l].second;
      if (mpy[y] && mpx[x] == false) {
        ans += cnt - mm[y];
      }
      if (!mpx[x]) {
        mm[y]++;
        cnt++;
      }
    }
    if (mpx[x]) {
      mm.clear();
      cnt = 0;
    }
    i = j + 1;
  }
  cout << ans << '\n';
  for (int i = 0; i < n; i++) mpx[a1[i]] = false;
  for (int i = 0; i < m; i++) mpy[a2[i]] = false;
  return;
}
int main() {
  boost();
  int tc = 1;
  cin >> tc;
  while (tc--) solve();
  return 0;
}
