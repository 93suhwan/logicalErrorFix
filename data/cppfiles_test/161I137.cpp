#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int a[n][2];
    for (int i = 0; i < n; i++) {
      cin >> a[i][0] >> a[i][1];
    }
    for (int i = 0; i < n; i++) {
      int l = a[i][0], r = a[i][1];
      cout << l << " " << r << " ";
      if (l == r) {
        cout << l << endl;
        continue;
      }
      map<int, bool> vis;
      for (int j = 0; j < n; j++) {
        if (i != j && a[j][0] >= l && a[j][1] <= r) {
          vis[a[j][0]] = true;
          vis[a[j][1]] = true;
        }
      }
      for (int j = l; j <= r; j++) {
        if (!vis[j]) {
          cout << j << endl;
          goto here;
        }
      }
    here:;
    }
  }
  return 0;
}
