#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const long long inf = 1e17;
long long mod_add(long long a, long long b) {
  a = a % mod;
  b = b % mod;
  return (((a + b) % mod) + mod) % mod;
}
long long mod_mul(long long a, long long b) {
  a = a % mod;
  b = b % mod;
  return (((a * b) % mod) + mod) % mod;
}
long long inv(long long i) {
  if (i == 1) return 1;
  return (mod - ((mod / i) * inv(mod % i)) % mod) % mod;
}
long long pwr(long long a, long long b) {
  a %= mod;
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return res;
}
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
string yans = "YES", nans = "NO";
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t = 1;
  cin >> t;
  while (t--) {
    long long n, k, x;
    cin >> n >> k >> x;
    string s;
    cin >> s;
    vector<long long> v;
    string ans = "";
    long long cnt = 0;
    for (long long i = 0; i < n; i++) {
      if (s[i] == '*') {
        if (cnt == 0) {
          ans += '?';
        }
        cnt++;
      } else {
        ans += 'a';
        if (cnt) {
          v.push_back(cnt * k + 1);
          cnt = 0;
        }
      }
    }
    if (cnt) {
      v.push_back(cnt * k + 1);
    }
    long long m = v.size(), b = ans.size();
    long long j = m - 1;
    for (long long i = b - 1; i >= 0; i--) {
      if (ans[i] == '?' and x) {
        long long p = x % v[j], q = v[j];
        if (p) {
          v[j] = p;
        }
        x = (x + q - 1) / q;
        j--;
      }
    }
    j = 0;
    string res = "";
    for (long long i = 0; i < b; i++) {
      if (ans[i] == '?') {
        for (long long l = 0; l < v[j] - 1; l++) {
          res += 'b';
        }
        j++;
      } else {
        res += 'a';
      }
    }
    cout << res << "\n";
  }
  return 0;
}
