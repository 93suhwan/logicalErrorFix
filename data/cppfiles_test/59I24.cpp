#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}
long long mod(long long a, long long b) {
  if (a > b)
    return (a - b);
  else
    return (b - a);
}
double distance(long long x1, long long y1, long long x2, long long y2) {
  return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2) * 1.0);
}
bool isPerfectSquare(long double x) {
  long double sr = sqrt(x);
  return ((sr - floor(sr)) == 0);
}
bool palindrome(string s, long long i, long long j) {
  if (i > j) return true;
  if (s[i] != s[j])
    return false;
  else
    return palindrome(s, i + 1, j - 1);
}
bool isPrime(long long n) {
  if (n <= 1) return false;
  if (n <= 3) return true;
  if (n % 2 == 0 || n % 3 == 0) return false;
  for (long long i = 5; i * i <= n; i = i + 6)
    if (n % i == 0 || n % (i + 2) == 0) return false;
  return true;
}
const long long MD = 1e9 + 7;
long long binpow(long long a, long long b, long long m) {
  a %= m;
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = res * a % m;
    a = a * a % m;
    b >>= 1;
  }
  return res;
}
const long long N = 2e5 + 5;
long long fact[N];
void precompute() {
  fact[0] = fact[1] = 1;
  for (long long i = 2; i < N; i++) {
    fact[i] = fact[i - 1] * i;
    fact[i] %= MD;
  }
}
long long nPr(long long n, long long c) {
  long long num = fact[n];
  num %= MD;
  num /= fact[n - c];
  num %= MD;
  return num;
}
struct tri {
  long long a, b, c;
};
void solve(long long tt) {
  long long n;
  cin >> n;
  vector<vector<long long>> vec(n, vector<long long>(5));
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < 5ll; j++) {
      cin >> vec[i][j];
    }
  }
  map<long long, vector<long long>> mp;
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < 5; j++) {
      if (vec[i][j] == 1) mp[j].push_back(i);
    }
  }
  for (long long i = 0; i < 5; i++) {
    if (mp[i].size() >= n / 2) {
      map<long long, long long> mapi;
      for (long long k = 0; k < mp[i].size(); k++) mapi[mp[i][k]]++;
      for (long long j = i + 1; j < 5; j++) {
        long long cnt = 0;
        for (long long k = 0; k < mp[j].size(); k++) {
          if (mapi[mp[j][k]] == 0) cnt++;
        }
        if (cnt >= n / 2) {
          cout << "YES"
               << "\n";
          return;
        }
      }
    }
  }
  cout << "NO"
       << "\n";
}
signed main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
  long long t;
  cin >> t;
  precompute();
  for (long long tt = 1; tt <= t; tt++) {
    solve(tt);
  }
  return 0;
}
