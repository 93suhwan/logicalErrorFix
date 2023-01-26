#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
const long long int base = 313;
const long long int inf = 1e16;
const long long int mod = 998244353;
int a[N][10];
inline void solve() {
  int n;
  cin >> n;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 5; j++) cin >> a[i][j];
  }
  for (int i = 1; i < n; i++) {
    int cnt1 = 0, cnt2 = 0;
    for (int j = 0; j < 5; j++) {
      cnt1 += (a[i][j] > a[ans][j]);
      cnt2 += (a[i][j] < a[ans][j]);
    }
    if (cnt1 >= 3) continue;
    if (cnt2 >= 3)
      ans = i;
    else
      ans = i + 1;
  }
  if (ans == n) {
    cout << -1 << endl;
    return;
  }
  for (int i = 0; i < n; i++) {
    if (i == ans) continue;
    int cnt = 0;
    for (int j = 0; j < 5; j++) {
      cnt += (a[i][j] > a[ans][j]);
    }
    if (cnt < 3) {
      cout << -1 << endl;
      return;
    }
  }
  cout << ans + 1 << endl;
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  int q;
  cin >> q;
  while (q--) {
    solve();
  }
  return 0;
}
