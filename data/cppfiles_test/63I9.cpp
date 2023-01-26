#include <bits/stdc++.h>
using namespace std;
long long power(long long a, long long b) {
  long long c, d;
  if (b == 1) {
    return a % 1000000007;
  } else if (b % 2 == 0) {
    c = power(a, b / 2);
    return (c * c) % 1000000007;
  } else {
    c = power(a, b / 2);
    d = (c * c) % 1000000007;
    d = (d * a) % 1000000007;
    return d;
  }
}
void ha() { printf("YES\n"); }
void na() { printf("NO\n"); }
void dfs(vector<vector<int> > &adj, vector<int> &vis, int con, int strt) {
  if (vis[strt]) {
    return;
  } else {
    vis[strt] = con;
    for (int i = 0; i < adj[strt].size(); i++) {
      dfs(adj, vis, con, adj[strt][i]);
    }
  }
}
int main() {
  int n, m1, m2;
  scanf("%d %d %d", &n, &m1, &m2);
  vector<int> vis1(n);
  vector<int> vis2(n);
  vector<vector<int> > adj1(n);
  vector<vector<int> > adj2(n);
  int i, j, k;
  for (i = 0; i < n; i++) {
    vis1[i] = 0;
    vis2[i] = 0;
  }
  for (i = 0; i < m1; i++) {
    scanf("%d %d", &j, &k);
    adj1[j - 1].push_back(k - 1);
    adj1[k - 1].push_back(j - 1);
  }
  for (i = 0; i < m2; i++) {
    scanf("%d %d", &j, &k);
    adj2[j - 1].push_back(k - 1);
    adj2[k - 1].push_back(j - 1);
  }
  int con_comp = 0;
  for (i = 0; i < n; i++) {
    if (vis1[i] == 0) {
      con_comp++;
      dfs(adj1, vis1, con_comp, i);
    }
  }
  con_comp = 0;
  for (i = 0; i < n; i++) {
    if (vis2[i] == 0) {
      con_comp++;
      dfs(adj2, vis2, con_comp, i);
    }
  }
  vector<pair<int, int> > ans;
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      if ((vis1[i] != vis1[j]) && (vis2[i] != vis2[j])) {
        ans.push_back(make_pair(i, j));
      }
    }
  }
  printf("%d\n", ans.size());
  for (i = 0; i < ans.size(); i++) {
    printf("%d %d\n", ans[i].first + 1, ans[i].second + 1);
  }
  return 0;
}
