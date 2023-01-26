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
    long long n, k;
    cin >> n >> k;
    long long x = 1, s = 1, ans = 0;
    while (s < n && min(k, x) != k) {
      s += x;
      x = x * 2;
      ++ans;
    }
    if (s < n) {
      ans += (n - s + k - 1) / k;
    }
    cout << ans << endl;
  }
  return 0;
}
