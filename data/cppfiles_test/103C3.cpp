#include <bits/stdc++.h>
using namespace std;
using ll = long long;
string s[2000];
int cnt[2000][2000], was[2000][2000];
pair<int, int> preder[4000000];
int col = 0;
int main() {
  cin.tie(0);
  cout.tie(0);
  ios_base::sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
      cin >> s[i];
    }
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        cnt[i][j] = was[i][j] = -1;
      }
    }
    int ansx = 0, ansy = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (cnt[i][j] == -1) {
          int nowx = i, nowy = j, tim = 0;
          while (nowx >= 0 && nowy >= 0 && nowx < n && nowy < m &&
                 cnt[nowx][nowy] == -1) {
            preder[col] = {nowx, nowy};
            ++col;
            cnt[nowx][nowy] = tim;
            ++tim;
            if (s[nowx][nowy] == 'U')
              --nowx;
            else if (s[nowx][nowy] == 'D')
              ++nowx;
            else if (s[nowx][nowy] == 'R')
              ++nowy;
            else
              --nowy;
          }
          int kekx, keky, zn;
          if (nowx >= 0 && nowy >= 0 && nowx < n && nowy < m) {
            if (was[nowx][nowy] == -1) {
              kekx = preder[col - 1].first, keky = preder[col - 1].second;
              zn = cnt[kekx][keky] - cnt[nowx][nowy] + 1;
              while (preder[col - 1].first != nowx ||
                     preder[col - 1].second != nowy) {
                cnt[preder[col - 1].first][preder[col - 1].second] = zn;
                was[preder[col - 1].first][preder[col - 1].second] = 1;
                --col;
              }
              cnt[preder[col - 1].first][preder[col - 1].second] = zn;
              was[preder[col - 1].first][preder[col - 1].second] = 1;
              --col;
            }
          }
          while (col > 0) {
            nowx = preder[col - 1].first;
            nowy = preder[col - 1].second;
            int nx = nowx, ny = nowy;
            if (s[nowx][nowy] == 'U')
              --nowx;
            else if (s[nowx][nowy] == 'D')
              ++nowx;
            else if (s[nowx][nowy] == 'R')
              ++nowy;
            else
              --nowy;
            if (nowx >= 0 && nowy >= 0 && nowx < n && nowy < m)
              cnt[nx][ny] = cnt[nowx][nowy] + 1;
            else
              cnt[nx][ny] = 1;
            was[preder[col - 1].first][preder[col - 1].second] = 1;
            --col;
          }
        }
        if (cnt[i][j] > cnt[ansx][ansy]) {
          ansx = i;
          ansy = j;
        }
      }
    }
    cout << ansx + 1 << ' ' << ansy + 1 << ' ' << cnt[ansx][ansy] << endl;
  }
  return 0;
}
