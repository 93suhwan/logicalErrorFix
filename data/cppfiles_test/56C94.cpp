#include <bits/stdc++.h>
using namespace std;
const int maxnk = 60 * 2000 + 10;
const int maxn = 2010;
const long long mod = 1e9 + 7;
const map<string, int> M = {{"white", 0}, {"yellow", 1}, {"red", 2},
                            {"blue", 3},  {"orange", 4}, {"green", 5}};
const int G[6][4] = {{2, 3, 4, 5}, {2, 3, 4, 5}, {0, 1, 3, 5},
                     {0, 1, 2, 4}, {0, 1, 3, 5}, {0, 1, 2, 4}};
map<long long, int> id;
int tot_id;
vector<int> H[maxnk];
long long dp[maxnk][6];
long long lim[maxnk];
void dfs(int u) {
  for (auto v : H[u]) {
    dfs(v);
  }
  if (lim[u] == -1) {
    for (int i = 0; i < 6; i++) {
      long long mul = 1;
      for (auto v : H[u]) {
        long long sum = 0;
        for (auto it : G[i]) {
          sum += dp[v][it];
          sum %= mod;
        }
        mul *= sum;
        mul %= mod;
      }
      dp[u][i] += mul;
      dp[u][i] %= mod;
    }
  } else {
    dp[u][lim[u]] = 1;
    for (auto v : H[u]) {
      long long sum = 0;
      for (auto it : G[lim[u]]) {
        sum += dp[v][it];
        sum %= mod;
      }
      dp[u][lim[u]] *= sum;
      dp[u][lim[u]] %= mod;
    }
  }
}
long long fpow(long long a, long long b, long long mod) {
  long long res = 1;
  a %= mod;
  for (; b; b >>= 1) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
  }
  return res;
}
int main() {
  int k, n;
  cin >> k >> n;
  int id_rt = -1;
  memset(lim, 0xff, sizeof(lim));
  for (int i = 0; i < n; i++) {
    long long p;
    string s;
    cin >> p >> s;
    if (id.count(p)) {
      lim[id[p]] = M.at(s);
      continue;
    }
    id[p] = ++tot_id;
    if (p == 1) id_rt = id[p];
    lim[id[p]] = M.at(s);
    for (; p >> 1; p >>= 1) {
      if (id.count(p >> 1)) {
        H[id[p >> 1]].push_back(id[p]);
        break;
      }
      id[p >> 1] = ++tot_id;
      H[id[p >> 1]].push_back(id[p]);
      if ((p >> 1) == 1) {
        id_rt = id[p >> 1];
      }
    }
  }
  dfs(id_rt);
  long long sum = 0;
  for (int i = 0; i < 6; i++) {
    sum += dp[id_rt][i];
    sum %= mod;
  }
  long long other = fpow(4, (1LL << k) - 1 - id.size(), mod);
  long long ans = sum * other % mod;
  printf("%lld\n", ans);
  return 0;
}
