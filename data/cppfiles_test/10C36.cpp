#include <bits/stdc++.h>
using namespace std;
template <class c>
struct rge {
  c b, e;
};
template <class c>
rge<c> range(c i, c j) {
  return rge<c>{i, j};
}
template <class c>
auto dud(c* x) -> decltype(cerr << *x, 0);
template <class c>
char dud(...);
struct debug {
  template <class c>
  debug& operator<<(const c&) {
    return *this;
  }
};
const int mxn = 1e5;
const long long mod = 1e9 + 7;
long long n, m, k, r, c, ax, ay, bx, by;
long long fastexpo(long long a, long long b) {
  long long ret = 1;
  while (b) {
    if (b & 1) {
      ret = (ret * a) % mod;
    }
    a = (a * a) % mod;
    b >>= 1;
  }
  return ret;
}
long long solve(long long n1, long long m1, long long k1, long long r1,
                long long c1, long long ax1, long long ay1, long long bx1,
                long long by1) {
  if (n1 == 1 && m1 == 1) {
    return k1;
  } else if (ax1 == bx1 && ay1 == by1) {
    long long ans = fastexpo(k1, n1 * m1);
    return ans;
  } else if (abs(ax1 - bx1) < r1 && abs(ay1 - by1) < c1) {
    bool atas, kanan;
    if (bx1 >= ax1) {
      atas = false;
    } else {
      atas = true;
    }
    if (by1 >= ay1) {
      kanan = true;
    } else {
      kanan = false;
    }
    long long r2, c2;
    if (atas) {
      r2 = bx1 + r1 - ax1;
    } else {
      r2 = ax1 + r1 - bx1;
    }
    if (kanan) {
      c2 = ay1 + c1 - by1;
    } else {
      c2 = by1 + c1 - ay1;
    }
    long long temp;
    if (!kanan && atas) {
      temp = solve(r1, c1, k1, r2, c2, 1ll, 1ll, r1 - r2 + 1, c1 - c2 + 1);
    } else if (!kanan && !atas) {
      temp = solve(r1, c1, k1, r2, c2, r1 - r2 + 1, 1ll, 1ll, c1 - c2 + 1);
    } else if (kanan && !atas) {
      temp = solve(r1, c1, k1, r2, c2, r1 - r2 + 1, c1 - c2 + 1, 1ll, 1ll);
    } else if (kanan && atas) {
      temp = solve(r1, c1, k1, r2, c2, 1ll, c1 - c2 + 1, r1 - r2 + 1, 1ll);
    }
    debug() << "["
            << "temp"
               ": "
            << (temp) << "] ";
    long long ans = fastexpo(k1, n1 * m1 - 2 * r1 * c1 + r2 * c2);
    return (ans * temp) % mod;
  } else {
    long long ans = fastexpo(k1, n1 * m1 - 2 * r1 * c1);
    ans = (ans * fastexpo(k1, r1 * c1)) % mod;
    return ans;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m >> k >> r >> c >> ax >> ay >> bx >> by;
  cout << solve(n, m, k, r, c, ax, ay, bx, by);
}
