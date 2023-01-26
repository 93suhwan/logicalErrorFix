#include <bits/stdc++.h>
#pragma warning(disable : 4996)
using namespace std;
const long long MOD = 1e9 + 7;
const long long MODD = 1e9 + 1;
const long long MODL = 998244353;
const long long N = 200005;
const long long INF = 1e18;
const long long mx = 1e5 + 1;
long long Power(long long x, long long y) {
  long long r = 1;
  while (y) {
    if (y & 1) r = 1ll * r * x % MOD;
    x = 1ll * x * x % MOD, y >>= 1;
  }
  return r;
}
bool sortbysec(const pair<int, int>& a, const pair<int, int>& b) {
  return (a.second < b.second);
}
bool sortstring(const string& a, const string& b) { return a + b < b + a; }
long long GCD(long long a, long long b) {
  if (b == 0) return a;
  a %= b;
  return GCD(b, a);
}
bool isZero(int i) { return i == 0; }
int ce(int n, int m) {
  int ans = 0;
  if (n % m == 0)
    ans = n / m;
  else
    ans = n / m + 1;
  return ans;
}
int solve(int n) {
  int m, k;
  cin >> m >> k;
  int p = 0;
  int q = 0, qq = 0;
  int r = 0;
  int x = ce(n, m);
  int s = 0;
  if (n % m != 0) {
    for (int i = n - 1; i >= 0; i--) {
      if (i % x == 0 && (n - i) % (n / m) == 0) {
        s = i;
        break;
      }
    }
  }
  s = (n - s) / (n / m);
  for (int i = 0; i < k; i++) {
    for (int j = 0; j < m - s; j++) {
      cout << x << " ";
      r = j * x + p;
      for (int k = 0; k < x; k++) {
        cout << r % n + 1 << " ";
        q = r % n;
        r++;
      }
      cout << "\n";
    }
    qq = q;
    for (int j = 0; j < s; j++) {
      cout << n / m << " ";
      r = q + 1;
      for (int k = 0; k < n / m; k++) {
        cout << r % n + 1 << " ";
        q = r % n;
        r++;
      }
      cout << "\n";
    }
    p = qq + 1;
  }
  cout << "\n";
  cerr << n << " " << m << " " << k;
  return 0;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  int n = 0;
  cin >> t;
  while (t--) {
    cin >> n;
    solve(n);
  }
  return 0;
}
