#include <bits/stdc++.h>
using namespace std;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int N, M, K;
int Map[105][105];
int ans[105 * 105];
bool ban[27];
void solve() {
  scanf("%d%d%d", &N, &M, &K);
  int TN = N, TM = M, TK = K;
  int K2 = N * M / 2 - K;
  if ((N & 1) && (M & 1)) {
    printf("NO\n");
    return;
  }
  if (N & 1) {
    K -= M / 2;
    if (K < 0) {
      printf("NO\n");
      return;
    }
  }
  if (M & 1) {
    K2 -= N / 2;
    if (K2 < 0) {
      printf("NO\n");
      return;
    }
  }
  if (K & 1) {
    printf("NO\n");
    return;
  }
  if (K2 & 1) {
    printf("NO\n");
    return;
  }
  printf("YES\n");
  int cnt = 0, precnt = 0;
  for (int i = 0; i < (int)(TN + 3); ++i)
    for (int j = 0; j < (int)(TM + 3); ++j) Map[i][j] = 0;
  if (N & 1) {
    for (int i = 0; i < M; i += 2) Map[N - 1][i] = Map[N - 1][i + 1] = ++cnt;
    N = N / 2 * 2;
  }
  if (M & 1) {
    for (int i = 0; i < N; i += 2) {
      Map[i][M - 1] = Map[i + 1][M - 1] = ++cnt;
      precnt++;
    }
    M = M / 2 * 2;
  }
  for (int i = 0; i < N; i += 2)
    for (int j = 0; j < M; j += 2) {
      if (cnt - precnt < TK) {
        Map[i][j] = Map[i][j + 1] = ++cnt;
        Map[i + 1][j] = Map[i + 1][j + 1] = ++cnt;
      } else {
        Map[i][j] = Map[i + 1][j] = ++cnt;
        Map[i][j + 1] = Map[i + 1][j + 1] = ++cnt;
      }
    }
  for (int i = 1; i <= (int)(cnt + 1); ++i) ans[i] = -1;
  for (int i = 0; i < (int)(TN); ++i)
    for (int j = 0; j < (int)(TM); ++j) {
      if (ans[Map[i][j]] != -1) continue;
      for (int k = 0; k < (int)(26); ++k) ban[k] = false;
      for (int k = 0; k < (int)(4); ++k) {
        int x = i + dx[k], y = j + dy[k];
        if (x < 0 || x >= TN || y < 0 || y >= TM) continue;
        if (Map[x][y] != Map[i][j] && ans[Map[x][y]] != -1)
          ban[ans[Map[x][y]]] = true;
      }
      int ni, nj;
      if (Map[i + 1][j] == Map[i][j])
        ni = i + 1, nj = j;
      else
        ni = i, nj = j + 1;
      for (int k = 0; k < (int)(4); ++k) {
        int x = ni + dx[k], y = nj + dy[k];
        if (x < 0 || x >= TN || y < 0 || y >= TM) continue;
        if (Map[x][y] != Map[i][j] && ans[Map[x][y]] != -1)
          ban[ans[Map[x][y]]] = true;
      }
      for (int k = 0; k < (int)(26); ++k)
        if (!ban[k]) {
          ans[Map[i][j]] = k;
          break;
        }
    }
  for (int i = 0; i < (int)(TN); ++i) {
    for (int j = 0; j < (int)(TM); ++j) printf("%c", 'a' + ans[Map[i][j]]);
    printf("\n");
  }
}
int main() {
  int T;
  scanf("%d", &T);
  while (T--) solve();
  return 0;
}
