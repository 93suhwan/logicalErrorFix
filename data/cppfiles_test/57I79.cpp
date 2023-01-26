#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
long long int gcd(long long int a, long long int b) {
  if (!b)
    return a;
  else
    return gcd(b, a % b);
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long int s, n, k;
    cin >> s >> n >> k;
    if (s < k) {
      cout << "NO" << '\n';
      continue;
    }
    if (s == k) {
      cout << "YES" << '\n';
      continue;
    }
    long long int cnt = s;
    long long int r = s % k;
    if ((s / k) & 1)
      cnt += k - r;
    else
      cnt += r;
    if (cnt < 2 * n + 1)
      cout << "YES" << '\n';
    else
      cout << "NO" << '\n';
  }
}
