#include <bits/stdc++.h>
using namespace std;
using Vi = vector<int>;
using i64 = long long;
using ll = long long;
using Pi = pair<int, int>;
mt19937 mrand(time(0));
int rnd(int x) { return mrand() % x; }
const int N = 500005;
const int M = 40005;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  int BL = (int)sqrt(m);
  vector<Pi> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i].first >> a[i].second;
  Vi ans(m + 1);
  vector<vector<Pi>> nd(n);
  vector<Pi> day(m);
  for (int i = 0; i < m; ++i) {
    cin >> day[i].first >> day[i].second;
    --day[i].second;
    if (day[i].first == 1)
      nd[day[i].second].emplace_back(i, m - 1);
    else
      nd[day[i].second].back().second = i - 1;
  }
  for (int i = 0; i < n; ++i) {
    int x = a[i].first, y = a[i].second;
    if (x + y < BL) continue;
    for (auto j : nd[i]) {
      for (int k = j.first; k <= j.second; k += x + y) {
        if (k + x <= j.second) {
          ++ans[k + x];
          --ans[min(k + x + y, j.second + 1)];
        }
      }
    }
  }
  for (int i = 1; i < m; ++i) ans[i] += ans[i - 1];
  vector<Vi> B(BL + 1);
  for (int i = 1; i < BL + 1; ++i) B[i].resize(i, 0);
  Vi vis(n);
  for (int i = 0; i < m; ++i) {
    int x = a[day[i].second].first, y = a[day[i].second].second;
    if (x + y >= BL) continue;
    if (day[i].first == 1) {
      for (int j = i + x; j < i + x + y; ++j) ++B[x + y][j % (x + y)];
      vis[day[i].second] = i;
    } else {
      int t = vis[day[i].second];
      for (int j = t + x; j < t + x + y; ++j) --B[x + y][j % (x + y)];
    }
    for (int j = 1; j < BL + 1; ++j) ans[i] += B[j][i % j];
  }
  for (int i = 0; i < m; ++i) cout << ans[i] << endl;
  return 0;
}
