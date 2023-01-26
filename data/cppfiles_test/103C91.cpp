#include <bits/stdc++.h>
using namespace std;
int n, m;
const int NMAX(2005);
inline int conv(int i, int j) { return (i - 1) * m + j; }
pair<int, int> goBack(int val) {
  int i = val / m, j = -1;
  if (val % m == 0)
    j = m;
  else {
    j = val - i * m;
    ++i;
  }
  return {i, j};
}
pair<int, int> goTo[NMAX][NMAX];
int viz[NMAX][NMAX];
int dp[NMAX][NMAX], isCycle[NMAX][NMAX];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> n >> m;
    for (int i = 0; i <= n + 1; ++i)
      for (int j = 0; j <= m + 1; ++j)
        goTo[i][j] = {-1, -1}, dp[i][j] = isCycle[i][j] = 0, viz[i][j] = 0;
    for (int i = 1; i <= n; ++i) {
      string s;
      cin >> s;
      for (int j = 1; j <= m; ++j) {
        if (s[j - 1] == 'L' && j - 1 >= 1)
          goTo[i][j] = {i, j - 1};
        else if (s[j - 1] == 'R' && j + 1 <= m)
          goTo[i][j] = {i, j + 1};
        else if (s[j - 1] == 'U' && i - 1 >= 1)
          goTo[i][j] = {i - 1, j};
        else if (s[j - 1] == 'D' && i + 1 <= n)
          goTo[i][j] = {i + 1, j};
      }
    }
    int nr = 0;
    stack<int> st;
    for (int i = 1; i <= n; ++i)
      for (int j = 1; j <= m; ++j)
        if (viz[i][j] == 0) {
          ++nr;
          st.push(conv(i, j));
          viz[i][j] = nr;
          bool ok = 0;
          int curX = i, curY = j;
          while (goTo[curX][curY].first != -1) {
            int aX = curX, aY = curY;
            curX = goTo[aX][aY].first;
            curY = goTo[aX][aY].second;
            if (viz[curX][curY]) {
              if (viz[curX][curY] == nr) ok = 1;
              break;
            }
            viz[curX][curY] = nr;
            st.push(conv(curX, curY));
          }
          if (ok) {
            stack<int> aux;
            while (!st.empty()) {
              pair<int, int> cur = goBack(st.top());
              aux.push(st.top());
              if (cur.first != curX || cur.second != curY)
                ;
              else
                break;
              st.pop();
            }
            int lg = aux.size();
            while (!aux.empty()) {
              pair<int, int> cur = goBack(aux.top());
              isCycle[cur.first][cur.second] = lg;
              aux.pop();
            }
          }
          while (!st.empty()) st.pop();
        }
    for (int i = 0; i <= n + 1; ++i)
      for (int j = 0; j <= m + 1; ++j) viz[i][j] = 0;
    while (!st.empty()) st.pop();
    for (int i = 1; i <= n; ++i)
      for (int j = 1; j <= m; ++j)
        if (!viz[i][j]) {
          if (isCycle[i][j]) {
            dp[i][j] = isCycle[i][j];
            continue;
          }
          st.push(conv(i, j));
          viz[i][j] = 1;
          int curX = i, curY = j;
          while (goTo[curX][curY].first != -1) {
            int aX = curX, aY = curY;
            curX = goTo[aX][aY].first;
            curY = goTo[aX][aY].second;
            if (isCycle[curX][curY]) {
              dp[curX][curY] = isCycle[curX][curY];
              break;
            }
            if (viz[curX][curY] == 1) break;
            viz[curX][curY] = 1;
            st.push(conv(curX, curY));
          }
          while (!st.empty()) {
            pair<int, int> cur = goBack(st.top());
            dp[cur.first][cur.second] = dp[goTo[cur.first][cur.second].first]
                                          [goTo[cur.first][cur.second].second] +
                                        1;
            st.pop();
          }
        }
    int maxx = 0, curX = 0, curY = 0;
    for (int i = 1; i <= n; ++i)
      for (int j = 1; j <= m; ++j)
        if (dp[i][j] > maxx) {
          maxx = dp[i][j];
          curX = i, curY = j;
        }
    cout << curX << ' ' << curY << ' ' << maxx << '\n';
  }
  return 0;
}
