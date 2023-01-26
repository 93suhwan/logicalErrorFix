#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1);
long long q_pow(long long a, long long b) {
  long long res = 1;
  while (b) {
    if (b & 1) res = res * a;
    a = a * a;
    b >>= 1;
  }
  return res;
}
const int N = 2e5 + 456;
long long a[100], dp[12], b[100];
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
      int x;
      cin >> x;
      if (!x) {
        a[i] = 1;
      } else {
        long long sum = 1;
        for (int j = 1; j <= x; j++) {
          sum *= 10;
        }
        a[i] = sum;
      }
    }
    a[n + 1] = 2 * a[n];
    long long ans = 0, sum = 0;
    for (int i = 1; i <= n; i++) {
      b[i] = (a[i + 1] / a[i] - 1);
    }
    int ok = 0;
    for (int i = 1; i <= n - 1; i++) {
      if (k - ans < b[i]) {
        ok = 1;
        sum += (k - ans + 1) * a[i];
        break;
      } else {
        ans += b[i];
        sum += b[i] * a[i];
      }
    }
    if (ok)
      cout << sum << '\n';
    else {
      sum += (k - ans + 1) * a[n];
      cout << sum << '\n';
    }
  }
  return 0;
}
