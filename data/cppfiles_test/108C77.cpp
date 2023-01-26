#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
int a[N], b[N], p[N], ans[N];
bool cmp(int u, int v) { return a[u] < a[v]; }
int main() {
  ios::sync_with_stdio(false), cin.tie(0);
  int n, t;
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i], p[i] = i, ans[i] = 0;
    sort(p + 1, p + 1 + n, cmp);
    int mb = b[p[n]];
    ans[p[n]] = 1;
    for (int i = n - 1; i; i--) {
      if (b[p[i]] > mb) {
        for (int j = i; j <= n && !ans[p[j]]; j++) {
          ans[p[j]] = 1;
          mb = min(mb, b[p[j]]);
        }
      }
    }
    for (int i = 1; i <= n; i++) cout << ans[i];
    cout << "\n";
  }
  return 0;
}
