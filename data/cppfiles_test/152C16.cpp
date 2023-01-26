#include <bits/stdc++.h>
using namespace std;
const int N = 1000000, INF = 0x3f3f3f3f;
int aa[N], dp0[N], pp0[N], dp1[N], pp1[N], *dp;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
      int a;
      cin >> a;
      aa[i] = a;
    }
    fill(dp0, dp0 + n, INF);
    fill(dp1, dp1 + n, INF);
    dp0[0] = dp1[0] = -INF;
    for (int i = 0; i + 1 < n; i++) {
      if (dp0[i] < aa[i + 1] && dp0[i + 1] > aa[i])
        dp0[i + 1] = aa[i], pp0[i + 1] = 1;
      if (dp1[i] < aa[i + 1] && dp0[i + 1] > -aa[i])
        dp0[i + 1] = -aa[i], pp0[i + 1] = -1;
      if (aa[i] < aa[i + 1] && dp0[i + 1] > dp0[i])
        dp0[i + 1] = dp0[i], pp0[i + 1] = 1;
      if (-aa[i] < aa[i + 1] && dp0[i + 1] > dp1[i])
        dp0[i + 1] = dp1[i], pp0[i + 1] = -1;
      if (dp0[i] < -aa[i + 1] && dp1[i + 1] > aa[i])
        dp1[i + 1] = aa[i], pp1[i + 1] = 1;
      if (dp1[i] < -aa[i + 1] && dp1[i + 1] > -aa[i])
        dp1[i + 1] = -aa[i], pp1[i + 1] = -1;
      if (-aa[i] < -aa[i + 1] && dp1[i + 1] > dp1[i])
        dp1[i + 1] = dp1[i], pp1[i + 1] = -1;
    }
    if (dp0[n - 1] != INF || dp1[n - 1] != INF) {
      int p = dp0[n - 1] != INF ? 1 : -1;
      cout << "YES\n";
      for (int i = n - 1; i >= 0; i--) {
        aa[i] *= p;
        p = p == 1 ? pp0[i] : pp1[i];
      }
      for (int i = 0; i < n; i++) cout << aa[i] << ' ';
      cout << '\n';
    } else
      cout << "NO\n";
  }
  return 0;
}
