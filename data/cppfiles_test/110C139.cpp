#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
struct node {
  bool friend operator<(node n1, node n2) {
    if (n1.val == n2.val) {
      return n1.id > n2.id;
    } else {
      return n1.val > n2.val;
    }
  }
  int id, val;
};
priority_queue<node> que;
vector<int> pre[maxn];
int degree[maxn];
int n;
int solve() {
  node cur, tmp;
  int i, res, cnt, u, v;
  while (!que.empty()) {
    que.pop();
  }
  res = 0, cnt = 0;
  for (i = 1; i <= n; i++) {
    if (degree[i] == 0) {
      tmp.id = i, tmp.val = 1;
      que.push(tmp);
      res = max(res, tmp.val), cnt++;
    }
  }
  while (!que.empty()) {
    cur = que.top();
    que.pop();
    u = cur.id;
    for (i = 0; i < pre[u].size(); i++) {
      v = pre[u][i];
      degree[v]--;
      if (degree[v] == 0) {
        tmp.id = v;
        if (v < u)
          tmp.val = cur.val + 1;
        else
          tmp.val = cur.val;
        que.push(tmp);
        res = max(res, tmp.val), cnt++;
      }
    }
  }
  if (cnt < n)
    return -1;
  else
    return res;
}
int main() {
  int t, i, j, k;
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    for (i = 1; i <= n; i++) {
      pre[i].clear();
      degree[i] = 0;
    }
    for (i = 1; i <= n; i++) {
      scanf("%d", &k);
      while (k--) {
        scanf("%d", &j);
        pre[j].push_back(i);
        degree[i]++;
      }
    }
    printf("%d\n", solve());
  }
  return 0;
}
