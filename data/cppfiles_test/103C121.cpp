#include <bits/stdc++.h>
using namespace std;
long long int mod = 1e9 + 7;
int mx = 1e7 + 1;
string second[2000];
int cm = 0, cy = 0;
pair<int, int> ed;
int n, m;
int dist[2000][2000];
void dfs(pair<int, int> st) {
  dist[st.first][st.second] = ++cm;
  pair<int, int> x = {-1, -1};
  int i = st.first, j = st.second;
  if (second[i][j] == 'R') {
    if (j + 1 < m) x = {i, j + 1};
  } else if (second[i][j] == 'L') {
    if (j - 1 >= 0) x = {i, j - 1};
  } else if (second[i][j] == 'U') {
    if (i - 1 >= 0) x = {i - 1, j};
  } else {
    if (i + 1 < n) x = {i + 1, j};
  }
  if (x.first != -1) {
    if (!dist[x.first][x.second]) {
      dfs(x);
      if (cy) {
        dist[st.first][st.second] = dist[x.first][x.second];
        if (ed == st) cy = 0;
      } else {
        dist[st.first][st.second] = dist[x.first][x.second] - 1;
      }
    } else if (dist[x.first][x.second] < 0) {
      dist[st.first][st.second] = dist[x.first][x.second] - 1;
    } else {
      int cl = dist[st.first][st.second] - dist[x.first][x.second] + 1;
      cy = 1;
      ed = x;
      dist[st.first][st.second] = -cl;
    }
  }
  if (x.first == -1) dist[st.first][st.second] = -1;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    cin >> n >> m;
    int mx = 0, ax, ay;
    for (int i = 0; i < n; i++) {
      cin >> second[i];
      for (int j = 0; j < m; j++) {
        dist[i][j] = 0;
      }
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (!dist[i][j]) {
          dfs({i, j});
          if (-dist[i][j] > mx) {
            mx = -dist[i][j];
            ax = i + 1, ay = j + 1;
          }
        }
      }
    }
    cout << ax << " " << ay << " " << mx << "\n";
  }
  return 0;
}
