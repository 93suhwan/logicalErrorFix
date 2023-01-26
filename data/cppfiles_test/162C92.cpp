#include <bits/stdc++.h>
using namespace std;
const double PI = 3.141592653589793238460;
long long int gcd(long long int a, long long int b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}
long long int max(long long int a, long long int b) {
  if (a > b)
    return a;
  else
    return b;
}
long long int min(long long int a, long long int b) {
  if (a < b)
    return a;
  else
    return b;
}
long long int power(long long int a, long long int n) {
  long long int res = 1;
  while (n) {
    if (n % 2 == 0) {
      a *= a;
      n /= 2;
    } else {
      res *= a;
      n--;
    }
  }
  return res;
}
bool solver(vector<long long int> h, long long int x) {
  long long int i, j, k, p;
  vector<long long int> tt;
  tt = h;
  for (i = h.size() - 1; i >= 2; i--) {
    if (h[i] >= x) {
      p = (min(tt[i], h[i] - x)) / 3;
      h[i] -= (p * 3);
      h[i - 1] += p;
      h[i - 2] += (2 * p);
    } else {
      return false;
    }
  }
  for (i = 0; i < h.size(); i++) {
    if (h[i] < x) return false;
  }
  return true;
}
int main() {
  ios::sync_with_stdio(false);
  long long int t;
  cin >> t;
  while (t--) {
    long long int i, j, x = 0, y, n, sum = 0;
    cin >> n;
    vector<long long int> h(n);
    for (i = 0; i < n; i++) {
      cin >> h[i];
      sum += h[i];
    }
    long long int l, m, r;
    l = 0;
    r = (sum / n);
    while (l <= r) {
      m = l + (r - l) / 2;
      if (solver(h, m)) {
        l = m + 1;
        y = m;
      } else {
        r = m - 1;
      }
    }
    cout << y << '\n';
  }
  return 0;
}
