#include <bits/stdc++.h>
using namespace std;
const int MAXN = 3e5 + 5;
const int INF = 0x3f3f3f3f;
long long a[MAXN];
int n;
void solve() {
  cin >> n;
  long long sum = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    sum += a[i];
  }
  sort(a + 1, a + 1 + n);
  int m;
  cin >> m;
  for (int i = 1; i <= m; i++) {
    int x, y;
    cin >> x >> y;
    long long ans1 = 0, ans2 = 0;
    int l = 1, r = n;
    int pos = n;
    while (l <= r) {
      int mid = (l + r) >> 1;
      if (a[mid] > x) {
        pos = mid;
        r = mid - 1;
      } else {
        l = mid + 1;
      }
    }
    long long tmp1 = a[pos], tmp2 = a[1];
    if (pos > 1) tmp2 = a[pos - 1];
    if (tmp1 < x) ans1 = x - tmp1;
    ans1 += max((long long)0, y - (sum - tmp1));
    if (tmp2 < x) ans2 = x - tmp2;
    ans2 += max((long long)0, y - (sum - tmp2));
    cout << min(ans1, ans2) << endl;
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t;
  t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
