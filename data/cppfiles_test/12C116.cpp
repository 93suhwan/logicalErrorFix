#include <bits/stdc++.h>
using namespace std;
template <typename T, typename K>
inline bool smax(T &x, const K &y) {
  return x < y ? x = y, true : false;
}
template <typename T, typename K>
inline bool smin(T &x, const K &y) {
  return x > y ? x = y, true : false;
}
const int mod = 1e9 + 7;
int add(int x, int y) {
  int z = x + y;
  if (z >= mod) {
    z -= mod;
  }
  return z;
}
int sub(int x, int y) {
  int z = x - y;
  if (z < 0) {
    z += mod;
  }
  return z;
}
int mul(int x, int y) {
  long long z = 1ll * x * y;
  if (z >= mod) {
    z %= mod;
  }
  return z;
}
int binpow(int a, long long p) {
  int r = 1;
  while (p) {
    if (p & 1) r = mul(r, a);
    a = mul(a, a), p >>= 1;
  }
  return r;
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, m, k;
    cin >> n >> m >> k;
    if (n & 1) {
      if (k < m / 2 || m == 1) {
        cout << "NO" << endl;
        continue;
      }
      k -= m / 2;
      n -= 1;
    }
    if (m & 1) {
      m -= 1;
    }
    if (k >= 0 && k % 2 == 0 && m * n >= k * 2) {
      cout << "YES" << endl;
      continue;
    }
    cout << "NO" << endl;
    continue;
  }
}
