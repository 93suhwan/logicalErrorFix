#include <bits/stdc++.h>
using namespace std;
int dadsadasda;
const int INF = 0x3f3f3f3f;
const long long LLINF = 1e18;
const int MAXN = 2003;
int N, M;
string MAT[MAXN];
int LEN[MAXN][MAXN];
bool CYC[MAXN][MAXN];
pair<int, int> GOT(int i, int j) {
  if (MAT[i][j] == 'L')
    return {0, -1};
  else if (MAT[i][j] == 'R')
    return {0, 1};
  else if (MAT[i][j] == 'U')
    return {-1, 0};
  else
    return {1, 0};
}
char V[MAXN][MAXN];
void dfs2(int x, int y) {
  if (min(x, y) < 0 || x >= N || y >= M) return;
  V[x][y] = 1;
  int _x = x + GOT(x, y).first, _y = y + GOT(x, y).second;
  if (min(_x, _y) < 0 || _x >= N || _y >= M) {
    V[x][y] = 2;
    return;
  }
  if (V[_x][_y] == 1)
    CYC[_x][_y] = 1;
  else if (V[_x][_y] == 0)
    dfs2(_x, _y);
  V[x][y] = 2;
}
void get_cycles() {
  for (int i = 0; i < N; i++)
    for (int j = 0; j < M; j++)
      if (V[i][j] == 0) dfs2(i, j);
  for (int i = 0; i < N; i++)
    for (int j = 0; j < M; j++)
      if (CYC[i][j]) {
        int x = i, y = j;
        int cnt = 0;
        do {
          cnt++;
          int _x = x + GOT(x, y).first, _y = y + GOT(x, y).second;
          x = _x, y = _y;
        } while (x != i || y != j);
        x = i, y = j;
        do {
          LEN[x][y] = cnt;
          int _x = x + GOT(x, y).first, _y = y + GOT(x, y).second;
          x = _x, y = _y;
        } while (x != i || y != j);
      }
}
int dfs(int x, int y) {
  if (min(x, y) < 0 || x >= N || y >= M) return 0;
  if (LEN[x][y] != 0) return LEN[x][y];
  LEN[x][y] = 1 + dfs(x + GOT(x, y).first, y + GOT(x, y).second);
  return LEN[x][y];
}
void solve() {
  dadsadasda = scanf("%d %d", &N, &M);
  for (int i = 0; i < N; i++) cin >> MAT[i];
  get_cycles();
  int bst = 0;
  int x = 0, y = 0;
  for (int i = 0; i < N; i++)
    for (int j = 0; j < M; j++) {
      if (LEN[i][j] == 0) dfs(i, j);
      if (LEN[i][j] > bst) {
        bst = LEN[i][j];
        x = i;
        y = j;
      }
    }
  printf("%d %d %d\n", x + 1, y + 1, bst);
  for (int i = 0; i < N; i++)
    for (int j = 0; j < M; j++) {
      LEN[i][j] = 0;
      CYC[i][j] = 0;
      V[i][j] = 0;
    }
  for (int i = 0; i < N; i++) MAT[i].clear();
}
int main() {
  int t;
  dadsadasda = scanf("%d", &t);
  while (t--) solve();
  return 0;
}
