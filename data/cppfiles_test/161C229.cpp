#include <bits/stdc++.h>
long long int mod = 1000000007;
using namespace std;
long long long long int max(long long long long int a,
                            long long long long int b) {
  if (a > b) return a;
  return b;
}
long long long long int min(long long long long int a,
                            long long long long int b) {
  if (a < b) return a;
  return b;
}
long long long long int power(long long long long int n,
                              long long long long int k) {
  if (k == 0) return 1;
  if (k == 1) return n;
  long long long long int res = power(n, k / 2);
  if (k % 2 == 0) return res * res;
  return res * res * n;
}
long long long long int powermod(long long long long int n,
                                 long long long long int k,
                                 long long long long int mod = 1000000007) {
  if (k == 0) return 1;
  if (k == 1) return n % mod;
  long long long long int res = powermod(n, k / 2, mod);
  if (k % 2 == 0) return (res * res) % mod;
  return ((res * res) % mod * n) % mod;
}
long long long long int gcd(long long long long int a,
                            long long long long int b) {
  while (b != 0) {
    long long int temp = a;
    a = b;
    b = temp % b;
  }
  return a;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    set<tuple<long long int, long long int, long long int>> mep;
    for (long long int i = 0; i < n; i++) {
      long long int l, r;
      cin >> l >> r;
      mep.insert(make_tuple(l - r, l, r));
    }
    while (mep.size()) {
      tuple<long long int, long long int, long long int> p = *mep.begin();
      long long int l = get<1>(p);
      long long int r = get<2>(p);
      long long int ans = -1;
      for (long long int i = l; i <= r; i++) {
        bool f = true;
        if (i - 1 >= l) f = f && mep.count(make_tuple(l - i + 1, l, i - 1));
        if (i + 1 <= r) f = f && mep.count(make_tuple(i + 1 - r, i + 1, r));
        if (f) {
          cout << l << ' ' << r << ' ' << i << '\n';
          mep.erase(make_tuple(l - r, l, r));
          break;
        }
      }
    }
  }
}
