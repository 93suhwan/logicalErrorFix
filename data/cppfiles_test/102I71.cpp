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
  int64_t k, A, h;
  cin >> k >> A >> h;
  if (k <= 4) {
    int Z = (1 << k);
    int i, j;
    for (i = 0; i < (1 << (Z - 1)); ++i) {
      int64_t R = 0;
      int z = (1 << k);
      std::vector<int> a(z), b, r(z);
      for (j = 0; j < z; ++j) a[j] = j + 1;
      int f = 0;
      while (true) {
        for (j = 0; j < z / 2; ++j) {
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
        for (j = 0; j < Z; ++j) cout << r[j] << ' ';
        return 0;
      }
    }
    cout << -1;
    return 0;
  } else {
    int N = 6e6;
    int Z = 32;
    std::vector<int64_t> AA(32);
    AA[0] = 1;
    for (int i = 1; i != 32; (1 < 32) ? ++i : --i) AA[i] = (AA[i - 1] * A) % p;
    int64_t R;
    int z, f, i, j, zz;
    std::vector<int> a, b, r;
    while (N--) {
      i = rng() % (1ll << 31);
      R = 0;
      z = (1 << k);
      f = 0;
      a.assign(z, 0);
      b.clear();
      r.assign(z, 0);
      for (j = 0; j < z; ++j) a[j] = j + 1;
      while (true) {
        zz = 1 + z / 2;
        for (j = 0; j < zz - 1; ++j) {
          if ((i >> (j + f)) & 1) {
            R = (R + a[2 * j] * AA[zz]) % p;
            b.push_back(a[2 * j + 1]);
            r[a[2 * j] - 1] = zz;
          } else {
            R = (R + a[2 * j + 1] * AA[zz]) % p;
            b.push_back(a[2 * j]);
            r[a[2 * j + 1] - 1] = zz;
          }
        }
        a = b;
        b.clear();
        z /= 2;
        f += z;
        if (int(a.size()) == 1) {
          R = (R + A * a[0]) % p;
          r[a[0] - 1] = 1;
          break;
        }
      }
      if (R == h) {
        for (j = 0; j < Z; ++j) cout << r[j] << ' ';
        return 0;
      }
    }
    cout << -1;
  }
}
