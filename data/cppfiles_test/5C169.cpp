#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5, mod = 1e9 + 7;
int T, n;
bool vis[N];
int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> T;
  while (T--) {
    cin >> n;
    string a, b;
    cin >> a >> b;
    int res = 0;
    memset(vis, 0, sizeof vis);
    for (int i = 0; i < n; i++) {
      if (b[i] == '1') {
        if (a[i] == '0') {
          res++;
          vis[i] = 1;
        } else {
          if (i && !vis[i - 1] && a[i - 1] == '1')
            res++, vis[i - 1] = 1;
          else if (i < n - 1 && a[i + 1] == '1')
            res++, vis[i + 1] = 1;
        }
      }
    }
    cout << res << endl;
  }
  return 0;
}
