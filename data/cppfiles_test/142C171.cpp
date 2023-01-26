#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
vector<vector<int> > a;
int n, m;
bool tmam(int x) {
  vector<int> f(n, 0);
  bool found = 0;
  for (int i = 0; i < m; i++) {
    bool tm = 0;
    for (int j = 0; j < n; j++) {
      if (a[j][i] >= x) {
        tm = 1;
        f[j]++;
        if (f[j] > 1) found = 1;
      }
    }
    if (tm == 0) return 0;
  }
  return found;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    cin >> n >> m;
    a = vector<vector<int> >(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cin >> a[i][j];
      }
    }
    int low = 0, high = (int)1e9 + 5, ans = 0;
    while (high >= low) {
      int mid = low + high >> 1;
      if (tmam(mid)) {
        ans = mid;
        low = mid + 1;
      } else {
        high = mid - 1;
      }
    }
    cout << ans << '\n';
  }
  return 0;
}
