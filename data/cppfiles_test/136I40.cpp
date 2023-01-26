#include <bits/stdc++.h>
using namespace std;
long long int power(long long int x, long long int y);
long long int gcd(long long int a, long long int b);
vector<long long int> ft = {1};
long long int modInv(long long int i) { return power(i, 1000000007 - 2); }
long long int ncr(long long int n, long long int r) {
  return (n >= r ? (ft[n] * modInv(ft[r])) % 1000000007 * modInv(ft[n - r]) %
                       1000000007
                 : 0);
}
long long int power(long long int x, long long int y) {
  long long int res = 1;
  x %= 1000000007;
  while (y > 0) {
    if (y & 1) res = (res * x) % 1000000007;
    y = y >> 1;
    x = (x * x) % 1000000007;
  }
  return res % 1000000007;
}
long long int gcd(long long int a, long long int b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    vector<long long int> a(n);
    long long int s = 0;
    for (long long int i = 0; i < n; i++) {
      cin >> a[i];
      s += a[i];
    }
    long long int val = (n * (n + 1)) / 2;
    if (s % val != 0) {
      cout << "NO\n";
      continue;
    }
    val = s / val;
    long long int f = 0;
    vector<long long int> ans;
    for (long long int i = 0; i < n; i++) {
      if ((abs(a[i] - a[(i - 1 + n) % n] - val)) % n or
          abs(a[i] - a[(i - 1 + n) % n] - val) == 0) {
        f = 1;
        break;
      } else {
        ans.push_back((abs(a[i] - a[(i - 1 + n) % n] - val)) / n);
      }
    }
    if (f)
      cout << "NO\n";
    else {
      cout << "YES\n";
      for (auto i : ans) cout << i << " ";
      cout << "\n";
    }
  }
}
