#include <bits/stdc++.h>
using namespace std;
long long T, n;
const long long N = 2e5 + 10;
long long ans[N];
struct node {
  long long id, x, y;
} a[N];
bool cmp(node a, node b) { return a.x < b.x; }
bool cmp2(node a, node b) { return a.y < b.y; }
signed main() {
  cin >> T;
  while (T--) {
    cin >> n;
    for (long long i = 1; i <= n; ++i) {
      long long x;
      cin >> x;
      a[i].id = i, a[i].x = x;
    }
    for (long long i = 1; i <= n; ++i) {
      long long x;
      cin >> x;
      a[i].y = x;
    }
    sort(a + 1, a + n + 1, cmp);
    long long mx = -1, sit;
    for (long long i = 1; i <= n; ++i) {
      if (a[i].y > mx) {
        mx = a[i].y;
        sit = i;
      }
    }
    for (long long i = sit; i <= n; ++i) ans[a[i].id] = 1;
    sort(a + 1, a + n + 1, cmp2);
    mx = -1, sit = 0;
    for (long long i = 1; i <= n; ++i) {
      if (a[i].x > mx) {
        mx = a[i].x;
        sit = i;
      }
    }
    for (long long i = sit; i <= n; ++i) ans[a[i].id] = 1;
    for (long long i = 1; i <= n; ++i) cout << ans[i], ans[i] = 0;
    cout << "\n";
  }
}
