#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
const int M = 1000010;
const int INF = 0x3f3f3f3f;
const long long mod = 998244353;
int n, m;
int cnt[N];
void solve() {
  cin >> m >> n;
  vector<vector<int>> a(n + 1, vector<int>(m + 1));
  for (int i = 1; i <= m; i++)
    for (int j = 1; j <= n; j++) cin >> a[j][i];
  int l = 0, r = 1e9;
  set<int> S;
  while (l < r) {
    int mid = l + r + 1 >> 1;
    bool flag = true;
    for (int i = 1; i <= n; i++) {
      int Max = 0;
      for (int j = 1; j <= m; j++) Max = max(Max, a[i][j]);
      if (Max < mid) flag = false;
    }
    for (int i = 1; i <= m; i++) cnt[i] = 0;
    bool f = false;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++)
        if (a[i][j] >= mid) {
          cnt[j]++;
          if (cnt[j] == 2) f = true;
        }
    }
    if (flag && f)
      l = mid;
    else
      r = mid - 1;
  }
  cout << l << '\n';
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  cout << fixed << setprecision(10);
  int T(1);
  cin >> T;
  for (int o = 1; o <= T; o++) {
    solve();
  }
  return 0;
}
