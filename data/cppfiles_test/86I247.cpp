#include <bits/stdc++.h>
using namespace std;
void KruNULL() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
bool sortbysec(const pair<long long, long long> &a,
               const pair<long long, long long> &b) {
  return (a.second < b.second);
}
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long lcm(long long a, long long b) { return (a * b) / gcd(a, b); }
long long prime(long long n) {
  long long flag = 1;
  for (long long i = 2; i <= sqrt(n); i++) {
    if (n % i == 0) {
      flag = 0;
      break;
    }
  }
  return flag;
}
long long power(long long x, long long y, long long p) {
  long long res = 1;
  x = x % p;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
void solve() {
  long long n;
  cin >> n;
  string s, t;
  cin >> s >> t;
  long long dono = 0;
  map<char, long long> m;
  long long zz = 0;
  long long ans = 0;
  for (long long i = 0; i < n; i++) {
    m[s[i]]++;
    m[t[i]]++;
    if (s[i] == '0' && t[i] == '0') zz++;
    if ((long long)m.size() == 2) {
      ans += max(zz, 2ll);
      zz = 0;
      m.clear();
    }
  }
  ans += zz;
  cout << ans << endl;
}
int32_t main() {
  KruNULL();
  long long tc = 1;
  cin >> tc;
  for (long long i = 1; i <= tc; i++) {
    solve();
  }
}
