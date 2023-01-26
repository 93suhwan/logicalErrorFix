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
vector<string> v;
map<char, long long int> mp;
bool compare(pair<long long int, pair<long long int, long long int>> p1,
             pair<long long int, pair<long long int, long long int>> p2) {
  if (p1.first == p2.first and p1.second.second > p2.second.second)
    return false;
  else if (p1.first < p2.first)
    return false;
  else
    return true;
}
set<string> vs;
void permute(string str, string out) {
  if (str.size() == 0) {
    vs.insert(out);
    return;
  }
  for (int i = 0; i < str.size(); i++) {
    permute(str.substr(1), out + str[0]);
    rotate(str.begin(), str.begin() + 1, str.end());
  }
}
bool isPrime(long long int n) {
  for (long long int i = 2; i * i <= n; i++) {
    if (n % i == 0) return false;
  }
  return true;
}
long long int ncr(long long int nn, long long int rr) {
  if (rr > nn) return 0;
  if (rr == 0) return 1;
  if (rr == 1) return nn;
  if (nn == rr) return 1;
  return ncr(nn - 1, rr - 1) + ncr(nn - 1, rr);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    n = n * 2;
    long long int fact = 1;
    for (long long int i = 2; i <= n; i++) {
      fact = (fact * i) % mod;
    }
    if (n <= 12 or n % 8 == 0)
      cout << (fact / 2) % mod << endl;
    else
      cout << (((fact / 2) % mod) + 500000004) % mod << endl;
  }
  return 0;
}
