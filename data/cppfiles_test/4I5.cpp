#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
const int N = 2e5 + 100;
const int MOD = 1e9 + 7;
int k, maxv, step = 0, ans = 0;
vector<int> lst;
int a[N], huprev[N], used[N], hap[N], col[N], sum[N];
vector<pair<int, int> > g[N];
int rmq_used[2][4 * N];
pair<int, int> rmq[2][4 * N];
void init() {}
void dfs1(int v, int pv, int cur_hap, int cur_col, int last_col, int cur_sum) {
  used[v] = step;
  huprev[v] = pv;
  hap[v] = cur_hap;
  col[v] = cur_col;
  sum[v] = cur_sum;
  if (pv != -1) {
    lst.push_back(v);
  }
  for (const pair<int, int>& e : g[v]) {
    if (used[e.first] != step) {
      if (cur_col == -1) {
        dfs1(e.first, (pv == -1 ? e.first : pv), (cur_hap + a[e.first]) % MOD,
             e.second, e.second, cur_sum);
      } else {
        dfs1(e.first, (pv == -1 ? e.first : pv), (cur_hap + a[e.first]) % MOD,
             cur_col, e.second, cur_sum + (e.second != last_col));
      }
    }
  }
}
pair<int, int> get(int c, int l, int r) {
  pair<int, int> res(0, 0);
  l += maxv;
  r += maxv;
  while (l <= r) {
    if (l % 2 != 0) {
      if (rmq_used[c][l] != step) {
        rmq[c][l] = make_pair(0, 0);
        rmq_used[c][l] = step;
      }
      res = make_pair((res.first + rmq[c][l].first) % MOD,
                      res.second + rmq[c][l].second);
    }
    l = (l + 1) / 2;
    if (r % 2 == 0) {
      if (rmq_used[c][r] != step) {
        rmq[c][r] = make_pair(0, 0);
        rmq_used[c][r] = step;
      }
      res = make_pair((res.first + rmq[c][r].first) % MOD,
                      res.second + rmq[c][r].second);
    }
    r = (r - 1) / 2;
  }
  return res;
}
void update(int c, int pos, pair<int, int> val) {
  pos += maxv;
  while (pos >= 1) {
    if (rmq_used[c][pos] != step) {
      rmq[c][pos] = make_pair(0, 0);
      rmq_used[c][pos] = step;
    }
    rmq[c][pos] = make_pair((rmq[c][pos].first + val.first) % MOD,
                            rmq[c][pos].second + val.second);
    pos /= 2;
  }
}
void solve(int v) {
  ++step;
  lst.clear();
  dfs1(v, -1, 0, -1, -1, 0);
  ans = (ans + a[v]) % MOD;
  int i = 0;
  while (i < ((int)(lst).size())) {
    int j = i;
    while (j + 1 < ((int)(lst).size()) &&
           huprev[lst[i]] == huprev[lst[j + 1]]) {
      ++j;
    }
    for (int z = i; z <= j; ++z) {
      if (sum[lst[z]] <= k) {
        ans = (ans + hap[lst[z]] + a[v]) % MOD;
      }
      pair<int, int> res = get(col[lst[z]], 0, k - sum[lst[z]]);
      ans = (ans + res.first + ll(res.second) * (a[v] + hap[lst[z]])) % MOD;
      res = get(col[lst[z]] ^ 1, 0, k - sum[lst[z]] - 1);
      ans = (ans + res.first + ll(res.second) * (a[v] + hap[lst[z]])) % MOD;
    }
    for (int z = i; z <= j; ++z) {
      update(col[lst[z]], sum[lst[z]], make_pair(hap[lst[z]], 1));
    }
    i = j + 1;
  }
  for (const pair<int, int>& e : g[v]) {
    g[e.first].erase(
        find((g[e.first]).begin(), (g[e.first]).end(), make_pair(v, e.second)));
    solve(e.first);
  }
}
void solve() {
  int n;
  scanf("%d %d", &n, &k);
  for (int i = 0; i < n; ++i) {
    scanf("%d", a + i);
  }
  for (int i = 0; i < n - 1; ++i) {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    --a;
    --b;
    g[a].push_back(make_pair(b, c));
    g[b].push_back(make_pair(a, c));
  }
  maxv = 1;
  while (maxv < n) {
    maxv *= 2;
  }
  solve(0);
  printf("%d\n", ans);
}
int main() {
  init();
  int t = 1;
  for (int i = 0; i < t; ++i) {
    solve();
  }
  return 0;
}
