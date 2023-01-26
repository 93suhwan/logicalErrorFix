#include <bits/stdc++.h>
using namespace std;
long long power(long long a, long long b) {
  if (b == 0) return 1;
  long long temp = power(a, b / 2);
  if (b % 2 == 0)
    return temp * temp;
  else
    return temp * temp * a;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long n, k, ans = 0, i;
    cin >> n >> k;
    long long x = 1, s = 1;
    while (x <= k && s < n) {
      s += x;
      x = x * 2;
      ++ans;
    }
    if (s >= n)
      cout << ans << endl;
    else {
      if (x > k) {
        x = x / 2 + 1;
        while (x <= k && s < n) {
          s += x;
          ++x;
          ++ans;
        }
        if (s >= n)
          cout << ans << endl;
        else {
          ans += (n - s + k - 1) / k;
          cout << ans << endl;
        }
      } else {
        ans += (n - s + k - 1) / k;
        cout << ans << endl;
      }
    }
  }
  return 0;
}
