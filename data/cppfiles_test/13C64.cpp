#include <bits/stdc++.h>
using namespace std;
char mp[110][110];
bool solve(int n, int m, int k) {
  int num = n * m / 2 - k;
  if (n == 1) {
    if (num)
      return false;
    else
      return true;
  }
  if (m == 1) {
    if (k)
      return false;
    else
      return true;
  }
  if (n % 2 == 0 && m % 2 == 0) {
    if (k & 1)
      return false;
    else
      return true;
  }
  if (n % 2 == 0) {
    num -= n / 2;
    if (num < 0)
      return false;
    else if (num & 1)
      return false;
    else
      return true;
  } else if (m % 2 == 0) {
    k -= m / 2;
    if (k < 0)
      return false;
    else if (k & 1)
      return false;
    else
      return true;
  }
}
int dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};
char get(int x, int y, bool _v = true) {
  int ch[26] = {};
  for (int i = 0; i < 4; i++) {
    int xx = x + dx[i];
    int yy = y + dy[i];
    if (isalpha(mp[xx][yy])) ch[mp[xx][yy] - 'a']++;
  }
  if (_v)
    x++;
  else
    y++;
  for (int i = 0; i < 4; i++) {
    int xx = x + dx[i];
    int yy = y + dy[i];
    if (isalpha(mp[xx][yy])) ch[mp[xx][yy] - 'a']++;
  }
  for (int i = 0; i < 26; i++)
    if (!ch[i]) return 'a' + i;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m, num;
    cin >> n >> m >> num;
    int k = n * m / 2 - num;
    if (solve(n, m, num)) {
      puts("YES");
      if (n & 1) {
        for (int i = 1; i <= m; i += 2) {
          mp[1][i] = mp[1][i + 1] = get(1, i, false);
          num--;
        }
        int nowx = 2, nowy = 1;
        if (num)
          while (num--) {
            mp[nowx][nowy] = mp[nowx][nowy + 1] = get(nowx, nowy, false);
            nowx++;
            if (nowx > n) nowx = 2, nowy += 2;
          }
        while (k) {
          mp[nowx][nowy] = mp[nowx + 1][nowy] = get(nowx, nowy);
          mp[nowx][nowy + 1] = mp[nowx + 1][nowy + 1] = get(nowx, nowy + 1);
          nowx += 2;
          k -= 2;
          if (nowx > n) nowx = 2, nowy += 2;
        }
      } else if (m & 1) {
        for (int i = 1; i <= n; i += 2) {
          mp[i][1] = mp[i + 1][1] = get(i, 1);
          k--;
        }
        int nowx = 1, nowy = 2;
        if (k)
          while (k--) {
            mp[nowx][nowy] = mp[nowx + 1][nowy] = get(nowx, nowy);
            nowy++;
            if (nowy > m) nowx += 2, nowy = 2;
          }
        while (num) {
          mp[nowx][nowy] = mp[nowx][nowy + 1] = get(nowx, nowy, false);
          mp[nowx + 1][nowy] = mp[nowx + 1][nowy + 1] =
              get(nowx + 1, nowy, false);
          num -= 2;
          nowy += 2;
          if (nowy > m) nowx += 2, nowy = 2;
        }
      } else {
        int nowx = 1, nowy = 1;
        if (num)
          while (num--) {
            mp[nowx][nowy] = mp[nowx][nowy + 1] = get(nowx, nowy, false);
            nowx++;
            if (nowx > n) nowx = 1, nowy += 2;
          }
        while (k) {
          mp[nowx][nowy] = mp[nowx + 1][nowy] = get(nowx, nowy);
          mp[nowx][nowy + 1] = mp[nowx + 1][nowy + 1] = get(nowx, nowy + 1);
          nowx += 2;
          k -= 2;
          if (nowx > n) nowx = 1, nowy += 2;
        }
      }
      for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
          printf("%c", mp[i][j]);
        }
        cout << endl;
      }
    } else
      puts("NO");
  }
}
