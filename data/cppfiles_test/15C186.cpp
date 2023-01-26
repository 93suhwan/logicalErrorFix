#include <bits/stdc++.h>
using namespace std;
void fastIO() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
}
vector<int> edge[110];
int dist[110];
const long long MOD = 1e9 + 7;
int cnt[110][110];
long long dp[110][110][110];
void dfs(int node, int pa = 0) {
  for (int nx : edge[node]) {
    if (nx == pa) continue;
    dist[nx] = dist[node] + 1;
    dfs(nx, node);
  }
}
int main() {
  fastIO();
  int T;
  cin >> T;
  while (T--) {
    int N, K;
    cin >> N >> K;
    for (int i = 1; i <= N; i++) edge[i].clear();
    for (int i = 1; i <= N - 1; i++) {
      int a, b;
      cin >> a >> b;
      edge[a].push_back(b);
      edge[b].push_back(a);
    }
    if (K == 2) {
      cout << (long long)N * (N - 1) / 2 << "\n";
      continue;
    }
    long long tot = 0;
    for (int i = 1; i <= N; i++) {
      for (int j = 0; j < (int)edge[i].size(); j++) {
        for (int k = 0; k <= N; k++) {
          cnt[j][k] = 0;
          dist[k] = 0;
        }
        dist[edge[i][j]] = 1;
        dfs(edge[i][j], i);
        for (int k = 1; k <= N; k++) {
          cnt[j][dist[k]]++;
        }
      }
      for (int j = 0; j <= (int)edge[i].size(); j++) {
        for (int k = 0; k <= K; k++) {
          for (int l = 0; l <= N; l++) {
            dp[j][k][l] = 0;
          }
        }
        for (int l = 0; l <= N; l++) {
          dp[j][0][l] = 1;
        }
      }
      for (int j = 1; j <= (int)edge[i].size(); j++) {
        for (int k = 1; k <= K; k++) {
          for (int l = 1; l <= N; l++) {
            dp[j][k][l] =
                dp[j - 1][k - 1][l] * cnt[j - 1][l] % MOD + dp[j - 1][k][l];
            dp[j][k][l] %= MOD;
          }
        }
      }
      for (int l = 1; l <= N; l++) {
        tot += dp[(int)edge[i].size()][K][l];
        tot %= MOD;
      }
    }
    cout << tot << "\n";
  }
}
