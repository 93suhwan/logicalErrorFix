#include <bits/stdc++.h>
using namespace std;
string a, b;
int n, m;
int p[510];
void kmppreprocess() {
  int i = 0, j = -1;
  p[0] = -1;
  while (i < m) {
    while (j >= 0 && b[i] != b[j]) j = p[j];
    i++, j++;
    p[i] = j;
  }
}
int kmpsearch(string s) {
  int n = s.size();
  int i = 0, j = 0, tot = 0;
  while (i < n) {
    while (j >= 0 && s[i] != b[j]) j = p[j];
    i++, j++;
    if (j == m) {
      tot++;
      j = p[j];
    }
  }
  return tot;
}
int dp[510][510], tmp[510][510];
int go[510][2];
int v[510];
int main() {
  cin >> n >> m >> a >> b;
  kmppreprocess();
  for (int i = 0; i < n; i++) v[i] = a[i] - '0';
  for (int i = 0; i < m; i++) {
    int j = i;
    if (b[i] == '0') {
      go[i][0] = i + 1;
      while (j >= 0 && b[j] != '1') j = p[j];
      go[i][1] = j + 1;
    } else {
      go[i][1] = i + 1;
      while (j >= 0 && b[j] != '0') j = p[j];
      go[i][0] = j + 1;
    }
  }
  int j = p[m];
  if (b[j] == '0') {
    go[m][0] = j + 1;
    while (j >= 0 && b[j] != '1') j = p[j];
    go[m][1] = j + 1;
  } else {
    go[m][1] = j + 1;
    while (j >= 0 && b[j] != '0') j = p[j];
    go[m][0] = j + 1;
  }
  for (int i = 0; i < 510; i++)
    for (int j = 0; j < 510; j++) dp[i][j] = 1000000000;
  dp[0][0] = 0;
  for (int i = 0; i < n; i++) {
    for (int i = 0; i < 510; i++)
      for (int j = 0; j < 510; j++) tmp[i][j] = 1000000000;
    for (int j = 0; j <= m; j++) {
      int to[2];
      to[0] = go[j][v[i]];
      to[1] = go[j][1 - v[i]];
      for (int k = 0; k < 510 - 10; k++) {
        for (int pl = 0; pl < 2; pl++) {
          int lel = to[pl] == m;
          tmp[to[pl]][k + lel] = min(tmp[to[pl]][k + lel], dp[j][k] + pl);
        }
      }
    }
    for (int i = 0; i < 510; i++)
      for (int j = 0; j < 510; j++) dp[i][j] = tmp[i][j];
  }
  for (int i = 1; i <= m; i++)
    for (int j = 0; j < 510; j++) dp[i][j] = min(dp[i][j], dp[i - 1][j]);
  for (int i = 0; i <= n - m + 1; i++)
    cout << (dp[m][i] == 1000000000 ? -1 : dp[m][i]) << " ";
}
