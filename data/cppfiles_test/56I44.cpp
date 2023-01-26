#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
const long long K_MAX = 1 << 6;
long long dp[K_MAX][8];
unordered_map<string, int> mpcolors = {
    {"white", 0}, {"green", 1},  {"red", 2},
    {"blue", 3},  {"yellow", 4}, {"orange", 5},
};
bool bad[6][6] = {{1, 0, 0, 0, 1, 0}, {0, 1, 0, 1, 0, 0}, {0, 0, 1, 0, 0, 1},
                  {0, 1, 0, 1, 0, 0}, {1, 0, 0, 0, 1, 0}, {0, 0, 1, 0, 0, 1}};
unordered_map<long long, int> selected_colors;
map<pair<long long, int>, long long> long_dp;
long long dfs(long long id, long long k, int color,
              unordered_set<long long>& nodes) {
  pair<long long, int> long_key = {id, color};
  if (long_dp.count(long_key)) {
    return long_dp[long_key];
  }
  if (0 < selected_colors.count(id) && selected_colors[id] != color) {
    return 0;
  }
  if (nodes.count(id)) {
    nodes.erase(id);
  }
  if (nodes.size() == 0) {
    return dp[k][color];
  }
  unordered_set<long long> left_nodes;
  unordered_set<long long> right_nodes;
  for (auto& p : nodes) {
    int cnt = 0;
    long long temp = p;
    while ((temp >> 1) != id) {
      temp >>= 1;
      cnt++;
    }
    if (0 < ((p >> cnt) & 1)) {
      right_nodes.insert(p);
    } else {
      left_nodes.insert(p);
    }
  }
  long long l = 2 * id;
  long long r = 2 * id + 1;
  long long ans = 0;
  for (int cl = 0; cl < 6; ++cl) {
    if (bad[color][cl]) {
      continue;
    }
    for (int cr = 0; cr < 6; ++cr) {
      if (bad[color][cr]) {
        continue;
      }
      long long lcnt = dfs(l, k - 1, cl, left_nodes);
      long long rcnt = dfs(r, k - 1, cr, right_nodes);
      ans = (ans + lcnt * rcnt % MOD) % MOD;
    }
  }
  return long_dp[long_key] = ans;
}
void solve() {
  long long k = 0;
  cin >> k;
  int n = 0;
  cin >> n;
  unordered_set<long long> nodes;
  for (int i = 0; i < n; ++i) {
    long long id;
    cin >> id;
    string color;
    cin >> color;
    nodes.insert(id);
    selected_colors[id] = mpcolors[color];
  }
  for (int i = 0; i < 6; ++i) {
    dp[1][i] = 1;
  }
  for (int ck = 2; ck <= k; ++ck) {
    for (int color = 0; color < 6; ++color) {
      dp[ck][color] = 0;
      for (int cl = 0; cl < 6; ++cl) {
        if (bad[color][cl]) {
          continue;
        }
        for (int cr = 0; cr < 6; ++cr) {
          if (bad[color][cr]) {
            continue;
          }
          dp[ck][color] =
              (dp[ck - 1][cl] * dp[ck - 1][cr] % MOD + dp[ck][color]) % MOD;
        }
      }
    }
  }
  long long ans = 0;
  for (int c = 0; c < 6; ++c) {
    ans = (ans + dfs(1, k, c, nodes));
  }
  cout << ans;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  while (t--) solve();
  return 0;
}
