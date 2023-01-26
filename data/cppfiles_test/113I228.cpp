#include <bits/stdc++.h>
using namespace std;
int T, n, m, a[100005];
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  sort(a + 1, a + 1 + n);
  int sum = 0, maxn = a[n];
  for (int i = 1; i <= n; i++) sum += a[i];
  cin >> m;
  while (m--) {
    int x, y;
    cin >> x >> y;
    int q = lower_bound(a + 1, a + 1 + n, x) - a - 1, p = max(1, q - 1);
    cout << min(max(0, x - a[q]) + max(0, y - sum + a[q]),
                max(0, x - a[p]) + max(0, y - sum + a[p]))
         << endl;
  }
}
