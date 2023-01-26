#include <bits/stdc++.h>
using namespace std;
bool isPrime(long long n) {
  if (n < 2) return false;
  for (long long i = 2; i * i <= n; i++) {
    if (n % i == 0) return false;
  }
  return true;
}
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long lcm(long long a, long long b) { return a / gcd(a, b) * b; }
long long mod(long long a, long long b) {
  long long r = a % b;
  return r >= 0 ? r : r + abs(b);
}
string getbin(long long x) {
  string r(64, '0');
  for (int i = 0; i < 64; i++) {
    if ((1ll << i) & x) r[63 - i] = '1';
  }
  return r;
}
void solve() {
  string s1, s2;
  long long x, y;
  cin >> x >> y;
  s1 = getbin(x);
  s2 = getbin(y);
  if (s1 == s2) {
    cout << "YES" << '\n';
    return;
  }
  while (s1[0] == '0') s1 = s1.substr(1, s1.size());
  while (s2[0] == '0') s2 = s2.substr(1, s2.size());
  if (s2.find(s1 + "1") != string::npos) {
    for (int i = 0; i < s2.size() - s1.size(); i += 1) {
      if (s2.substr(i, s1.size() + 1) == s1 + "1") {
        bool ok = 1;
        for (int j = 0; j < i; j += 1) {
          if (s2[j] == '0') ok = 0;
        }
        for (int j = i + s1.size() + 1; j < s2.size(); j += 1) {
          if (s2[j] == '0') ok = 0;
        }
        if (ok) {
          cout << "YES" << '\n';
          return;
        }
      }
    }
  }
  while (s1[s1.size() - 1] == '0') s1 = s1.substr(0, s1.size() - 1);
  reverse(s1.begin(), s1.end());
  if (s2.find(s1) != string::npos) {
    for (int i = 0; i < s2.size() - s1.size() + 1; i += 1) {
      if (s2.substr(i, s1.size()) == s1) {
        bool ok = 1;
        for (int j = 0; j < i; j += 1) {
          if (s2[j] == '0') ok = 0;
        }
        for (int j = i + s1.size(); j < s2.size(); j += 1) {
          if (s2[j] == '0') ok = 0;
        }
        if (ok) {
          cout << "YES" << '\n';
          return;
        }
      }
    }
  }
  cout << "NO" << '\n';
}
int main() {
  solve();
  return 0;
}
