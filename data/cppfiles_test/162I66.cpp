#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int test_case;
  cin >> test_case;
  for (int test = 1; test <= test_case; test++) {
    int n;
    cin >> n;
    vector<int> v(n + 10);
    int ans;
    for (int i = 1; i <= n; i++) {
      cin >> v[i];
      ans = min(ans, v[i]);
    }
    int lo = ans + 1, hi = 1e9;
    while (lo <= hi) {
      int mid = (lo + hi) / 2;
      vector<int> a = v;
      for (int i = 1; i < n; i++) {
        if (a[i] >= mid) continue;
        int x, y, r, k;
        x = mid - a[i];
        x = (x + 1) / 2;
        y = 0, r, k = 0;
        y = a[i + 2] / 3;
        r = min(x, y);
        k = r, a[i] += r + r;
        a[i + 2] -= 3 * r;
        x = mid - a[i];
        x = max(x, 0);
        y = a[i + 1] / 3;
        r = min(x, y);
        a[i + 1] -= r;
        a[i] += r;
        a[i + 1] += k;
      }
      bool flag = 1;
      for (int j = 1; j <= n; j++) {
        if (a[j] < mid) flag = 0;
      }
      if (flag) {
        ans = mid, lo = mid + 1;
      } else
        hi = mid - 1;
    }
    cout << ans << '\n';
  }
}
