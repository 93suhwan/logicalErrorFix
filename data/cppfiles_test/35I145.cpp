#include <bits/stdc++.h>
using namespace std;
long long a[105], b[105], ans[105];
void solve() {
  int n, m, cnt = 0;
  cin >> n >> m;
  memset(ans, 0, sizeof(ans));
  m++;
  while (n || m) {
    a[cnt] = n & 1;
    b[cnt] = m & 1;
    n >>= 1;
    m >>= 1;
    cnt++;
  }
  bool ok = 0;
  long long c = 0;
  while (cnt >= 0) {
    if (ok) {
      ans[cnt] = 0;
      cnt--;
      continue;
    }
    if (a[cnt] > b[cnt]) {
      ok = 1;
    } else if (a[cnt] < b[cnt]) {
      ans[cnt] = 1;
    }
    cnt--;
  }
  for (int i = 0; i < 36; i++) {
    c += ans[i] << i;
  }
  cout << c << endl;
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  ;
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
