#include <bits/stdc++.h>
using namespace std;
const long double PI = acos(-1.0);
const int MOD = 1e9 + 7;
const int INF = 1 << 30;
const long double EPS = 1e-6;
const int MAXN = 1000 + 5;
int a[MAXN][5];
int n;
void solve() {
  cin >> n;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < 5; ++j) cin >> a[i][j];
  for (int i = 0; i < 5; ++i) {
    for (int j = i + 1; j < 5; ++j) {
      vector<int> cnt(3);
      for (int k = 0; k < n; ++k) {
        if (a[k][i] && a[k][j])
          cnt[2]++;
        else if (a[k][i])
          cnt[0]++;
        else if (a[k][j])
          cnt[1]++;
      }
      if (cnt[0] + cnt[2] >= n / 2 && cnt[1] + cnt[2] >= n / 2) {
        cout << "YES" << '\n';
        return;
      }
    }
  }
  cout << "NO" << '\n';
  return;
}
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr);
  int T = 1;
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}
