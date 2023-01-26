#include <bits/stdc++.h>
using namespace std;
vector<int> a[15];
int n, m;
set<vector<int> > set1;
set<vector<int> > set2;
struct Node {
  vector<int> v;
  int sum;
  bool operator<(const Node& rhs) const { return sum < rhs.sum; }
};
void solve() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    int t, t1;
    scanf("%d", &t);
    a[i].push_back(0);
    for (int j = 0; j < t; j++) {
      scanf("%d", &t1);
      a[i].push_back(t1);
    }
  }
  scanf("%d", &m);
  for (int i = 0; i < m; i++) {
    vector<int> v;
    int t;
    for (int j = 0; j < n; j++) {
      scanf("%d", &t);
      v.push_back(t);
    }
    set1.insert(v);
  }
  priority_queue<Node> q;
  Node t2;
  t2.sum = 0;
  t2.v.clear();
  for (int i = 1; i <= n; i++) {
    t2.v.push_back(a[i].size() - 1);
    t2.sum += a[i][a[i].size() - 1];
  }
  q.push(t2);
  set2.insert(t2.v);
  vector<int> ans;
  while (!q.empty()) {
    Node n1 = q.top();
    q.pop();
    if (set1.find(n1.v) == set1.end()) {
      ans = n1.v;
      break;
    }
    for (int i = 1; i <= n; i++) {
      Node n2 = n1;
      if (n2.v[i - 1] >= 2) {
        int t = n2.v[i - 1];
        n2.sum = n2.sum + a[i][t - 1] - a[i][t];
        n2.v[i - 1] = t - 1;
        if (set2.find(n2.v) == set2.end()) {
          q.push(n2);
          set2.insert(n2.v);
        }
      }
    }
  }
  for (int i = 0; i < ans.size(); i++) printf("%d ", ans[i]);
  printf("\n");
}
int main() {
  solve();
  return 0;
}
