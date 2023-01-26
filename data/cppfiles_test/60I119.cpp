#include <bits/stdc++.h>
using namespace std;
const int eps = 10e-13;
long long power(long long x, long long y, long long p) {
  long long res = 1;
  x = x % p;
  if (x == 0) return 0;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    long double c;
    cin >> c;
    long double n = c;
    map<long double, long double> m;
    vector<long double> v;
    long double sum = 0;
    while (c--) {
      long double e;
      cin >> e;
      m[e]++;
      sum += e;
      v.push_back(e);
    }
    long double mot = (long double)(sum / (long double)n);
    long double ans = 0;
    for (int i = 0; i < v.size(); i++) {
      long double o = -1 * (mot * (n - 2) - sum + v[i]);
      if (m[o]) {
        if (o != v[i])
          ans += (m[o]);
        else
          ans += (m[o] - 1);
      }
    }
    cout << ans / 2 << "\n";
  }
  return 0;
}
