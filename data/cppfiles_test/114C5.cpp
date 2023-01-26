#include <bits/stdc++.h>
using namespace std;
int power(int x, unsigned int y) {
  int res = 1;
  while (y > 0) {
    if (y & 1) res = res * x;
    y = y >> 1;
    x = x * x;
  }
  return res;
}
long long binExpo(long long a, long long n) {
  long long res = 1;
  while (n > 0) {
    if (n % 2) {
      res *= a, n--;
    } else {
      a *= a;
      n /= 2;
    }
  }
  return res;
}
int modInverse(int a, int m) {
  int m0 = m;
  int y = 0, x = 1;
  if (m == 1) return 0;
  while (a > 1) {
    int q = a / m;
    int t = m;
    m = a % m, a = t;
    t = y;
    y = x - q * y;
    x = t;
  }
  if (x < 0) x += m0;
  return x;
}
long long fac(long long n) {
  long long res = 1;
  for (long long i = 2; i <= n; i++) {
    res *= i;
  }
  return res;
}
long long nCr(long long n, long long r) {
  return fac(n) / (fac(r) * fac(n - r));
}
void solve() {
  int n;
  cin >> n;
  int a[n];
  unordered_map<int, int> mp;
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
    mp[a[i]]++;
  }
  sort(a, a + n);
  int rq = n / 2;
  vector<pair<int, int>> v;
  int i = 0, j = 0;
  while (rq) {
    i = 0;
    while (i < n) {
      while (a[i] == a[i + 1]) i++;
      i++;
      if (!mp[a[i] % a[j]]) {
        v.push_back({a[i], a[j]});
        rq--;
      }
      if (rq == 0) break;
    }
    j++;
  }
  for (auto p : v) cout << p.first << " " << p.second << endl;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
