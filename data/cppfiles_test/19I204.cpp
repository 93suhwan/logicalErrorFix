#include <bits/stdc++.h>
using namespace std;
int a[15];
const int maxn = 2e5 + 5;
int vis[maxn];
void solve() {
  int n;
  cin >> n;
  int f = 0;
  memset(vis, 0, sizeof(vis));
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    if (a[i] <= 0) f = 1;
    if (a[i] > 0) {
      vis[a[i]]++;
      if (vis[a[i]] >= 2) f = 1;
    }
  }
  if (f)
    cout << "YES" << endl;
  else {
    sort(a + 1, a + 1 + n);
    int d = a[2] - a[1];
    int f = 2;
    for (int i = 2; i <= n; i++) {
      if (a[i] - a[i - 1] != d) {
        f--;
        break;
      }
    }
    for (int i = 2; i <= n; i++) {
      if (a[i] != a[i - 1] * 2) {
        f--;
        break;
      }
    }
    if (f)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
}
int main() {
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) solve();
}
