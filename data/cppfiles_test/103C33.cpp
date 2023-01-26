#include <bits/stdc++.h>
using namespace std;
int T;
int n, m;
char S[2005][2005];
int Len[2005][2005];
int Color[2005][2005];
void Change(int &x, int &y) {
  if (S[x][y] == 'L')
    y--;
  else if (S[x][y] == 'R')
    y++;
  else if (S[x][y] == 'U')
    x--;
  else if (S[x][y] == 'D')
    x++;
}
bool Check(int x, int y) {
  if (x < 1 || x > n || y < 1 || y > m) return false;
  if (Len[x][y]) return false;
  return true;
}
int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
      scanf("%s", S[i] + 1);
    }
    int Ans = 0, Num = 0;
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= m; j++) {
        int Cnt = 0, Flag = 0;
        int x = i, y = j, nx, ny;
        if (Len[i][j]) continue;
        ++Num;
        while (Check(x, y)) {
          if (Color[x][y]) break;
          Color[x][y] = Num;
          Cnt++;
          nx = x, ny = y;
          Change(nx, ny);
          if (!Check(nx, ny)) break;
          x = nx, y = ny;
        }
        int Step = Cnt + Len[nx][ny];
        if (Color[nx][ny] == Num) Flag = 1;
        x = i, y = j;
        while (Check(x, y)) {
          if (x == nx && y == ny) Flag = 2;
          Cnt++;
          Len[x][y] = Step;
          if (Flag != 2) Step--;
          Change(x, y);
        }
      }
    int Ansx, Ansy;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        if (Len[i][j] > Ans) {
          Ans = Len[i][j];
          Ansx = i, Ansy = j;
        }
      }
    }
    printf("%d %d %d\n", Ansx, Ansy, Ans);
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= m; j++) {
        Color[i][j] = Len[i][j] = 0;
      }
  }
}
