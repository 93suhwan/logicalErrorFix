#include <bits/stdc++.h>
using namespace std;
const int MOD = (int)1e9 + 7;
const int FFTMOD = 119 << 23 | 1;
const int INF = (int)1e9 + 23111992;
const long long LINF = (long long)1e18 + 23111992;
const long double PI = acos((long double)-1);
const long double EPS = 1e-9;
inline long long gcd(long long a, long long b) {
  long long r;
  while (b) {
    r = a % b;
    a = b;
    b = r;
  }
  return a;
}
inline long long lcm(long long a, long long b) { return a / gcd(a, b) * b; }
inline long long fpow(long long n, long long k, int p = MOD) {
  long long r = 1;
  for (; k; k >>= 1) {
    if (k & 1) r = r * n % p;
    n = n * n % p;
  }
  return r;
}
template <class T>
inline int chkmin(T& a, const T& val) {
  return val < a ? a = val, 1 : 0;
}
template <class T>
inline int chkmax(T& a, const T& val) {
  return a < val ? a = val, 1 : 0;
}
inline unsigned long long isqrt(unsigned long long k) {
  unsigned long long r = sqrt(k) + 1;
  while (r * r > k) r--;
  return r;
}
inline long long icbrt(long long k) {
  long long r = cbrt(k) + 1;
  while (r * r * r > k) r--;
  return r;
}
inline void addmod(int& a, int val, int p = MOD) {
  if ((a = (a + val)) >= p) a -= p;
}
inline void submod(int& a, int val, int p = MOD) {
  if ((a = (a - val)) < 0) a += p;
}
inline int mult(int a, int b, int p = MOD) { return (long long)a * b % p; }
inline int inv(int a, int p = MOD) { return fpow(a, p - 2, p); }
inline int sign(long double x) { return x < -EPS ? -1 : x > +EPS; }
inline int sign(long double x, long double y) { return sign(x - y); }
mt19937 mt(chrono::high_resolution_clock::now().time_since_epoch().count());
inline int mrand() { return abs((int)mt()); }
inline int mrand(int k) { return abs((int)mt()) % k; }
void chemthan() {
  int test;
  cin >> test;
  while (test--) {
    auto solve = [&]() {
      string s;
      int num = 0;
      auto go = [&](int x, int y) {
        assert(++num <= 130);
        cout << x << " " << y << "\n";
        cout.flush();
        cin >> s;
      };
      int cx = 1, cy = 1;
      go(cx, cy);
      if (s == "Done") {
        return;
      }
      while (1) {
        if (s.find("Right") != -1) {
          go(cx, ++cy);
          if (s == "Done") {
            return;
          }
        } else {
          int cnt = 0;
          while (1) {
            for (int i = (1); i < (8 + 1); ++i) {
              if (cx != i) {
                go(cx = i, cy);
                if (s == "Done") {
                  return;
                }
                if (s.find("Left") != -1) {
                  cnt = 0;
                } else {
                  cnt++;
                }
                if (s.find("Right") != -1) {
                  break;
                }
              }
            }
            if (s.find("Right") != -1) {
              break;
            }
            for (int i = (8) - 1; i >= (1); --i) {
              if (cx != i) {
                go(cx = i, cy);
                if (s == "Done") {
                  return;
                }
                if (s.find("Left") != -1) {
                  cnt = 0;
                } else {
                  cnt++;
                }
                if (s.find("Right") != -1) {
                  break;
                }
              }
            }
            if (s.find("Right") != -1) {
              break;
            }
            if (8 < cnt) {
              break;
            }
          }
          s = "Right";
        }
      }
    };
    solve();
  }
}
int32_t main(int32_t argc, char* argv[]) {
  if (argc > 1) {
    assert(freopen(argv[1], "r", stdin));
  }
  if (argc > 2) {
    assert(freopen(argv[2], "wb", stdout));
  }
  chemthan();
  cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
  return 0;
}
