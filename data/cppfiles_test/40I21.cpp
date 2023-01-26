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
int dfs2(int now) {
  used[now] = 1;
  int res = 0;
  int potential_go = 0;
  for (auto wh : reb[now]) {
    if (edge_from_tree.count(make_pair(now, wh)) &&
        ((is_pred(now, wh) && ans[wh] == 1) ||
         (is_pred(wh, now) && ans[now] == 1))) {
      potential_go++;
      if (!used[wh]) {
        res += dfs2(wh);
      }
    }
  }
  res += (potential_go == 1);
  return res;
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
  memset(used, 0, sizeof(used));
  for (int i = 1; i <= n; i++) {
    if (ans[i] != 0 && !used[i]) {
      int cur_leafs = dfs2(i);
      ans_no += (cur_leafs + 1) / 2;
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
