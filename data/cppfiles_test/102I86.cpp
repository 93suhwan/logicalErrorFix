#include <bits/stdc++.h>
using namespace std;
const int inf = 1000000000;
const int64_t N = 2e5 + 5;
const int64_t p = 998244353;
int64_t bvs(int64_t a, int64_t n) {
  if (n == 0) return 1;
  if (n % 2 == 1) return (bvs(a, n - 1) * a) % p;
  if (n % 2 == 0) return bvs((a * a) % p, n / 2);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
  int k, A, h;
  cin >> k >> A >> h;
  if (k <= 4) {
    int Z = (1 << k);
    for (int i = 0; i < (1 << (Z - 1)); ++i) {
      int64_t R = 0;
      int z = (1 << k);
      std::vector<int> a(z), b, r(z);
      for (int i = 0; i < z; ++i) a[i] = i + 1;
      int f = 0;
      while (true) {
        for (int j = 0; j < z / 2; ++j) {
          if ((i >> (j + f)) & 1) {
            R = (R + a[2 * j] * bvs(A, 1 + (z / 2))) % p;
            b.push_back(a[2 * j + 1]);
            r[a[2 * j] - 1] = 1 + (z / 2);
          } else {
            R = (R + a[2 * j + 1] * bvs(A, 1 + (z / 2))) % p;
            b.push_back(a[2 * j]);
            r[a[2 * j + 1] - 1] = 1 + (z / 2);
          }
        }
        a = b;
        b.clear();
        f += z / 2;
        z /= 2;
        if (int(a.size()) == 1) {
          R = (R + a[0] * bvs(A, 1)) % p;
          r[a[0] - 1] = 1;
          break;
        }
      }
      if (R == h) {
        for (int j = 0; j < Z; ++j) cout << r[j] << ' ';
        return 0;
      }
    }
    cout << -1;
    return 0;
  } else {
    int N = 1e6;
    int Z = (1 << k);
    while (N--) {
      int i = rng() % (1ll << 31);
      int64_t R = 0;
      int z = (1 << k);
      std::vector<int> a(z), b, r(z);
      for (int i = 0; i < z; ++i) a[i] = i + 1;
      int f = 0;
      while (true) {
        for (int j = 0; j < z / 2; ++j) {
          if ((i >> (j + f)) & 1) {
            R = (R + a[2 * j] * bvs(A, 1 + (z / 2))) % p;
            b.push_back(a[2 * j + 1]);
            r[a[2 * j] - 1] = 1 + (z / 2);
          } else {
            R = (R + a[2 * j + 1] * bvs(A, 1 + (z / 2))) % p;
            b.push_back(a[2 * j]);
            r[a[2 * j + 1] - 1] = 1 + (z / 2);
          }
        }
        a = b;
        b.clear();
        f += z / 2;
        z /= 2;
        if (int(a.size()) == 1) {
          R = (R + a[0] * bvs(A, 1)) % p;
          r[a[0] - 1] = 1;
          break;
        }
      }
      if (R == h) {
        for (int j = 0; j < Z; ++j) cout << r[j] << ' ';
        return 0;
      }
    }
    cout << -1;
  }
}
