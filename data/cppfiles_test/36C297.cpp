#include <bits/stdc++.h>
using namespace std;
long long bin_pow(long long x, long long y, long long m) {
  long long ans;
  if (y <= 0) return 1;
  ans = bin_pow(x, y / 2, m);
  if (y % 2 == 0) return (((ans % m) * (ans % m)) % m);
  return (x % m * ((ans % m * ans % m))) % m;
}
long long mult(long long a, long long b, long long m) {
  long long ans = ((a % m) * (b % m)) % m;
  return ans;
}
long long sum(long long a, long long b, long long m) {
  long long ans = (a % m + b % m) % m;
  return ans;
}
long long diff(long long a, long long b, long long m) {
  long long ans = ((a % m) - (b % m) + m) % m;
  return ans;
}
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
void swap(long long &a, long long &b) {
  long long tm = a;
  a = b;
  b = tm;
}
long long compute_lps_array(string s) {
  string s1 = s;
  reverse(s1.begin(), s1.end());
  s = s + "$" + s1;
  long long sz = s.size();
  vector<long long> lps(sz + 1, 0);
  lps[0] = 0;
  for (long long i = 1; i < sz; i++) {
    long long j = lps[i - 1];
    while (j != 0 && (s[i] != s[j])) j = lps[j - 1];
    if (s[i] == s[j]) j++;
    lps[i] = j;
  }
  return lps[sz - 1];
}
long long nCr(long long n, long long r, long long m) {
  long long tm1 = bin_pow(r, 10000000000 - 2, 10000000000);
  long long tm2 = bin_pow(m, 10000000000 - 2, 10000000000);
  long long tm3 = n % 10000000000;
  long long ans = mult(tm3, mult(tm1, tm2, 10000000000), 10000000000);
  return ans;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    if (n == 1LL) {
      cout << 'a' << endl;
      continue;
    }
    if (n == 2LL) {
      cout << "ab" << endl;
      continue;
    }
    if (n == 3LL) {
      cout << "abc" << endl;
      continue;
    }
    if (n % 2) {
      string s1 = "";
      for (long long i = 0; i < n; i++) {
        if (i <= (n / 2 - 2LL)) {
          s1 += 'a';
        } else if (i == (n / 2 - 1LL)) {
          s1 += 'b';
        } else if (i == (n / 2)) {
          s1 += 'c';
        } else {
          s1 += 'a';
        }
      }
      cout << s1 << endl;
      continue;
    }
    string s1 = "";
    for (long long i = 0; i < n; i++) {
      if (i <= (n / 2 - 2LL)) {
        s1 += 'a';
      } else if (i == (n / 2 - 1LL)) {
        s1 += 'b';
      } else {
        s1 += 'a';
      }
    }
    cout << s1 << endl;
  }
}
