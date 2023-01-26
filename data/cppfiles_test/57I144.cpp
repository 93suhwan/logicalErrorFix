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
    long long int cnt = s + 1;
    long long int r = (s + 1) % k;
    if (((s + 1 + (k - 1)) / k) & 1)
      cnt += k - r;
    else
      cnt += r;
    if (cnt < 2 * n + 2)
      cout << "YES" << '\n';
    else
      cout << "NO" << '\n';
  }
}
