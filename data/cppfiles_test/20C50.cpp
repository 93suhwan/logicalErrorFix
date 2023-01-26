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
int mat[405][405], psum[405][405];
void prefixSum(int n, int m) {
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++)
      psum[i][j] =
          mat[i][j] + psum[i - 1][j] + psum[i][j - 1] - psum[i - 1][j - 1];
  }
}
inline int recSum(int i1, int j1, int i2, int j2) {
  return psum[i2][j2] - psum[i1 - 1][j2] - psum[i2][j1 - 1] +
         psum[i1 - 1][j1 - 1];
}
inline int moveNeed(int i1, int j1, int i2, int j2) {
  int sum = recSum(i1, j1, i2, j2);
  int inner = recSum(i1 + 1, j1 + 1, i2 - 1, j2 - 1);
  int outer = sum - inner;
  int tot = (j2 - j1 + 1) * 2 + (i2 - i1 + 1) * 2 - 4;
  return inner + (tot - outer - !mat[i1][j1] - !mat[i1][j2] - !mat[i2][j1] -
                  !mat[i2][j2]);
}
inline int zcnt(int i, int c1, int c2) {
  return c2 - c1 + 1 - recSum(i, c1, i, c2);
}
inline int ocnt(int i, int c1, int c2) { return recSum(i, c1, i, c2); }
int calc(int c1, int c2, int n) {
  int pre = moveNeed(1, c1, 5, c2), ret = pre;
  for (int i = 6; i <= n; i++) {
    int x = moveNeed(i - 4, c1, i, c2);
    int y = pre - zcnt(i - 1, c1 + 1, c2 - 1) + ocnt(i - 1, c1 + 1, c2 - 1) +
            !mat[i - 1][c1] + !mat[i - 1][c2] + zcnt(i, c1 + 1, c2 - 1);
    pre = min({x, y});
    ret = min(ret, pre);
  }
  return ret;
}
int main() {
  OPFILE();
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
      string s;
      cin >> s;
      for (int j = 0; j < m; j++) mat[i][j + 1] = s[j] - 48;
    }
    prefixSum(n, m);
    int ans = 100007;
    for (int i = 1; i <= m; i++) {
      for (int j = i + 3; j <= m; j++) ans = min(ans, calc(i, j, n));
    }
    cout << ans << endl;
  }
  runTime();
  ;
}
