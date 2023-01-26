#include <bits/stdc++.h>
using namespace std;
const int MAXN = 3e5 + 5;
const int INF = 0x3f3f3f3f;
long long a[MAXN];
struct node {
  long long x, y;
} b[MAXN];
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
    cin >> b[i].x >> b[i].y;
    int l = 1, r = n;
    int pos = n;
    while (l <= r) {
      int mid = (l + r) >> 1;
      if (a[mid] > b[i].x) {
        pos = mid;
        r = mid - 1;
      } else {
        l = mid + 1;
      }
    }
    long long ans1 = 0, ans2 = 0;
    long long tmp1 = a[pos];
    if (tmp1 < b[i].x) ans1 = b[i].x - tmp1;
    ans1 += max(0ll, (b[i].y - sum + tmp1));
    long long tmp2 = a[1];
    if (pos - 1 >= 1) tmp2 = a[pos - 1];
    if (tmp2 < b[i].x) ans2 = b[i].x - tmp2;
    ans2 += max(0ll, (b[i].y - sum + tmp2));
    cout << min(ans1, ans2) << "\n";
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
