#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 9;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t, n;
  cin >> t;
  while (t--) {
    int ans = 0, cnt = 0;
    bool vis[N] = {};
    string a, b;
    cin >> n >> a >> b;
    for (int i = 0; i < n; i++) {
      if (a[i] != b[i]) {
        ans += 2;
        vis[i] = 1;
      } else if (a[i] == b[i] && a[i] == '1' && i != 0 && !vis[i - 1] &&
                 a[i - 1] == '0' && cnt) {
        vis[i] = 1;
        ans += 2;
        cnt--;
      } else if (a[i] == b[i] && a[i] == '0') {
        if (i != 0 && !vis[i - 1] && a[i - 1] == '1') {
          vis[i] = 1;
          ans += 2;
        } else
          cnt++;
      }
    }
    cout << ans + cnt << '\n';
  }
  return 0;
}
