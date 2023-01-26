#include <bits/stdc++.h>
using namespace std;
const int N = 200 + 5;
class Node {
 public:
  int rnk, parent;
  Node() {
    rnk = -1;
    parent = -1;
  }
};
class Disjoint_Set {
 public:
  vector<Node> node;
  int n;
  int comps;
  Disjoint_Set(int nn) {
    n = nn;
    node.resize(n);
    for (int i = 0; i < n; i++) {
      make_set(i);
    }
    comps = n;
  }
  void make_set(int x) {
    node[x].rnk = 0;
    node[x].parent = x;
  }
  int find_set(int x) {
    if (node[x].parent != x) {
      node[x].parent = find_set(node[x].parent);
    }
    return node[x].parent;
  }
  void Union(int u, int v) {
    int p = find_set(u), q = find_set(v);
    if (p == q) return;
    comps--;
    if (node[p].rnk > node[q].rnk)
      node[q].parent = p;
    else {
      node[p].parent = q;
      if (node[p].rnk == node[q].rnk) {
        node[q].rnk += 1;
      }
    }
  }
};
void TEST_CASES() {
  int n, m;
  cin >> n >> m;
  vector<int> b(n);
  vector<pair<int, int> > cnt;
  map<int, int> mp;
  for (int i = 0; i < n; i++) {
    cin >> b[i];
    b[i]--;
    int x = ((i - b[i]) % n + n) % n;
    mp[x]++;
    ;
  }
  for (auto it : mp) {
    cnt.push_back({it.second, it.first});
  }
  sort(cnt.rbegin(), cnt.rend());
  vector<int> ans;
  for (int i = 0; i < cnt.size(); i++) {
    int k = cnt[i].second;
    Disjoint_Set d(n);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      a[i] = ((i - k) % n + n) % n;
    }
    for (int i = 0; i < n; i++) {
      d.Union(b[i], a[i]);
    }
    if (n - d.comps <= m) {
      ans.push_back(k);
    } else {
      break;
    }
  }
  sort(ans.begin(), ans.end());
  cout << ans.size() << " ";
  for (int i : ans) {
    cout << i << " ";
  }
  cout << "\n";
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  cin >> t;
  while (t--) {
    TEST_CASES();
  }
  return 0;
}
