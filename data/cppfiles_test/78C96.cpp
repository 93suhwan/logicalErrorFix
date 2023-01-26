#include <bits/stdc++.h>
using namespace std;
const int MAXN = 3e5 + 50, MAXM = 2e7 + 50, INF = 0x3f3f3f3f, MOD = 1e9 + 9,
          BASE = 4e5;
const double eps = 1e-9;
int read() {
  int cnt = 0, flag = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') flag = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    cnt = (cnt << 1) + (cnt << 3) + (c ^ 48);
    c = getchar();
  }
  return flag * cnt;
}
void write(int x) {
  if (x >= 10) write(x / 10);
  putchar(x % 10 + '0');
}
int N, a[MAXN], cnt[31], ans[MAXN], Ans = 0;
bool check(int x) {
  for (int i = 30; i >= 0; --i)
    if (cnt[i] % x != 0) return false;
  return true;
}
void Init() {
  N = read();
  for (int i = 1; i <= N; ++i) a[i] = read();
}
void Solve() {
  Ans = 0;
  memset(cnt, 0, sizeof(cnt));
  for (int i = 1; i <= N; ++i)
    for (int j = 30; j >= 0; --j)
      if ((a[i] >> j) & 1) ++cnt[j];
  for (int i = 1; i <= N; ++i)
    if (check(i)) ans[++Ans] = i;
}
void Print() {
  for (int i = 1; i <= Ans; ++i) printf("%d ", ans[i]);
  printf("\n");
}
int main() {
  int T = read();
  while (T--) {
    Init();
    Solve();
    Print();
  }
  return 0;
}
