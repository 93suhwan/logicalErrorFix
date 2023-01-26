#include <bits/stdc++.h>
using namespace std;
typedef struct _node {
  int pa;
  bool plus;
  int x;
  int y;
} node;
void solve() {
  int n;
  cin >> n;
  vector<node> nodes;
  vector<int> valid_nodes;
  vector<int> arr;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    arr.push_back(x);
    if (i == 0) {
      node start{-1, false, -x, -0x7f7f7f7f};
      nodes.push_back(start);
      valid_nodes.push_back(0);
      continue;
    }
    vector<int> next_valid;
    for (int idx : valid_nodes)
      for (int s = 0; s <= 1; s++) {
        int val = s ? x : -x;
        node prev = nodes[idx];
        if (val < prev.y) continue;
        node nex{idx, (bool)s, prev.x, prev.y};
        if (val < prev.x)
          nex.y = val;
        else
          nex.x = val;
        nodes.push_back(nex);
        next_valid.push_back(nodes.size() - 1);
      }
    valid_nodes.clear();
    vector<bool> optimal(next_valid.size(), true);
    for (int me = 0; me < next_valid.size(); me++)
      for (int you = 0; you < next_valid.size(); you++) {
        if (me == you || !optimal[me]) continue;
        node& mynode = nodes[next_valid[me]];
        node& yournode = nodes[next_valid[you]];
        if (mynode.x == yournode.x && mynode.y == yournode.y) {
          optimal[you] = false;
        } else if (mynode.x >= yournode.x && mynode.y >= yournode.y) {
          optimal[me] = false;
          break;
        }
      }
    for (int me = 0; me < next_valid.size(); me++) {
      if (optimal[me]) valid_nodes.push_back(next_valid[me]);
    }
    if (valid_nodes.size() == 0) {
      int dbg = 0;
    }
  }
  if (valid_nodes.empty()) {
    cout << "NO\n";
    return;
  }
  cout << "YES\n";
  int cur = valid_nodes[0];
  vector<int> ans(n);
  for (int i = n - 1; i >= 0; i--) {
    int x = nodes[cur].plus ? arr[i] : -arr[i];
    ans[i] = x;
    cur = nodes[cur].pa;
  }
  for (int k : ans) cout << k << ' ';
  cout << '\n';
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) solve();
}
