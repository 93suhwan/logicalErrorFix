#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
  if (a % b == 0) {
    return b;
  } else {
    return gcd(b, a % b);
  }
}
long long powc(long long a, long long b) {
  if (b < 0) {
    return 0;
  }
  long long md = b;
  long long res = 1;
  while (b > 0) {
    if (b & 1) {
      res *= a;
    }
    a *= a;
    b >>= 1;
  }
  return res;
}
bool isPowerOfTwo(long long n) {
  if (n == 0) return false;
  return (ceil(log2(n)) == floor(log2(n)));
}
bool valid(long long i, long long j, long long n, long long m) {
  if (i >= 0 && i < n && j >= 0 && j < m) return true;
  return false;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    long long x = 0, y = 0;
    for (long long i = 1; i < s.size(); i++) {
      if (s[i] == 'b' && s[i - 1] == 'a') {
        x++;
      }
      if (s[i] == 'a' && s[i - 1] == 'b') {
        y++;
      }
    }
    if (x == y) {
      cout << s << "\n";
    } else {
      if (s[0] == 'a') {
        s[s.size() - 1] = 'a';
      } else {
        s[s.size() - 1] = 'b';
      }
      cout << s << "\n";
    }
  }
}
