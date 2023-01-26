#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int MAXN = 1e6 + 1;
const int B = 8191;
int n, a[MAXN];
vector<pair<int, int> > q[MAXN];
int eachq[B + 1];
queue<int> app[5005];
int dp[5005][B + 1];
bool vis[B + 1];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i]), app[a[i]].push(i);
  for (int i = 0; i <= 5000; ++i) app[i].push(INF);
  for (int i = 0; i <= 5000; ++i)
    for (int j = 0; j <= B; ++j) eachq[i ^ j] = i;
  memset(dp, 63, sizeof(dp));
  int cnt = 0;
  for (int i = 0; i <= 5000; ++i) {
    dp[i][i] = app[i].front();
    if (dp[i][i] != INF) {
      q[dp[i][i]].push_back(make_pair(i, i));
      cnt += 1;
      vis[i] = 1;
    }
  }
  for (int t = 1; t <= n; ++t) {
    for (auto it : q[t]) {
      while (eachq[it.second] != -1 && eachq[it.second] > it.first) {
        int Tmp_ = eachq[it.second]--;
        auto Tmp = make_pair(Tmp_, it.second ^ Tmp_);
        while (app[Tmp.first].front() <= t) app[Tmp.first].pop();
        if (app[Tmp.first].front() != INF) {
          cnt += vis[Tmp.second] == 0;
          vis[Tmp.second] = 1;
          if (cnt == B + 1) break;
          dp[Tmp.first][Tmp.second] = app[Tmp.first].front();
          q[dp[Tmp.first][Tmp.second]].push_back(Tmp);
        }
      }
    }
  }
  vector<int> ans;
  ans.push_back(0);
  for (int i = 1; i <= B; ++i) {
    if (vis[i]) ans.push_back(i);
  }
  printf("%d\n", int(ans.size()));
  for (auto it : ans) printf("%d ", it);
  return 0;
}
