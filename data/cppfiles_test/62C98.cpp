#include <bits/stdc++.h>
using namespace std;
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  long long T, a, b, c, d, n, m, q;
  std::cin >> n >> m >> q;
  std::vector<vector<bool>> state(n, vector<bool>(m, false));
  long long poss = 2 * m - 1;
  std::vector<int> dp(m, 2);
  dp[0] = 1;
  std::vector<int> newDp(m);
  for (int i = 1; i < n; i++) {
    newDp[0] = 1;
    poss += 1;
    for (int j = 1; j < m; j++) {
      newDp[j] = dp[j - 1] + 2;
      poss += dp[j - 1] * 2 + 2;
    }
    poss += dp[m - 1];
    swap(dp, newDp);
  }
  for (int i = 0; i < q; i++) {
    std::cin >> a >> b;
    a--;
    b--;
    long long dir = -1;
    if (state[a][b]) {
      dir = 1;
    }
    state[a][b] = !state[a][b];
    valarray<long long> start[] = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
    long long results[] = {0, 0, 0, 0};
    for (int j = 0; j < 4; j++) {
      long long temp[2] = {a, b};
      std::valarray<long long> cur(temp, 2);
      int index = j;
      cur += start[index];
      index = 3 - index;
      while (cur[0] >= 0 && cur[1] >= 0 && cur[0] < n && cur[1] < m &&
             state[cur[0]][cur[1]] == false) {
        results[j]++;
        cur += start[index];
        index = 3 - index;
      }
    }
    poss += results[0] * results[2] * dir;
    poss += results[1] * results[3] * dir;
    poss += results[0] * dir;
    poss += results[1] * dir;
    poss += results[2] * dir;
    poss += results[3] * dir;
    poss += dir;
    cout << poss << endl;
  }
}
