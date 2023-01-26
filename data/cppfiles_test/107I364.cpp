#include <bits/stdc++.h>
using namespace std;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    long long n, x, i, mx, mn, flag = 0;
    cin >> n >> mx >> mn;
    if (n <= 2 || ((mn + mx) > (n - 2) || (abs(mx - mn) > 1))) {
      cout << -1 << endl;
      continue;
    }
    int a[n + 10];
    memset(a, 0, sizeof a);
    long long cnt1 = 1, cnt2 = n;
    if (mn >= mx) {
      if (mn == mx) {
        flag = 1;
      }
      for (i = 1; mn > 0; i += 2) {
        mn--;
        a[i] = cnt1;
        cnt1++;
      }
      for (i = 0; i < n; i++) {
        if (a[i] == 0) {
          a[i] = cnt1;
          cnt1++;
        }
      }
      if (flag) {
        a[n - 1] = n - 1;
        a[n - 2] = n;
      }
    } else {
      for (i = 1; mx > 0; i += 2) {
        mx--;
        a[i] = cnt2;
        cnt2--;
      }
      for (i = 0; i < n; i++) {
        if (a[i] == 0) {
          a[i] = cnt2;
          cnt2--;
        }
      }
    }
    for (i = 0; i < n; i++) {
      cout << a[i] << " ";
    }
    cout << endl;
  }
}
