#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long t;
  t = 1;
  cin >> t;
  while (t--) {
    long long n, d;
    cin >> n >> d;
    long long arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];
    bool vis[n];
    memset(vis, 0, sizeof vis);
    queue<int> q;
    for (int i = 0; i < n; i++) {
      if (arr[i] == 0) {
        q.push(i);
        vis[i] = 1;
      }
    }
    long long ans = 0;
    while (!q.empty()) {
      int s = q.size();
      while (s--) {
        int x = q.front();
        q.pop();
        if (x < (n - d)) {
          if (vis[x + d] == 0) {
            vis[x + d] = 1;
            q.push(x + d);
          }
        } else {
          int ind = x - (n - d);
          if (vis[ind] == 0) {
            vis[ind] = 1;
            q.push(ind);
          }
        }
      }
      ans++;
    }
    for (int i = 0; i < n; i++) {
      if (vis[i] == 0) {
        ans = 0;
        break;
      }
    }
    cout << ans - 1 << "\n";
  }
  return 0;
}
