#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int t, n, a[N], p, res;
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    p = n;
    res = 0;
    for (int i = n - 1; i > 0; i--)
      if (a[i] > a[p]) p = i, res++;
    cout << res << '\n';
  }
  return 0;
}
