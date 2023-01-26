#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  int a[n + 1];
  int b[n + 1];
  memset(a, 0, sizeof a);
  memset(b, 0, sizeof b);
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= n; i++) cin >> b[i];
  int cost[n + 1];
  int par[n + 1];
  memset(cost, 0, sizeof cost);
  memset(par, -1, sizeof par);
  set<int> s;
  for (int i = 0; i <= n; i++) s.insert(i);
  vector<int> temp;
  queue<int> q;
  q.push(n);
  while (q.size()) {
    int curNode = q.front();
    q.pop();
    int tempCurNode = curNode + b[curNode];
    auto idx = s.lower_bound(tempCurNode - a[tempCurNode]);
    vector<int> temp;
    while (idx != s.end() && *idx < tempCurNode) {
      temp.push_back(*idx);
      par[*idx] = curNode;
      cost[*idx] = cost[curNode] + 1;
      q.push(*idx);
      idx++;
    }
    for (auto x : temp) s.erase(x);
  }
  if (cost[0] == 0) {
    cout << "-1" << endl;
    return;
  }
  cout << cost[0] << endl;
  int idx = 0;
  vector<int> ans;
  while (idx != n) {
    ans.push_back(idx);
    idx = par[idx];
  }
  reverse(ans.begin(), ans.end());
  for (auto x : ans) cout << x << " ";
  cout << endl;
}
int main() { solve(); }
