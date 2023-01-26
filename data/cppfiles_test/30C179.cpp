#include <bits/stdc++.h>
using namespace std;
long long power(long long x, long long y) {
  long long res = 1;
  while (y > 0) {
    if (y & 1) res = res * x;
    y = y >> 1;
    x = x * x;
  }
  return res;
}
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long pow(long long a, long long b, long long MOD) {
  long long x = 1, y = a;
  while (b > 0) {
    if (b % 2 == 1) {
      x = (x % MOD * y % MOD);
      if (x > MOD) x %= MOD;
    }
    y = (y % MOD * y % MOD);
    if (y > MOD) y %= MOD;
    b /= 2;
  }
  return x;
}
void union1(long long parent[], int x, int y) { parent[y] = x; }
int find1(long long parent[], int x) {
  if (parent[x] == -1) {
    return x;
  }
  return find1(parent, parent[x]);
}
int main(void) {
  long long t, n, x, y, k, m, r, p, d, u, v, q, a, b, z, w, l;
  long long MOD = 1000000007;
  t = 1;
  cin >> t;
  while (t--) {
    string s;
    cin >> n >> s;
    long long ans = INT_MAX;
    for (int i = 0; i < 26; i++) {
      long long l = 0, r = n - 1, count = 0;
      char c = 'a' + i;
      while (l <= r) {
        if (s[l] == s[r]) {
          l++;
          r--;
        } else if (s[l] == c) {
          l++;
          count++;
        } else if (s[r] == c) {
          count++;
          r--;
        } else {
          count = INT_MAX;
          break;
        }
      }
      ans = min(ans, count);
    }
    if (ans == INT_MAX) ans = -1;
    cout << ans << endl;
  }
}
