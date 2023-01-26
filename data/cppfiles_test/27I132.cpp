#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
const long long inf = 1000000000000000000;
long long mpow(long long a, long long b) {
  a %= mod;
  if (!b) return 1;
  long long temp = mpow(a, b / 2);
  temp = (temp * temp) % mod;
  if (b % 2) return (a * temp) % mod;
  return temp;
}
long long pow_(long long a, long long b) {
  if (!b) return 1;
  long long temp = pow_(a, b / 2);
  temp = (temp * temp);
  if (b % 2) return (a * temp);
  return temp;
}
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
bool isPrime(long long n) {
  if (n <= 1) return false;
  if (n <= 3) return true;
  if (n % 2 == 0 || n % 3 == 0) return false;
  for (long long i = 5; i * i <= n; i = i + 6)
    if (n % i == 0 || n % (i + 2) == 0) return false;
  return true;
}
bool isPalin(string s) {
  int i = 0, j = s.size() - 1;
  while (i < j) {
    if (s[i++] != s[j--]) {
      return false;
    }
  }
  return true;
}
string getsubstr(string s, long long si, long long li) {
  string tmp = "";
  for (long long i = si; i <= li; i++) {
    tmp += s[i];
  }
  return tmp;
}
long long cl(long long a, long long b) {
  if (a % b) return 1 + a / b;
  return a / b;
}
bool isPowerOfTwo(long long n) {
  if (n == 0) return false;
  return (ceil(log2(n)) == floor(log2(n)));
}
long long f[200001];
long long mod_inv(long long n) { return mpow(n, mod - 2); }
long long nCr(long long n, long long r) {
  return (f[n] * ((mod_inv(f[r]) * mod_inv(f[n - r])) % mod)) % mod;
}
bool isSubSequence(string str1, string str2, int m, int n) {
  int j = 0;
  for (int i = 0; i < n && j < m; i++)
    if (str1[j] == str2[i]) j++;
  return (j == m);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int t;
  t = 1;
  cin >> t;
  while (t--) {
    long long int n, m, i, j, a[500002], b[500002];
    long long int cn = 0, flag = 0, num, k, ans = 0, sum = 0, mx = 0, mn = inf;
    string s, tt;
    vector<long long> v;
    vector<pair<long long, long long> > vp;
    map<long long int, long long int> mapp;
    cin >> s >> tt;
    n = s.length();
    m = tt.length();
    if (m > n) {
      cout << "NO\n";
      continue;
    }
    j = 0;
    for (i = 0; i < n; i++) {
      if (s[i] == tt[j]) {
        j++;
      } else {
        if (j > 0) {
          if (tt[j - 1] == s[i]) continue;
        }
        j--;
        if (j < 0) j = 0;
      }
    }
    if (j == m)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  return 0;
}
