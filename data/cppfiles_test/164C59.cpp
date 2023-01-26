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
int MOD;
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
int n, k, tot;
int lc[maxn], rc[maxn], ord[maxn], fa[maxn];
bool fl[maxn], ok[maxn];
char S[maxn];
void DFS(int u) {
  if (!u) return;
  DFS(lc[u]), ord[++tot] = u, DFS(rc[u]);
}
void Solve(int u, int co) {
  if (!u || co > k) return;
  Solve(lc[u], co + 1);
  if (fl[lc[u]])
    fl[u] = 1;
  else if (ok[u])
    fl[u] = 1, k -= co;
  if (fl[u]) Solve(rc[u], 1);
}
void Output(int u) {
  if (!u) return;
  Output(lc[u]);
  cout << S[u];
  if (fl[u]) cout << S[u];
  Output(rc[u]);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> k >> (S + 1);
  for (int i = (1); i <= (n); ++i) cin >> lc[i] >> rc[i];
  DFS(1);
  int p = ord[n];
  for (int i = (n - 1); i >= (1); --i) {
    if (S[ord[i]] ^ S[ord[i + 1]]) p = ord[i + 1];
    if (S[ord[i]] < S[p]) ok[ord[i]] = 1;
  }
  Solve(1, 1);
  Output(1);
  return 0;
}
