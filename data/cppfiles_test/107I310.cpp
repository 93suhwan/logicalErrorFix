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
    long long n, x, i, mx, mn, err = 0;
    cin >> n >> mx >> mn;
    long long aa = mx, bb = mn;
    x = (n - 2) / 2;
    if (n % 2) x++;
    if (n <= 2 || ((mn + mx) > (n - 2))) {
      cout << -1 << endl;
      continue;
    }
    int a[n + 10];
    memset(a, 0, sizeof a);
    long long cnt1 = 1, cnt2 = n;
    long long bos = 0;
    if (mn > mx) {
      for (i = 1; mn > 0;) {
        a[i] = cnt1;
        cnt1++;
        mn--;
        if (mx <= 0) {
          i += 3;
          if (i >= n - 1 and mn > 0) {
            err = 1;
            break;
          }
        } else {
          i += 2;
        }
        bos++;
        mx--;
      }
      if (err) {
        cout << -1 << endl;
        continue;
      }
      if (aa == 0) {
        for (i = 0; i < n; i++) {
          if (a[i] == 0) {
            a[i] = cnt2;
            cnt2--;
          }
        }
      } else {
        for (i = 0; i < n; i++) {
          if (a[i] == 0) {
            a[i] = cnt1;
            cnt1++;
          }
        }
      }
    } else {
      for (i = 1; mx > 0;) {
        a[i] = cnt2;
        cnt2--;
        mx--;
        if (mn <= 0) {
          i += 3;
          if (i >= n - 1 and mx > 0) {
            err = 1;
            break;
          }
        } else {
          i += 2;
        }
        mn--;
      }
      if (err) {
        cout << -1 << endl;
        continue;
      }
      if (mn > 0) {
        for (i = 0; i < n; i++) {
          if (a[i] == 0) {
            a[i] = cnt2;
            cnt2--;
          }
        }
      } else {
        for (i = 0; i < n; i++) {
          if (a[i] == 0) {
            a[i] = cnt1;
            cnt1++;
          }
        }
      }
    }
    for (i = 0; i < n; i++) {
      cout << a[i] << " ";
    }
    cout << endl;
  }
}
