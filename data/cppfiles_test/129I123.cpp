#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int a[N], b[N];
signed main() {
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    int tot = 0, cnt = 0;
    for (int i = 1; i <= n; i++) b[i] = 0;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      if (a[i] <= n)
        b[a[i]]++, cnt++;
      else if (a[i] > 2 * n) {
        tot++;
      } else {
        b[(a[i] - 1) / 2]++;
      }
    }
    if (cnt + tot == n) {
      cout << tot << endl;
      continue;
    }
    int sum = 0, fg = 1;
    for (int i = 1; i <= n; i++) {
      sum += b[i];
      if (sum > i) {
        fg = 0;
        break;
      }
    }
    if (fg) {
      cout << n - cnt << endl;
    } else
      cout << "-1\n";
  }
}
