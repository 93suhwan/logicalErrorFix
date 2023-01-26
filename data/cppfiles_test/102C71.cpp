#include <bits/stdc++.h>
using namespace std;
const long long MOD = 998244353;
map<long long, vector<pair<int, int>>> mp[2][2];
int k, flag, vis[100];
long long a, h, A[100];
vector<int> v[10];
inline bool getbit(int x, int pos) { return (x >> pos) & 1; }
inline void init(int n) {
  A[0] = 1;
  for (int i = 1; i <= n; i++) A[i] = A[i - 1] * a % MOD;
}
inline long long cal(vector<pair<int, int>>& tmp) {
  long long ans = 0;
  for (auto c : tmp) ans += (long long)c.first * A[c.second] % MOD, ans %= MOD;
  return ans;
}
void dfs(int plen, int rd) {
  if (plen == 1) {
    vector<pair<int, int>> tmp;
    tmp.push_back({v[rd - 1][0], 1});
    int cnt = 2;
    vis[v[rd - 1][0]] = 1;
    for (int i = rd - 2; i >= 0; i--) {
      int t = cnt;
      for (auto c : v[i]) {
        if (vis[c]) continue;
        t += 2, vis[c] = 1;
        tmp.push_back({c, cnt + 1});
      }
      cnt = t;
    }
    for (auto c : v[0]) vis[c] = 0;
    mp[flag][0][cal(tmp)] = tmp;
    tmp[0].second++, mp[flag][1][cal(tmp)] = tmp;
    return;
  }
  for (int j = 0; j < (1 << (plen >> 1)); j++) {
    for (int i = 0; i < plen; i += 2)
      v[rd].push_back(v[rd - 1][i + getbit(j, i / 2)]);
    dfs(plen >> 1, rd + 1);
    v[rd].clear();
  }
}
inline void solve() {
  cin >> k >> a >> h;
  init(1 << k);
  for (int i = 1; i <= (1 << (k - 1)); i++) v[0].push_back(i);
  dfs(1 << (k - 1), 1);
  flag = !flag, v[0].clear();
  assert(v[1].size() == 0);
  for (int i = (1 << (k - 1)) + 1; i <= (1 << k); i++) v[0].push_back(i);
  dfs(1 << (k - 1), 1);
  vector<pair<int, int>> ans;
  for (int i = 0; i <= 1; i++) {
    int x1 = getbit(i, 0), x2 = getbit(i, 1);
    for (auto c : mp[x1][x2]) {
      long long t = (h - c.first + MOD) % MOD;
      if (mp[!x1][!x2].count(t)) {
        for (auto d : c.second) ans.push_back(d);
        for (auto d : mp[!x1][!x2][t]) ans.push_back(d);
        sort(ans.begin(), ans.end());
        for (auto d : ans) cout << d.second << " ";
        cout << "\n";
        return;
      }
    }
  }
  cout << "-1\n";
  return;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  solve();
  return 0;
}
