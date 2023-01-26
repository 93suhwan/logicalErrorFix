#include <bits/stdc++.h>
const long long int M = 1e9 + 7;
using namespace std;
long long int gcd(long long int x, long long int y) {
  return (y == 0) ? x : gcd(y, x % y);
}
long long int lcm(long long int a, long long int b) {
  return a / gcd(a, b) * b;
}
bool checkPrime(long long int n) {
  for (long long int i = 2; i * i <= n; i++)
    if (n % i == 0) return false;
  return true;
}
bool is_sqr(long long int x) {
  long long int y = (long long int)(sqrt(x) + 0.5);
  return y * y == x;
}
long long int fastPower(long long int a, long long int b) {
  long long int res = 1;
  while (b > 0) {
    if (b % 2 != 0) res = (res * a % M) % M;
    a = (a % M * a % M) % M;
    b = b >> 1;
  }
  return res;
}
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  long long int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    vector<long long int> v;
    for (long long int i = 0; i < n; i++) {
      long long int x;
      cin >> x;
      v.push_back(x);
    }
    while (v.size()) {
      bool deleted = false;
      long long int ind = v.size();
      auto it = v.end() - 1;
      for (; it != v.begin(); --it, --ind) {
        if (*it % (ind + 1)) {
          deleted = true;
          v.erase(it);
          break;
        }
      }
      if (!deleted && *it % (ind + 1)) {
        deleted = true;
        v.erase(it);
      }
      if (!deleted) {
        break;
      }
    }
    if (v.size())
      cout << "NO" << endl;
    else
      cout << "YES" << endl;
  }
  return 0;
}
