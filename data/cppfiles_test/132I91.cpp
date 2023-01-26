#include <bits/stdc++.h>
using namespace std;
const long long int mod = 1e9 + 7;
long long int Pow(long long int c, long long int d) {
  return d == 0 ? 1 : c * pow(c, d - 1);
}
long long int gcd(long long int a, long long int b) {
  return b == 0 ? a : gcd(b, a % b);
}
long long int lcm(long long int a, long long int b) {
  return ((a * b) / gcd(a, b));
}
long long int egcd(long long int a, long long int b, long long int &x,
                   long long int &y) {
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  }
  long long int x1, y1;
  long long int gcd = egcd(b, a % b, x1, y1);
  x = y1;
  y = x1 - y1 * (a / b);
  return gcd;
}
long long int bigMod(long long int a, long long int b) {
  a %= mod;
  long long int res = 1;
  while (b > 0) {
    if (b & 1) res = (res * a) % mod;
    a = (a * a) % mod;
    b >>= 1;
  }
  return res;
}
inline long long int MOD(long long int a) { return (a % mod + mod) % mod; }
inline long long int modAdd(long long int a, long long int b) {
  return MOD(MOD(a) + MOD(b));
}
inline long long int modSub(long long int a, long long int b) {
  return MOD(MOD(a) - MOD(b));
}
inline long long int modMul(long long int a, long long int b) {
  return MOD(MOD(a) * MOD(b));
}
inline long long int modInv(long long int a) { return bigMod(a, mod - 2); }
inline long long int modDiv(long long int a, long long int b) {
  a = MOD(a);
  b = modInv(b);
  return (a * b) % mod;
}
bool isPrime(long long int n) {
  for (long long int i = 2; i * i <= n; i++) {
    if (n % i == 0) return false;
  }
  return true;
}
bool compare(pair<long long int, pair<long long int, long long int>> p1,
             pair<long long int, pair<long long int, long long int>> p2) {
  if (p1.first == p2.first)
    return p1.second.first < p2.second.first;
  else
    return p1.first < p2.first;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t;
  cin >> t;
  while (t--) {
    vector<long long int> v(7);
    vector<long long int> v2;
    for (long long int i = 0; i < 7; i++) cin >> v[i];
    long long int a, b, c, cnt = 0, maxi;
    maxi = *max_element(v.begin(), v.end());
    for (long long int i = 0; i < v.size(); i++) {
      for (long long int j = 0; j < v.size(); j++) {
        if (v[i] + v[j] + v[j + 1] == maxi) {
          cnt++;
          a = v[i];
          b = v[j];
          c = v[j + 1];
          break;
        }
      }
      if (cnt > 0) break;
    }
    cout << a << " " << b << " " << c << "\n";
  }
  return 0;
}
