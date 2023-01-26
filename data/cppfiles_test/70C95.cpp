#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,fma")
using namespace std;
const long long mod1 = 998244353;
const long long mod = 1e9 + 7;
long long mod_mul(long long a, long long b) {
  a = a % mod;
  b = b % mod;
  return (((a * b) % mod) + mod) % mod;
}
long long inv(long long i) {
  if (i == 1) return 1;
  return (mod - ((mod / i) * inv(mod % i)) % mod) % mod;
}
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
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
long long findMinNumber(long long n) {
  long long count = 0, ans = 1;
  while (n % 2 == 0) {
    count++;
    n /= 2;
  }
  if (count % 2) ans *= 2;
  for (int i = 3; i <= sqrt(n); i += 2) {
    count = 0;
    while (n % i == 0) {
      count++;
      n /= i;
    }
    if (count % 2) ans *= i;
  }
  if (n > 2) ans *= n;
  return ans;
}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    string s, a;
    cin >> s;
    a = s;
    long long n = s.length(), i, cnt1 = 0, cnt = 0, idx;
    map<char, long long> m, m1;
    for (i = 0; i < n; i++) {
      m[s[i]]++;
      if (m[s[i]] == 1) cnt++;
    }
    vector<char> ans;
    for (i = n - 1; i >= 0; i--) {
      m1[s[i]]++;
      if (m1[s[i]] == 1) {
        ans.push_back(s[i]);
        cnt1++;
        if (cnt1 == cnt) {
          idx = i;
          break;
        }
      }
    }
    long long sum = 0;
    for (i = 0; i < ans.size(); i++) {
      sum += (cnt - i - 1) * (m[ans[i]]) / (cnt - i);
    }
    long long l = n - sum, j;
    string sans = s.substr(0, l);
    for (i = cnt - 1; i >= 0; i--) {
      for (j = 0; j < l; j++) {
        if (s[j] == '#' or s[j] == ans[i]) {
          s[j] = '#';
        } else {
          sans += s[j];
        }
      }
    }
    if (sans.size() != s.size())
      cout << -1 << '\n';
    else {
      long long res = 0;
      s = a;
      for (i = 0; i < sans.size(); i++)
        if (sans[i] != s[i]) {
          res = 1;
          break;
        }
      if (res)
        cout << -1 << '\n';
      else {
        string s1 = s.substr(0, l);
        cout << s1 << " ";
        for (i = 0; i < cnt1; i++) cout << ans[cnt1 - i - 1];
        cout << '\n';
      }
    }
  }
  return 0;
}
