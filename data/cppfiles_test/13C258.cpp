#include <bits/stdc++.h>
using namespace std;
int n, m, k;
char ans[105][105];
int dir[4][2] = {0, 1, 0, -1, 1, 0, -1, 0};
int w[50];
char get_color(int x, int y) {
  for (int i = 0; i < 26; i++) w[i] = 0;
  for (int i = 0; i < 4; i++) {
    int nx = x + dir[i][0], ny = y + dir[i][1];
    if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
    if (ans[nx][ny] != 0) w[ans[nx][ny] - 'a']++;
  }
  x++;
  for (int i = 0; i < 4; i++) {
    int nx = x + dir[i][0], ny = y + dir[i][1];
    if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
    if (ans[nx][ny] != 0) w[ans[nx][ny] - 'a']++;
  }
  x--, y++;
  for (int i = 0; i < 4; i++) {
    int nx = x + dir[i][0], ny = y + dir[i][1];
    if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
    if (ans[nx][ny] != 0) w[ans[nx][ny] - 'a']++;
  }
  for (int i = 0; i < 26; i++) {
    if (w[i] == 0) return (i + 'a');
  }
  return 0;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++) ans[i][j] = 0;
    int key = n * m / 2 - k;
    if (n & 1) {
      k -= m / 2;
      if (k < 0) {
        cout << "NO\n";
        continue;
      }
    } else if (m & 1) {
      key -= n / 2;
      if (key < 0) {
        cout << "NO\n";
        continue;
      }
    }
    if ((k & 1) || (key & 1)) {
      cout << "NO\n";
      continue;
    }
    cout << "YES\n";
    if (n & 1) {
      for (int i = 0; i < m; i += 2) {
        char color = get_color(0, i);
        ans[0][i] = ans[0][i + 1] = color;
      }
      int nowx = 1, nowy = 0;
      for (int i = 0; i < k; i++) {
        while (ans[nowx][nowy] != 0) {
          nowx++;
          if (nowx >= n) nowx = 1, nowy += 2;
        }
        char color = get_color(nowx, nowy);
        ans[nowx][nowy] = ans[nowx][nowy + 1] = color;
        nowx++;
        if (nowx >= n) nowx = 1, nowy += 2;
      }
      for (int i = 0; i < key; i++) {
        while (ans[nowx][nowy] != 0) {
          nowx += 2;
          if (nowx >= n) nowx = 1, nowy++;
        }
        char color = get_color(nowx, nowy);
        ans[nowx][nowy] = ans[nowx + 1][nowy] = color;
        nowx += 2;
        if (nowx >= n) nowx = 1, nowy++;
      }
    } else if (m & 1) {
      for (int i = 0; i < n; i += 2) {
        char color = get_color(i, 0);
        ans[i][0] = ans[i + 1][0] = color;
      }
      int nowx = 0, nowy = 1;
      for (int i = 0; i < key; i++) {
        while (ans[nowx][nowy] != 0) {
          nowy++;
          if (nowy >= m) nowx += 2, nowy = 1;
        }
        char color = get_color(nowx, nowy);
        ans[nowx][nowy] = ans[nowx + 1][nowy] = color;
        nowy++;
        if (nowy >= m) nowx += 2, nowy = 1;
      }
      for (int i = 0; i < k; i++) {
        while (ans[nowx][nowy] != 0) {
          nowy += 2;
          if (nowy >= m) nowx++, nowy = 1;
        }
        char color = get_color(nowx, nowy);
        ans[nowx][nowy] = ans[nowx][nowy + 1] = color;
        nowy += 2;
        if (nowy >= m) nowx++, nowy = 1;
      }
    } else {
      int nowx = 0, nowy = 0;
      for (int i = 0; i < k; i++) {
        while (ans[nowx][nowy] != 0) {
          nowx++;
          if (nowx >= n) nowx = 0, nowy += 2;
        }
        char color = get_color(nowx, nowy);
        ans[nowx][nowy] = ans[nowx][nowy + 1] = color;
        nowx++;
        if (nowx >= n) nowx = 0, nowy += 2;
      }
      for (int i = 0; i < key; i++) {
        while (ans[nowx][nowy] != 0) {
          nowx += 2;
          if (nowx >= n) nowx = 0, nowy++;
        }
        char color = get_color(nowx, nowy);
        ans[nowx][nowy] = ans[nowx + 1][nowy] = color;
        nowx += 2;
        if (nowx >= n) nowx = 0, nowy++;
      }
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) cout << ans[i][j];
      cout << "\n";
    }
  }
}
