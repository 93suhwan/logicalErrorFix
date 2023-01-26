#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, m;
  cin >> n >> m;
  int ans = n;
  vector<int> mp(n + 1, 0);
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    int mx = max(x, y);
    int mn = min(x, y);
    if (mp[mn] == 0) ans--;
    mp[mn]++;
  }
  int ans1 = ans;
  int q;
  cin >> q;
  for (int i = 0; i < q; i++) {
    int ch;
    cin >> ch;
    if (ch == 1) {
      int x, y;
      cin >> x >> y;
      int mx = max(x, y);
      int mn = min(x, y);
      if (mp[mn] == 0) ans--;
      mp[mn]++;
    } else if (ch == 2) {
      int x, y;
      cin >> x >> y;
      int mx = max(x, y);
      int mn = min(x, y);
      mp[mn]--;
      if (mp[mn] == 0) ans++;
    } else {
      cout << ans << endl;
    }
  }
}
