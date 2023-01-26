#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int a[N], b[N], len;
bool vis[N];
int xx(int x) {
  if (x & 1)
    return x / 2;
  else
    return x / 2 - 1;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    len = 0;
    memset(vis, 0, sizeof vis);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      if (a[i] >= 1 && a[i] <= n) {
        if (!vis[a[i]])
          vis[a[i]] = 1;
        else
          b[++len] = a[i];
      } else {
        b[++len] = a[i];
      }
    }
    sort(b + 1, b + len + 1);
    int j = len;
    bool flag = 0;
    for (int i = n; i > 0; i--) {
      if (vis[i]) continue;
      if (xx(b[j]) < i) {
        flag = 1;
        break;
      } else {
        j--;
      }
    }
    if (flag)
      cout << -1 << endl;
    else
      cout << len << endl;
  }
  return 0;
}
