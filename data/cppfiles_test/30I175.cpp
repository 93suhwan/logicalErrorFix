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
  cin >> t;
  while (t--) {
    long long n, m, p, b;
    char ch;
    string s;
    cin >> n >> ch >> s;
    long long flag = 1, ans = 0;
    vector<long long> v;
    for (int i = 0; i < n; i++) {
      if (s[i] != ch) {
        flag = 0;
        break;
      }
    }
    if (flag) {
      cout << 0 << endl;
    } else {
      for (int i = 1; i <= n; i++) {
        flag = 1;
        for (int j = i; j <= n; j += i) {
          if (s[j - 1] != ch) flag = 0;
        }
        if (flag) {
          cout << 1 << endl;
          cout << i << endl;
          ans = 1;
          break;
        }
      }
      if (!ans) {
        cout << 2 << endl;
        cout << n - 1 << " " << n << endl;
      }
    }
  }
}
