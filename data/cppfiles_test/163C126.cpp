#include <bits/stdc++.h>
using namespace std;
char BB[1 << 16], *SB = BB, *TB = BB;
template <typename T>
void read(T &n) {
  T w = 1;
  n = 0;
  char ch =
      (SB == TB && (TB = (SB = BB) + fread(BB, 1, 1 << 15, stdin), SB == TB)
           ? EOF
           : *SB++);
  while (!isdigit(ch)) {
    if (ch == '-') w = -1;
    ch = (SB == TB && (TB = (SB = BB) + fread(BB, 1, 1 << 15, stdin), SB == TB)
              ? EOF
              : *SB++);
  }
  while (isdigit(ch)) {
    n = (n << 3) + (n << 1) + (ch & 15);
    ch = (SB == TB && (TB = (SB = BB) + fread(BB, 1, 1 << 15, stdin), SB == TB)
              ? EOF
              : *SB++);
  }
  n *= w;
}
template <typename T>
inline void exg(T &a, T &b) {
  a ^= b ^= a ^= b;
}
template <typename T>
inline void chkmn(T &a, const T &b) {
  (a > b) && (a = b);
}
template <typename T>
inline void chkmx(T &a, const T &b) {
  (a < b) && (a = b);
}
inline int min(const int &a, const int &b) { return a < b ? a : b; }
inline int max(const int &a, const int &b) { return a > b ? a : b; }
inline long long min(const long long &a, const long long &b) {
  return a < b ? a : b;
}
inline long long max(const long long &a, const long long &b) {
  return a > b ? a : b;
}
const int MOD = 1e9 + 7;
inline int adt(const int &a) { return (a % MOD + MOD) % MOD; }
inline int inc(const int &a, const int &b) {
  return a + b >= MOD ? a + b - MOD : a + b;
}
inline int dec(const int &a, const int &b) {
  return a - b < 0 ? a - b + MOD : a - b;
}
inline int mul(const int &a, const int &b) { return 1LL * a * b % MOD; }
inline int sqr(const int &a) { return 1LL * a * a % MOD; }
inline int cub(const int &a) { return 1LL * a * a % MOD * a % MOD; }
inline void Adt(int &a) { a = (a % MOD + MOD) % MOD; }
inline void Inc(int &a, const int &b) { ((a += b) >= MOD) && (a -= MOD); }
inline void Dec(int &a, const int &b) { ((a -= b) < 0) && (a += MOD); }
inline void Mul(int &a, const int &b) { a = 1LL * a * b % MOD; }
inline void Sqr(int &a) { a = 1LL * a * a % MOD; }
inline void Cub(int &a) { a = 1LL * a * a % MOD * a % MOD; }
inline int fsp(int a, int x = MOD - 2) {
  int res = 1;
  while (x) {
    if (x & 1) Mul(res, a);
    Sqr(a), x >>= 1;
  }
  return res;
}
const int maxn = 2e5 + 5;
int tt, n, m, p, q, dx, dy;
pair<int, int> A, B;
inline pair<int, int> nxt(pair<int, int> x) {
  pair<int, int> to = make_pair(x.first + dx, x.second + dy);
  if (to.first < 1 || to.first > n) dx = -dx;
  if (to.second < 1 || to.second > m) dy = -dy;
  return make_pair(x.first + dx, x.second + dy);
}
inline int calc(pair<int, int> A, pair<int, int> B) {
  return (A.first == B.first || A.second == B.second) ? q : 1;
}
int main() {
  read(tt);
  while (tt--) {
    read(n), read(m), read(A.first), read(A.second), read(B.first),
        read(B.second), read(p);
    Mul(p, fsp(100)), q = dec(1, p);
    dx = -1, dy = -1;
    int s = 0, t = 1;
    A = nxt(A);
    int rx = dx, ry = dy;
    pair<int, int> X = A;
    do {
      int tmp = calc(A, B);
      Inc(s, 1);
      Mul(s, tmp), Mul(t, tmp);
      A = nxt(A);
    } while (!(A == X && dx == rx && dy == ry));
    printf("%d\n", mul(s, fsp(dec(1, t))));
  }
  return 0;
}
