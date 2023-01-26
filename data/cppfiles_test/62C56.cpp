#include <bits/stdc++.h>
using namespace std;
template <typename __T1, typename __T2>
ostream &operator<<(ostream &out, pair<__T1, __T2> &__VAR) {
  cout << "[" << __VAR.first << ", " << __VAR.second << "]";
  return out;
}
template <typename __T>
ostream &operator<<(ostream &out, vector<__T> &__VAR) {
  cout << "[";
  for (int i = 0; i <= (int)__VAR.size() - 2; i++) cout << __VAR[i] << ", ";
  if (__VAR.size() > 0) cout << __VAR[__VAR.size() - 1];
  cout << "]" << endl;
  return out;
}
const int INF = 1e9;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int N, M, Q;
  cin >> N >> M >> Q;
  vector<vector<vector<long long>>> dp(
      N, vector<vector<long long>>(M, vector<long long>(2, 0)));
  long long result = 0;
  for (int i = N - 1; i >= 0; i--) {
    for (int j = M - 1; j >= 0; j--) {
      dp[i][j][0] = dp[i][j][1] = 1;
      if (i + 1 < N) {
        dp[i][j][0] += dp[i + 1][j][1];
      }
      if (j + 1 < M) {
        dp[i][j][1] += dp[i][j + 1][0];
      }
      result += dp[i][j][0] + dp[i][j][1];
    }
  }
  vector<vector<bool>> block(N, vector<bool>(M, false));
  long long cnt = N * M;
  while (Q--) {
    int x, y;
    cin >> y >> x;
    x--, y--;
    vector<int> dx = {1, 0};
    vector<int> dy = {0, 1};
    auto update = [&](int i, int j, int it) {
      while (i >= 0 && j >= 0) {
        result -= dp[i][j][0] + dp[i][j][1];
        int xx = dx[it], yy = dy[it];
        it = 1 - it;
        dp[i][j][0] = dp[i][j][1] = 1;
        if (i + 1 < N && !block[i + 1][j]) {
          dp[i][j][0] += dp[i + 1][j][1];
        }
        if (j + 1 < M && !block[i][j + 1]) {
          dp[i][j][1] += dp[i][j + 1][0];
        }
        if (block[i][j]) {
          dp[i][j][0] = dp[i][j][1] = 0;
        }
        result += dp[i][j][0] + dp[i][j][1];
        i -= yy;
        j -= xx;
      }
    };
    if (block[y][x]) {
      cnt++;
      block[y][x] = false;
      update(y, x, 0);
      update(y, x, 1);
    } else {
      cnt--;
      block[y][x] = true;
      update(y, x, 0);
      update(y, x, 1);
    }
    cout << result - cnt << '\n';
  }
  return 0;
}
