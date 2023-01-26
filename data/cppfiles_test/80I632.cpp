#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
const long long inf = 1000000000000000000;
int dx4[] = {0, 1, 0, -1};
int dy4[] = {1, 0, -1, 0};
int dx8[] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dy8[] = {-1, 0, 1, 1, 1, 0, -1, -1};
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
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int T;
  T = 1;
  cin >> T;
  while (T--) {
    long long int n, m, i, j, a[500002], b[500002];
    long long int cn = 0, flag = 0, num, k, ans = 0, sum = 0, mx = 0, mn = inf;
    string s;
    vector<long long> v;
    vector<pair<long long, long long> > vp;
    map<long long, long long> mapp;
    cin >> n >> s;
    for (i = 0; i < n; i++) {
      if (s[i] == '0') {
        flag = 1;
        break;
      }
    }
    if (flag == 0) {
      if (n % 2)
        cout << 1 << " " << cl(n, 2) << " " << cl(n, 2) << " " << n << "\n";
      else
        cout << 1 << " " << n / 2 << " " << n / 2 + 1 << " " << n << "\n";
      continue;
    }
    long long idx = -1;
    for (i = 0; i <= n / 2; i++) {
      if (s[i] == '0') {
        idx = i;
        break;
      }
    }
    if (idx > -1) {
      idx++;
      cout << idx << " " << n << " " << idx + 1 << " " << n << "\n";
    } else {
      for (i = n / 2 + 1; i < n; i++) {
        if (s[i] == '0') {
          idx = i;
          break;
        }
      }
      cout << 1 << " " << idx + 1 << " " << 1 << " " << idx << "\n";
    }
  }
  return 0;
}
