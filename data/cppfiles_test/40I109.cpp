#include <bits/stdc++.h>
using namespace std;
const int max_n = 3e5 + 10, inf = 1000111222;
vector<int> reb[max_n];
int p[max_n];
bool used[max_n];
int tin[max_n];
int tout[max_n];
int T;
bool is_pred(int u, int v) { return tin[u] <= tin[v] && tin[v] <= tout[u]; }
map<pair<int, int>, bool> edge_from_tree;
void dfs(int now, int pred) {
  tin[now] = ++T;
  p[now] = pred;
  used[now] = 1;
  for (auto wh : reb[now]) {
    if (!used[wh]) {
      edge_from_tree[make_pair(now, wh)] = 1;
      edge_from_tree[make_pair(wh, now)] = 1;
      dfs(wh, now);
    }
  }
  tout[now] = T;
}
int ans[max_n];
vector<int> answers[max_n];
int lol[max_n];
vector<int> reb1[max_n];
int deg[max_n];
int pp2[max_n];
void dfs2(int now, int pred) {
  pp2[now] = pred;
  used[now] = 1;
  for (auto wh : reb1[now]) {
    if (!used[wh]) {
      deg[now]++;
      dfs2(wh, now);
    }
  }
}
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    reb[u].push_back(v);
    reb[v].push_back(u);
  }
  dfs(1, -1);
  int q;
  scanf("%d", &q);
  for (int i = 0; i < q; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    auto mark_ans = [&](int a) {
      while (a != 1) {
        ans[a] ^= 1;
        a = p[a];
      }
    };
    mark_ans(u);
    mark_ans(v);
    vector<int> cur_ans;
    while (!is_pred(u, v)) {
      cur_ans.push_back(u);
      u = p[u];
    }
    cur_ans.push_back(u);
    vector<int> ans_2;
    while (v != u) {
      ans_2.push_back(v);
      v = p[v];
    }
    reverse(ans_2.begin(), ans_2.end());
    for (auto j : ans_2) {
      cur_ans.push_back(j);
    }
    answers[i] = cur_ans;
  }
  int ans_no = 0;
  for (int now = 1; now <= n; now++) {
    for (int wh : reb[now]) {
      if (now < wh && edge_from_tree.count(make_pair(now, wh)) &&
          ((is_pred(now, wh) && ans[wh] == 1) ||
           (is_pred(wh, now) && ans[now] == 1))) {
        reb1[now].push_back(wh);
        reb1[wh].push_back(now);
      }
    }
  }
  queue<int> qq;
  memset(used, 0, sizeof(used));
  for (int i = 1; i <= n; i++) {
    if (!reb1[i].empty() && !used[i]) {
      dfs2(i, -1);
    }
  }
  for (int i = 1; i <= n; i++) {
    if (!reb1[i].empty() && deg[i] == 0) {
      qq.push(i);
    }
  }
  while (!qq.empty()) {
    int now = qq.front();
    qq.pop();
    int to = pp2[now];
    if (to != -1) {
      if (lol[now] == 0) {
        ans_no++;
      }
      deg[to]--;
      if (deg[to] == 0) {
        qq.push(to);
      }
      lol[to] ^= 1;
    }
  }
  if (ans_no) {
    cout << "NO"
         << "\n";
    cout << ans_no << "\n";
  } else {
    cout << "YES"
         << "\n";
    for (int i = 0; i < q; i++) {
      cout << (int)(answers[i].size()) << "\n";
      for (auto j : answers[i]) {
        cout << j << " ";
      }
      cout << "\n";
    }
  }
}
