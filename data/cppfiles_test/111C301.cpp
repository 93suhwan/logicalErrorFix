#include <bits/stdc++.h>
using namespace std;
clock_t Start;
inline void runTime() {}
int ROW[] = {+1, -1, +0, +0};
int COL[] = {+0, +0, +1, -1};
int X[] = {+0, +0, +1, -1, -1, +1, -1, +1};
int Y[] = {-1, +1, +0, +0, +1, +1, -1, -1};
int KX[] = {-2, -2, -1, -1, 1, 1, 2, 2};
int KY[] = {-1, 1, -2, 2, -2, 2, -1, 1};
vector<int> basePrime = {1009, 1013, 1019, 1021, 1031, 1223, 1229, 1231, 1237,
                         1249, 1289, 1291, 1297, 1301, 1303, 353,  359,  367,
                         373,  379,  859,  863,  877,  881,  883,  1931, 1933,
                         1949, 1951, 1973, 401,  409,  419,  421,  431,  1709,
                         1721, 1723, 1733, 1741, 3499, 3511, 3517, 3527, 3529,
                         929,  937,  941,  947,  953};
template <class XXX>
XXX GCD(XXX a, XXX b) {
  return b == 0 ? a : GCD(b, a % b);
}
template <class XXX>
XXX LCM(XXX a, XXX b) {
  return a * (b / GCD(a, b));
}
template <class T>
inline void fastRead(T &r) {
  r = 0;
  register int f = 1;
  register char ch = getchar();
  while (ch < '0' or ch > '9') {
    f = (ch == '-' ? -1 : 1), ch = getchar();
  }
  while (ch >= '0' and ch <= '9') {
    r = r * 10 + ch - '0', ch = getchar();
  }
  r *= f;
}
template <class XXX>
inline XXX moduler(XXX num, XXX mod) {
  return (num >= mod ? num -= mod : num);
}
inline int Set(int pos, int N) { return N = N | (1 << pos); }
inline int Reset(int pos, int N) { return N = N & ~(1 << pos); }
inline bool Check(int pos, int N) { return (bool)(N & (1 << pos)); }
inline void OPFILE() {}
int main() {
  OPFILE();
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
      for (int j = 0; j < i; j++) cout << '(';
      for (int j = 0; j < i; j++) cout << ')';
      int now = n - i;
      for (int j = 0; j < now; j++) cout << '(';
      for (int j = 0; j < now; j++) cout << ')';
      puts("");
    }
  }
  runTime();
  ;
}
