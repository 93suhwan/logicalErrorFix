#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n, vis[N], a[N];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    int ans = 0;
    for (int i = 1, _n = n; i <= _n; ++i) vis[i] = 0;
    for (int i = 1, _n = n; i <= _n; ++i) {
      int x;
      cin >> x;
      if (x <= n && !vis[x]) {
        vis[x] = 1;
        a[i] = 0;
      } else {
        a[i] = (x - 1) / 2;
        ans += 1;
      }
    }
    sort(a + 1, a + 1 + n, greater<int>());
    int j = 1;
    for (int i = n, _n = 1; i >= _n; --i)
      if (!vis[i]) {
        if (a[j++] < i) {
          ans = -1;
          break;
        }
      }
    cout << ans << '\n';
  }
}
