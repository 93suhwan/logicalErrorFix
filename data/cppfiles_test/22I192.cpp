#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
inline int rd() {
  char c = getchar();
  int x = 0, w = 1;
  while (!isdigit(c) && c != '-') c = getchar();
  if (c == '-') w = -1, c = getchar();
  while (isdigit(c)) x = x * 10 + c - 48, c = getchar();
  return x * w;
}
inline void cmx(int& a, int b) { a = a > b ? a : b; }
inline void cmn(int& a, int b) { a = a < b ? a : b; }
int n, k, m[15], q[15][45], V[15][45];
void dfs(int x) {
  if (x == k + 1) {
    int ss = 0;
    for (int i = (0); i < (n); ++i)
      if (V[x][i] == -1) ss++;
    if (ss == 1 && V[x][0] == -1) {
      for (int i = (1); i < (n); ++i)
        if (!V[x][i]) {
          puts("REJECTED");
          exit(0);
        }
      return;
    }
    if (ss == 1 && V[x][n - 1] == -1) {
      for (int i = (0); i < (n - 1); ++i)
        if (V[x][i]) {
          puts("REJECTED");
          exit(0);
        }
      return;
    }
    for (int i = (0); i < (n); ++i)
      if (V[x][i] == -1) {
        puts("REJECTED");
        exit(0);
      }
    for (int i = (1); i < (n); ++i)
      if (!V[x][i] && V[x][i - 1]) {
        puts("REJECTED");
        exit(0);
      }
    return;
  }
  int nn = m[x], s0 = 0, s1 = 0;
  for (int i = (1); i <= (nn); ++i) {
    int t = V[x][q[x][i]];
    if (t == 0) s0++;
    if (t == 1) s1++;
  }
  for (int i = (0); i < (n); ++i) V[x + 1][i] = V[x][i];
  for (int j = (1); j <= (s0 - 1); ++j) V[x + 1][q[x][j]] = 0;
  for (int j = (s0); j <= (nn); ++j) V[x + 1][q[x][j]] = 1;
  for (int i = (s0); i <= (nn - s1); ++i) {
    V[x + 1][q[x][i]] = 0;
    dfs(x + 1);
  }
}
int main() {
  n = rd();
  k = rd();
  for (int i = (1); i <= (k); ++i) {
    m[i] = rd();
    for (int j = (1); j <= (m[i]); ++j) q[i][j] = rd() - 1;
    sort(q[i] + 1, q[i] + m[i] + 1);
  }
  for (int i = (0); i < (n); ++i) V[1][i] = -1;
  dfs(1);
  puts("ACCEPTED");
  return 0;
}
