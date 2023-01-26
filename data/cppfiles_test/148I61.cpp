#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 9;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t, a[N], b[N], c[N], d[N];
  cin >> t;
  while (t--) {
    int h, w, k, p, n, y;
    cin >> w >> h;
    cin >> k;
    for (int i = 0; i < k; i++) cin >> a[i];
    cin >> p;
    for (int i = 0; i < p; i++) cin >> b[i];
    cin >> n;
    for (int i = 0; i < n; i++) cin >> c[i];
    cin >> y;
    for (int i = 0; i < y; i++) cin >> d[i];
    sort(a, a + k);
    sort(b, b + p);
    sort(c, c + n);
    sort(d, d + y);
    int ans = 0;
    ans = max(ans, (a[k - 1] - a[0]) * h);
    ans = max(ans, (b[p - 1] - b[0]) * h);
    ans = max(ans, (c[n - 1] - c[0]) * w);
    ans = max(ans, (d[y - 1] - d[0]) * w);
    cout << ans << '\n';
  }
}
