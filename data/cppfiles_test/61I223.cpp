#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int a[N], b[N];
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i] >> b[i];
    sort(a + 1, a + 1 + n);
    sort(b + 1, b + 1 + n);
    int x = 1, y = 1, aa = 0, bb = 0;
    a[n + 1] = b[n + 1] = 0;
    long long ans_a = 1, ans_b = 1;
    for (int i = 1; i <= n + 1; i++) {
      if (a[i] == a[i - 1])
        x++;
      else
        ans_a *= x, x = 1, aa++;
      if (b[i] == b[i - 1])
        y++;
      else
        ans_b *= y, y = 1, bb++;
    }
    aa--, bb--;
    cout << aa << " " << bb << endl;
    cout << ans_a << " " << ans_b << endl;
    long long ans = aa * (aa - 1) * (aa - 2) / 6 * ans_a +
                    bb * (bb - 1) * (bb - 2) / 6 * ans_b;
    ans -= min(bb * (bb - 1) * (bb - 2) / 6, aa * (aa - 1) * (aa - 2) / 6);
    cout << ans << endl;
  }
  return 0;
}
