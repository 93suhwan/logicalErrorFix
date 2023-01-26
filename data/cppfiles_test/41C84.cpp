#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
const long long int maxn = 1e3 + 16, md = 1e9 + 7, inf = 2e16;
long long int gcd(long long int a, long long int b) {
  if (a < b) swap(a, b);
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long int tav(long long int n, long long int k) {
  long long int res = 1;
  while (k > 0) {
    if (k & 1) {
      res *= n;
      res %= md;
    }
    n *= n;
    n %= md;
    k >>= 1;
  }
  return res;
}
long long int n, k, r;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> k;
  long long int h = 1;
  for (long long int i = 1; i < n; i++) {
    h *= k;
    if (n <= h) {
      r = i;
      break;
    }
  }
  cout << r << '\n';
  for (long long int i = 0; i < n; i++) {
    for (long long int j = i + 1; j < n; j++) {
      long long int h = i, o = j;
      for (long long int q = 1; q <= r; q++) {
        if (h % k < o % k) {
          cout << q << ' ';
          break;
        }
        h /= k;
        o /= k;
      }
    }
  }
  return 0;
}
