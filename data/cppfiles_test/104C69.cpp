#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n, m;
int a[N], b[N], c[N], d[N], e[N], f[N];
long long fun(int a[], int b[], int c[], int d[]) {
  long long sum1 = 0, sum2 = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] >= m) {
      c[i] = a[i] - m;
      d[i] = b[i];
    } else {
      c[i] = 0;
      d[i] = b[i] - (m - a[i]);
    }
    sum1 += c[i];
    sum2 += d[i];
  }
  for (int i = 0; i < n; i++) {
    if (sum1 >= sum2) break;
    long long low = 0, high = min(a[i] - c[i], d[i]);
    long long now = 0;
    while (low <= high) {
      long long mid = (low + high) / 2;
      if (sum1 + mid <= sum2 - mid) {
        low = mid + 1;
        now = mid;
      } else {
        high = mid - 1;
      }
    }
    sum1 += now;
    sum2 -= now;
    c[i] += now;
    d[i] -= now;
  }
  return abs(sum2 - sum1);
}
long long fun2(int a[], int b[], int c[], int d[]) {
  long long sum1 = 0, sum2 = 0;
  for (int i = 0; i < n; i++) {
    if (b[i] >= m) {
      d[i] = b[i] - m;
      c[i] = a[i];
    } else {
      d[i] = 0;
      c[i] = (a[i]) - (m - b[i]);
    }
    sum1 += c[i];
    sum2 += d[i];
  }
  for (int i = 0; i < n; i++) {
    if (sum1 <= sum2) break;
    long long low = 0, high = min(c[i], b[i] - d[i]);
    long long now = 0;
    while (low <= high) {
      long long mid = (low + high) / 2;
      if (sum1 - mid >= sum2 + mid) {
        low = mid + 1;
        now = mid;
      } else {
        high = mid - 1;
      }
    }
    sum1 -= now;
    sum2 += now;
    c[i] -= now;
    d[i] += now;
  }
  return abs(sum2 - sum1);
}
void TEST_CASES() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> a[i] >> b[i];
  }
  long long ans = fun(a, b, c, d);
  cout << ans << "\n";
  for (int i = 0; i < n; i++) {
    cout << a[i] - c[i] << " " << b[i] - d[i] << "\n";
    assert(a[i] - c[i] + b[i] - d[i] == m);
  }
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  cin >> t;
  while (t--) {
    TEST_CASES();
  }
  return 0;
}
