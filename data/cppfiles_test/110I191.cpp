#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> vec;
set<int> b;
set<int> r;
vector<int> a;
int nav(int f) {
  int ans = -1;
  r.insert(f);
  for (auto i : vec[f]) {
    if (r.count(i)) return -1;
    if (b.count(i) == 0) {
      int x = nav(i);
      if (x == -1) return -1;
      a[i] = x;
      b.insert(i);
      r.clear();
    }
    if (b.count(i)) {
      if (f < i)
        ans = max(ans, a[i] + 1);
      else
        ans = max(ans, a[i]);
    }
  }
  b.insert(f);
  a[f] = ans;
  return ans;
}
int mark[200001];
int dfs(int u) {
  if (mark[u] == 1) return -1;
  mark[u] = 1;
  for (auto x : vec[u]) {
    dfs(x);
  }
  return 1;
}
int order() {
  int n;
  cin >> n;
  vec.clear();
  b.clear();
  r.clear();
  a.clear();
  vec.resize(n + 1);
  a.resize(n + 1);
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    if (x == 0) b.insert(i), a[i] = 1;
    for (int j = 0; j < x; j++) {
      int y;
      cin >> y;
      vec[i].push_back(y);
    }
  }
  for (int i = 1; i <= n; i++) mark[i] = 0;
  int k;
  for (k = 1; k <= n; k++) {
    if (mark[k] == 0) {
      if (dfs(k) == -1) break;
    }
  }
  if (k < n + 1) return -1;
  for (int i = 1; i <= n; i++) {
    if (b.count(i)) continue;
    int ans = -1;
    for (auto j : vec[i]) {
      if (b.count(j) == 0) {
        r.clear();
        r.insert(i);
        int x = nav(j);
        if (x == -1)
          return -1;
        else
          b.insert(x), a[i] = x;
      }
      if (b.count(j)) {
        if (j < i)
          ans = max(ans, a[j]);
        else
          ans = max(ans, a[j] + 1);
      }
    }
    b.insert(i);
    a[i] = ans;
  }
  return *max_element(a.begin(), a.end());
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int t;
  cin >> t;
  while (t-- > 0) {
    cout << order() << "\n";
  }
}
