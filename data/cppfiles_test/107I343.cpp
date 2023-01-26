#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 100;
int z[N], ans[N];
int n, m;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int a, b, f = 1;
    cin >> n >> a >> b;
    if (abs(a - b) > 1 || a + b > n - 2) {
      cout << -1 << endl;
      continue;
    } else if (a >= b)
      for (int i = 1; i <= n; i++) z[i] = i;
    else
      for (int i = 1; i <= n; i++) z[i] = n - i + 1;
    ans[1] = z[1];
    int i = 2, j = n, k = 2, sum = a + b;
    for (int p = 1; p <= sum; k++, p++) {
      if (p & 1)
        ans[k] = z[j--], b--;
      else
        ans[k] = z[i++], a--;
    }
    while (k <= n) ans[k++] = z[j--];
    for (int p = 1; p <= n; p++) cout << ans[p] << ' ';
    cout << endl;
  }
}
