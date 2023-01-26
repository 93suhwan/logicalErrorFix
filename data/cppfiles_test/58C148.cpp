#include <bits/stdc++.h>
using namespace std;
long long secondmax(long long a, long long b, long long c) {
  long long ar[3];
  ar[0] = a, ar[1] = b, ar[2] = c;
  sort(ar, ar + 3);
  return ar[1];
}
bool comp(pair<long long, long long> a, pair<long long, long long> b) {
  if (a.first != b.first)
    return a.first > b.first;
  else
    return a.second > b.second;
}
inline void normal(long long &a) {
  a %= 1000000007;
  (a < 0) && (a += 1000000007);
}
inline long long modMul(long long a, long long b) {
  a %= 1000000007, b %= 1000000007;
  normal(a), normal(b);
  return (a * b) % 1000000007;
}
inline long long modAdd(long long a, long long b) {
  a %= 1000000007, b %= 1000000007;
  normal(a), normal(b);
  return (a + b) % 1000000007;
}
inline long long modSub(long long a, long long b) {
  a %= 1000000007, b %= 1000000007;
  normal(a), normal(b);
  a -= b;
  normal(a);
  return a;
}
inline long long modPow(long long b, long long p) {
  long long r = 1;
  while (p) {
    if (p & 1) r = modMul(r, b);
    b = modMul(b, b);
    p >>= 1;
  }
  return r;
}
inline long long modInverse(long long a) { return modPow(a, 1000000007 - 2); }
inline long long modDiv(long long a, long long b) {
  return modMul(a, modInverse(b));
}
long long pow1(long long base, long long x) {
  long long ans = 1;
  for (long long i = 1; i <= x; i++) ans *= base;
  return ans;
}
void debug(string s) { cout << s << "\n"; }
void debug(long long s) { cout << s << "\n"; }
int main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    string s1, s2;
    cin >> s1 >> s2;
    if (s1[n - 1] != '0' && s2[n - 1] != '0') {
      cout << "NO\n";
      continue;
    }
    long long c = 0;
    for (long long i = 0; i < n; i++) {
      if (s1[i] == '0' || s2[i] == '0') c++;
    }
    if (c == n)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  return 0;
}
