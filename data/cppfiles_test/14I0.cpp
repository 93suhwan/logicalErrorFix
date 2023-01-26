#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2050;
int N, K, a[MAXN], f[MAXN][MAXN], t[MAXN][MAXN], Ans = 0;
void Init() {
  scanf("%d%d", &N, &K);
  for (int i = 1; i <= N; ++i) scanf("%d", &a[i]);
}
void Solve() {
  Ans = -1;
  for (int i = 0; i <= N + 1; ++i)
    for (int j = 0; j <= N + 1; ++j) f[i][j] = t[i][j] = 0;
  for (int i = 1; i <= N; ++i) a[i] = i - a[i];
  for (int i = 0; i < N; ++i)
    for (int j = N; j >= 1; --j) t[i][j] = t[i][j + 1] + (a[j] == i);
  f[0][0] = t[0][1];
  for (int i = 1; i <= N; ++i)
    for (int j = 0; j <= N; ++j)
      f[i][j] = max(f[i - 1][j], f[i - 1][j - 1] - t[j - 1][i] + t[j][i + 1]);
  for (int i = 0; i <= N; ++i)
    if (f[N][i] >= K) {
      Ans = i;
      return;
    }
}
void Print() { printf("%d\n", Ans); }
int main() {
  int T;
  cin >> T;
  while (T--) {
    Init();
    Solve();
    Print();
  }
  return 0;
}
