#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, m, q, i, j, k, c, x, y, l, r, mid, ans, d, z, f, g, h,
      sum = 0;
  cin >> n;
  vector<long long int> v(n, 0);
  for (i = 0; i < n; i++) {
    cin >> c;
    v[i];
    sum += c;
  }
  sort(v.begin(), v.end());
  cin >> m;
  for (i = 0; i < m; i++) {
    cin >> x >> y;
    l = 0;
    r = n - 1;
    c = 0;
    while (l <= r) {
      mid = (l + r + 1) / 2;
      if (v[mid] == x) {
        c = 1;
        break;
      } else if (v[mid] < x) {
        l = mid + 1;
      } else {
        r = mid - 1;
      }
    }
    if (c == 1) {
      sum -= x;
      if (sum >= y) {
        ans = 0;
      } else {
        ans = y - sum;
      }
    } else {
      if (l >= n) {
        d = x - v[r];
        if (d <= 0) {
          d = 0;
        }
        ans += d;
        sum -= v[r];
        z = y - sum;
        if (z <= 0) {
          z = 0;
        }
        ans += z;
      } else if (r < 0) {
        r = l;
        d = x - v[r];
        if (d <= 0) {
          d = 0;
        }
        ans += d;
        sum -= v[r];
        z = y - sum;
        if (z <= 0) {
          z = 0;
        }
        ans += z;
      } else {
        d = abs(v[l] - x);
        z = abs(v[r] - x);
        if (d >= z) {
          d = x - v[r];
          if (d <= 0) {
            d = 0;
          }
          ans += d;
          sum -= v[r];
          z = y - sum;
          if (z <= 0) {
            z = 0;
          }
          ans += z;
        } else {
          r = l;
          d = x - v[r];
          if (d <= 0) {
            d = 0;
          }
          ans += d;
          sum -= v[r];
          z = y - sum;
          if (z <= 0) {
            z = 0;
          }
          ans += z;
        }
      }
    }
    cout << ans << endl;
  }
  return 0;
}
