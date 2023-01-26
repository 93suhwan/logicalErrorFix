#include <bits/stdc++.h>
using namespace std;
namespace LYYY {
inline int rd() {
  int s = 0;
  char c = getchar();
  int f = 1;
  while (c < 48 || c > 57) {
    if (c == 45) f = -1;
    c = getchar();
  }
  while (c >= 48 && c <= 57) s = (s << 3) + (s << 1) + (c ^ 48), c = getchar();
  return s * f;
}
long long rdl() {
  long long s = 0;
  char c = getchar();
  int f = 1;
  while (c < 48 || c > 57) {
    if (c == 45) f = -1;
    c = getchar();
  }
  while (c >= 48 && c <= 57) s = (s << 3) + (s << 1) + (c ^ 48), c = getchar();
  return s * f;
}
void wt(int x) {
  if (x >= 10) wt(x / 10);
  putchar(x % 10 + 48);
}
void WT(int x) {
  if (x < 0) x = -x, putchar(45);
  wt(x);
}
void wtl(long long x) {
  if (x >= 10) wtl(x / 10);
  putchar(x % 10 + 48);
}
void WTL(long long x) {
  if (x < 0) x = -x, putchar(45);
  wtl(x);
}
}  // namespace LYYY
using namespace LYYY;
const int maxn = 111;
int N, M, K, ss[maxn][maxn];
void put1() {
  for (int i = 1; i <= N; ++i) {
    for (int j = 1; j <= M; ++j) putchar(ss[i][j] + 'a');
    puts("");
  }
}
void put2() {
  for (int j = 1; j <= M; ++j) {
    for (int i = 1; i <= N; ++i) putchar(ss[i][j] + 'a');
    puts("");
  }
}
bool solve2() {
  if (K & 1) return false;
  K >>= 1;
  int k = 1;
  for (int i = 1; i <= N; i += 2) {
    int cnt = i >> 1;
    for (int j = 1; j <= M; j += 2) {
      ++cnt;
      if (k <= K)
        ss[i][j] = ss[i][j + 1] = (cnt * 2 - 1) % 26,
        ss[i + 1][j] = ss[i + 1][j + 1] = cnt * 2 % 26, ++k;
      else
        ss[i][j] = ss[i + 1][j] = (cnt * 2 - 1) % 26,
        ss[i][j + 1] = ss[i + 1][j + 1] = cnt * 2 % 26;
    }
  }
  return true;
}
bool solve1() {
  int a = M >> 1;
  if (K < a || ((K - a) & 1)) return false;
  K -= a, --N;
  solve2();
  ++N;
  for (int i = 1; i <= M; i += 2)
    ss[N][i] = ss[N][i + 1] = (ss[N - 1][i] + 1) % 26;
  return true;
}
int main() {
  int T = rd();
  while (T--) {
    N = rd(), M = rd(), K = rd();
    if (N & 1) {
      if (solve1())
        puts("YES"), put1();
      else
        puts("NO");
    } else if (M & 1) {
      swap(N, M), K = N * M / 2 - K;
      if (solve1())
        puts("YES"), put2();
      else
        puts("NO");
    } else {
      if (solve2())
        puts("YES"), put1();
      else
        puts("NO");
    }
  }
  return 0;
}
