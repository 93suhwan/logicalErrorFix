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
bitset<8> toBinary(long long int n) { return bitset<8>(n); }
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t = 1;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    vector<pair<long long int, long long int>> v;
    long long int l = -1, r = 0;
    for (long long int i = 0; i < n; i++) {
      long long int x;
      cin >> x;
      long long int mx = 0;
      for (long long int j = 1; j <= x; j++) {
        long long int k;
        cin >> k;
        k = (k + 1) - (j - 1);
        mx = max(mx, k);
      }
      r = max(r, mx);
      v.push_back({mx, x});
    }
    sort(v.begin(), v.end());
    r++;
    while (r - l > 1) {
      long long int m = (l + r) / 2;
      long long int tm = m;
      long long int f = 0;
      for (long long int i = 0; i < v.size(); i++) {
        long long int ar = v[i].first;
        if (i > 0) tm += v[i - 1].second;
        if (tm <= ar) {
          f = 1;
          break;
        }
      }
      if (f == 0) {
        r = m;
      } else {
        l = m;
      }
    }
    cout << l << endl;
  }
}
