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
  ios_base::sync_with_stdio(0);
  cin.tie(0);
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
    long long int r = (s + 1) % k;
    long long int q = s / k;
    if (q % 2 == 1) {
      if (!r)
        cnt += k - 1;
      else
        cnt += k - r + 1;
    } else {
      if (!r)
        cnt++;
      else
        cnt += r - 1;
    }
    if (cnt < 2 * n + 1)
      cout << "YES" << '\n';
    else
      cout << "NO" << '\n';
  }
}
