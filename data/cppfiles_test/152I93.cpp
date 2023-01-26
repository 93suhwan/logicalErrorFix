#include <bits/stdc++.h>
using namespace std;
const int N = 3e6 + 1e3 + 7;
int T, n, a[N], vis[N];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> T;
  while (T--) {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i], vis[i] = 0;
    int ls = -1e9;
    int ok = 1;
    for (int i = 1; i <= n; i++) {
      if (-a[i] > ls)
        a[i] = -a[i], vis[i] = 1, ls = a[i];
      else if (a[i] > ls)
        vis[i] = 1, ls = a[i];
    }
    ls = -1e9;
    for (int i = 1; i <= n; i++) {
      if (vis[i]) continue;
      if (-a[i] > ls)
        a[i] = -a[i], vis[i] = 1, ls = a[i];
      else if (a[i] > ls)
        vis[i] = 1, ls = a[i];
      else
        ok = 0, ls = 114514;
    }
    if (ok) {
      cout << "YES\n";
      for (int i = 1; i <= n; i++) cout << a[i] << " \n"[i == n];
    } else
      cout << "NO\n";
  }
}
