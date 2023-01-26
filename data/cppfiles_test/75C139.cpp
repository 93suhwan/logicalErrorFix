#include <bits/stdc++.h>
const int N = 1e6 + 10;
const int mod = 1e9 + 7;
const int inf = 0x3f3f3f3f;
const double eps = 1e-8;
const double pi = acos(-1);
const double INF = 1e18;
using namespace std;
struct edge {
  int len, mx;
} a[N];
int cmp(edge x, edge y) { return x.mx < y.mx; }
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, i, j;
    cin >> n;
    for (i = 1; i <= n; i++) {
      cin >> a[i].len;
      a[i].mx = -inf;
      for (j = 1; j <= a[i].len; j++) {
        int x;
        cin >> x;
        a[i].mx = max(a[i].mx, x - j + 1);
      }
    }
    sort(a + 1, a + n + 1, cmp);
    int ans, l = 1, r = inf;
    while (l <= r) {
      int mid = (l + r) / 2;
      int f = 1, sum = mid;
      for (i = 1; i <= n; i++) {
        if (sum <= a[i].mx) {
          f = 0;
          break;
        }
        sum += a[i].len;
      }
      if (f) {
        r = mid - 1;
        ans = mid;
      } else
        l = mid + 1;
    }
    cout << ans << endl;
  }
  return 0;
}
