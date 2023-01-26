#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const int Max = 2e5 + 5;
const long long INF = 1e18 + 5;
inline void norm(long long &a) {
  a %= mod;
  (a < 0) && (a += mod);
}
inline long long modAdd(long long a, long long b) {
  a %= mod, b %= mod;
  norm(a), norm(b);
  return (a + b) % mod;
}
inline long long modSub(long long a, long long b) {
  a %= mod, b %= mod;
  norm(a), norm(b);
  return (a - b) % mod;
}
inline long long modMul(long long a, long long b) {
  a %= mod, b %= mod;
  norm(a), norm(b);
  return (a * b) % mod;
}
long long bigmod(long long a, long long p, long long M) {
  p %= (M - 1);
  long long result = 1LL;
  while (p > 0LL) {
    if (p & 1LL) result = result * a % M;
    a = a * a % M;
    p >>= 1LL;
  }
  return result;
}
long long gcd(long long a, long long b) {
  while (b) {
    a %= b;
    swap(a, b);
  }
  return a;
}
long long lcm(long long a, long long b) { return (a / gcd(a, b) * b); }
long long inverse(long long a, long long M) {
  if (gcd(a, M) == 1) return bigmod(a, M - 2, M) % M;
  return 1;
}
long long ncr(long long a, long long b) {
  long long x = max(a - b, b), ans = 1;
  for (long long K = a, L = 1; K >= x + 1; K--, L++) {
    ans = ans * K % mod;
    ans = ans * inverse(L, mod) % mod;
  }
  return ans;
}
void F_I_O() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}
int main() {
  F_I_O();
  int t = 1;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    vector<int> v(26, 0);
    long long r = 0, g = 0;
    for (int i = 0; i < s.size(); i++) {
      int e = s[i] - 'a';
      v[e]++;
    }
    for (int i = 0; i < 26; i++) {
      if (v[i] > 1) {
        r++;
        g++;
      } else if (v[i] == 1) {
        if (r > g) {
          g++;
        } else if (r < g) {
          r++;
        } else {
          g++;
        }
      }
    }
    cout << min(r, g) << '\n';
  }
}
