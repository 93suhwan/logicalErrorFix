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
    if (n == 1) {
      cout << "0\n";
      continue;
    }
    if (power(2, k) >= n) {
      cout << (int)(log2(n) + 1) << endl;
    } else {
      long long x = 1, y = 1, ans = 0;
      while (x * 2 < k) {
        y += x;
        ++ans;
        x = x * 2;
      }
      while (y < n && x < k) {
        y += x;
        ++ans;
        ++x;
      }
      while (y < n) {
        y += x;
        ++ans;
      }
      cout << ans << endl;
    }
  }
  return 0;
}
