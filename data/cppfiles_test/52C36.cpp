#include <bits/stdc++.h>
using namespace std;
long long m = 1e9 + 7;
long long power(long long a, long long b) {
  if (b == 0) return 1;
  if (b == 1) return a % m;
  if (b % 2 == 0) {
    return (power(a, b / 2) % m * power(a, b / 2) % m) % m;
  }
  long long x = (power(a, b / 2) % m * power(a, b / 2) % m) % m;
  return (a % m * x % m) % m;
}
int main() {
  long long t;
  cin >> t;
  vector<long long> v;
  long long x = 1;
  while (x < m) {
    v.push_back(x);
    x = x * 2;
  }
  while (t--) {
    long long n, k;
    cin >> n >> k;
    vector<long long> res;
    while (k) {
      int r = lower_bound(v.begin(), v.end(), k) - v.begin();
      if (r == v.size())
        r--;
      else if (v[r] != k)
        r--;
      res.push_back(r);
      k -= v[r];
    }
    long long ans = 0;
    for (long long x : res) {
      ans = (ans % m + power(n, x) % m) % m;
    }
    cout << ans << endl;
  }
}
