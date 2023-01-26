#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
int n, m, f[2001][4001], p[2001][4001];
char ch1[3001], ch2[3001];
int add(int a, int b) {
  if (a + b >= mod) return a + b - mod;
  return a + b;
}
int del(int a, int b) {
  if (a - b < 0) return a - b + mod;
  return a - b;
}
int mul(int a, int b) { return ((int)(1ll * a * b % mod)); }
int find(int a) {
  if (a < 0) a = -a;
  return a;
}
void solve(int a, int l, int r) {
  for (int i = 2000 - a + 1; i < 2000 + a; i++) {
    int c = i + l - r;
    f[a][c] = add(f[a][c], f[a - 1][i]);
    p[a][c] = add(p[a][c], p[a - 1][i]);
    p[a][c] = add(p[a][c], mul(f[a - 1][i], find(c - 2000)));
  }
}
int main() {
  scanf("%d", &m);
  while (m) {
    m--;
    scanf("%d", &n);
    scanf("%s", ch1 + 1);
    scanf("%s", ch2 + 1);
    for (int i = 2; i <= n; i = i + 2) {
      if (ch1[i] != '?') ch1[i] = (ch1[i] ^ 1);
      if (ch2[i] != '?') ch2[i] = (ch2[i] ^ 1);
    }
    f[0][2000] = 1;
    for (int i = 1; i <= n; i++) {
      if (ch1[i] == '?') {
        if (ch2[i] == '?') {
          solve(i, 0, 0);
          solve(i, 0, 1);
          solve(i, 1, 0);
          solve(i, 1, 1);
        } else {
          solve(i, 0, ch2[i] - '0');
          solve(i, 1, ch2[i] - '0');
        }
      } else {
        if (ch2[i] == '?') {
          solve(i, ch1[i] - '0', 0);
          solve(i, ch1[i] - '0', 1);
        } else {
          solve(i, ch1[i] - '0', ch2[i] - '0');
        }
      }
    }
    printf("%d\n", p[n][2000]);
    for (int i = 0; i <= n; i++) {
      ch1[i] = 0;
      ch2[i] = 0;
      for (int j = 2000 - n; j <= 2000 + n; j++) {
        f[i][j] = 0;
        p[i][j] = 0;
      }
    }
  }
}
