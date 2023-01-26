#include <bits/stdc++.h>
using namespace std;
void err(istream_iterator<string> it) {}
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
  cout << *it << " = " << a << "    ";
  err(++it, args...);
}
const int MOD = 1e9 + 7;
map<char, int> ind;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int n, m;
bool isValid(int x, int y) {
  if (x >= 0 and x < n and y >= 0 and y < m) return true;
  return false;
}
void solve() {
  cin >> n >> m;
  ind['U'] = 0;
  ind['R'] = 1;
  ind['D'] = 2;
  ind['L'] = 3;
  string s[n];
  for (int i = 0; i < n; i++) cin >> s[i];
  int v[n][m], dp[n][m];
  memset(v, 0, sizeof(v));
  memset(dp, 0, sizeof(dp));
  int ans = 0, fx, fy;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (v[i][j]) continue;
      int cnt = 0;
      int x = i, y = j, fk = 0;
      set<pair<int, int>> st;
      vector<pair<int, int>> temp;
      while (isValid(x, y)) {
        cnt++;
        int p = ind[s[x][y]];
        v[x][y] = 1;
        st.insert({x, y});
        temp.push_back({x, y});
        x += dx[p];
        y += dy[p];
        if (isValid(x, y) and v[x][y]) {
          if (st.find({x, y}) != st.end()) {
            int pp = 0;
            vector<pair<int, int>> temp2;
            while (1) {
              pp++;
              temp2.push_back(temp.back());
              temp.pop_back();
              if (temp2.back() == make_pair(x, y)) break;
            }
            for (auto [xx, yy] : temp2) dp[xx][yy] = pp;
            while (!temp.empty()) {
              dp[temp.back().first][temp.back().second] = ++pp;
              temp.pop_back();
            }
            break;
          } else {
            int pp = dp[x][y];
            while (!temp.empty()) {
              dp[temp.back().first][temp.back().second] = ++pp;
              temp.pop_back();
            }
            break;
          }
        } else if (!isValid(x, y)) {
          int pp = 0;
          while (!temp.empty()) {
            dp[temp.back().first][temp.back().second] = ++pp;
            temp.pop_back();
          }
          break;
        }
      }
      if (dp[i][j] > ans) {
        fx = i;
        fy = j;
        ans = dp[i][j];
      }
    }
  }
  cout << fx + 1 << " " << fy + 1 << " " << ans << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  int tt;
  cin >> tt;
  while (tt--) solve();
}
