#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e9 + 7;
const long long MOD = 998244353;
void solve() {
  long long n, m;
  cin >> n >> m;
  vector<string> arr(n);
  for (int i = 0; i < n; i++) cin >> arr[i];
  vector<vector<bool>> isVisited(n, vector<bool>(m, false));
  vector<vector<long long>> ans(n, vector<long long>(m, -1));
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < m; j++) {
      if (isVisited[i][j]) continue;
      long long curx = i, cury = j;
      vector<pair<long long, long long>> st;
      while (true) {
        if (curx < 0 || curx >= n || cury < 0 || cury >= m ||
            isVisited[curx][cury])
          break;
        isVisited[curx][cury] = true;
        st.push_back({curx, cury});
        if (arr[curx][cury] == 'L')
          cury--;
        else if (arr[curx][cury] == 'R')
          cury++;
        else if (arr[curx][cury] == 'U')
          curx--;
        else
          curx++;
      }
      if (curx < 0 || curx >= n || cury < 0 || cury >= m) {
        long long curlen = 0;
        while (!st.empty()) {
          ans[st.back().first][st.back().second] = curlen++;
          st.pop_back();
        }
      } else if (ans[curx][cury] != -1) {
        long long curlen = ans[curx][cury] + 1;
        while (!st.empty()) {
          ans[st.back().first][st.back().second] = curlen++;
          st.pop_back();
        }
      } else {
        long long curlen = st.size();
        curlen--;
        int k = 0;
        for (; k < st.size(); k++) {
          if (curx == st[k].first && cury == st[k].second) break;
          ans[st[k].first][st[k].second] = curlen--;
        }
        for (; k < st.size(); k++) {
          ans[st[k].first][st[k].second] = curlen;
        }
      }
    }
  }
  long long ansx = 0, ansy = 0, answer = ans[0][0];
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < m; j++) {
      if (ans[i][j] > answer) {
        answer = ans[i][j];
        ansx = i;
        ansy = j;
      }
    }
  }
  cout << ansx + 1 << " " << ansy + 1 << " " << answer + 1 << "\n";
  return;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
