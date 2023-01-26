#include <bits/stdc++.h>
using namespace std;
int n, m;
void visit(vector<string> &b, vector<vector<int> > &dp) {
  vector<vector<int> > visited(n, vector<int>(m, 0));
  stack<pair<int, int> > st, temp;
  for (int k = 0; k < n; k++) {
    for (int l = 0; l < m; l++) {
      int i = k, j = l, d = 0;
      while (1) {
        if (dp[k][l] != -1) {
          break;
        }
        if (i >= n || i < 0 || j >= m || j < 0) {
          d = 1;
          while (!st.empty()) {
            dp[st.top().first][st.top().second] = d;
            st.pop();
            d++;
          }
          break;
        } else if (dp[i][j] != -1) {
          d = dp[i][j];
          while (!st.empty()) {
            d++;
            dp[st.top().first][st.top().second] = d;
            st.pop();
          }
          break;
        }
        if (visited[i][j]) {
          d = 1;
          while (st.top() != make_pair(i, j)) {
            temp.push({st.top().first, st.top().second});
            if (!st.empty()) st.pop();
            d++;
          }
          temp.push(st.top());
          st.pop();
          while (!temp.empty()) {
            dp[temp.top().first][temp.top().second] = d;
            temp.pop();
          }
          while (!st.empty()) {
            d++;
            dp[st.top().first][st.top().second] = d;
            st.pop();
          }
          break;
        }
        visited[i][j] = 1;
        st.push({i, j});
        if (b[i][j] == 'R') {
          j++;
        } else if (b[i][j] == 'L') {
          j--;
        } else if (b[i][j] == 'U') {
          i--;
        } else {
          i++;
        }
        d++;
      }
    }
  }
}
void solve() {
  cin >> n >> m;
  vector<string> b(n);
  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }
  vector<vector<int> > dp(n, vector<int>(m, -1));
  visit(b, dp);
  int r, c, d = INT_MIN;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int t = dp[i][j];
      if (t > d) {
        d = t;
        r = i + 1;
        c = j + 1;
      }
    }
  }
  cout << r << " " << c << " " << d << endl;
}
int main() {
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
