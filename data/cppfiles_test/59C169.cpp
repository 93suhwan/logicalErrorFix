#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const long long mod = 1000000007;
const int N = 1010;
int n;
int a[N][6];
void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= 5; j++) {
      cin >> a[i][j];
    }
  }
  if (n & 1) {
    cout << "NO" << endl;
    return;
  }
  for (int i = 1; i <= 5; i++) {
    for (int j = i + 1; j <= 5; j++) {
      int cnt1 = 0, cnt2 = 0, cnt3 = 0;
      for (int k = 1; k <= n; k++) {
        if (!a[k][i] && a[k][j]) cnt1++;
        if (!a[k][j] && a[k][i]) cnt2++;
        if (a[k][i] && a[k][j]) cnt3++;
      }
      if (cnt1 < n / 2 && cnt3 == 0)
        continue;
      else if (cnt2 < n / 2 && cnt3 == 0)
        continue;
      else {
        if (cnt1 < n / 2) {
          int t = cnt1;
          cnt1 += min(cnt3, n / 2 - cnt1);
          cnt3 -= min(cnt3, n / 2 - t);
        }
        if (cnt2 < n / 2) {
          int t = cnt2;
          cnt2 += min(cnt3, n / 2 - cnt2);
          cnt3 -= min(cnt3, n / 2 - t);
        }
        if (cnt1 == n / 2 && cnt2 == n / 2) {
          cout << "YES" << endl;
          return;
        }
      }
    }
  }
  cout << "NO\n";
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
