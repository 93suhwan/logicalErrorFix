#include <bits/stdc++.h>
using namespace std;
map<int, int> mpa, mpb;
vector<vector<int>> ea(1001), eb(1001);
vector<int> visa(1001, 0), visb(1001, 0);
vector<pair<int, int>> ans;
void dfsa(int curr, int par) {
  for (auto x : ea[curr]) {
    if (visa[x]) continue;
    visa[x] = 1;
    mpa[x] = mpa[par];
    dfsa(x, par);
  }
}
void dfsb(int curr, int par) {
  for (auto x : eb[curr]) {
    if (visb[x]) continue;
    visb[x] = 1;
    mpb[x] = mpb[par];
    dfsb(x, par);
  }
}
int root_a(int i) {
  while (mpa[i] != i) {
    i = mpa[i];
  }
  return i;
}
int root_b(int i) {
  while (mpb[i] != i) {
    i = mpb[i];
  }
  return i;
}
void merge_a(int a, int b) {
  if (root_a(a) < root_a(b))
    mpa[root_a(b)] = root_a(a);
  else
    mpa[root_a(a)] = root_a(b);
}
void merge_b(int a, int b) {
  if (root_b(a) < root_b(b))
    mpb[root_b(b)] = root_b(a);
  else
    mpb[root_b(a)] = root_b(b);
}
int main() {
  int n, m1, m2, i, j;
  cin >> n >> m1 >> m2;
  while (m1--) {
    int x, y;
    cin >> x >> y;
    x--;
    y--;
    ea[x].push_back(y);
    ea[y].push_back(x);
  }
  while (m2--) {
    int x, y;
    cin >> x >> y;
    x--;
    y--;
    eb[x].push_back(y);
    eb[y].push_back(x);
  }
  for (i = 0; i < n; i++) {
    mpa[i] = mpb[i] = i;
  }
  for (i = 0; i < n; i++) {
    if (visa[i]) continue;
    visa[i] = 1;
    dfsa(i, i);
  }
  for (i = 0; i < n; i++) {
    if (visb[i]) continue;
    visb[i] = 1;
    dfsb(i, i);
  }
  for (i = 0; i < n; i++) {
    for (j = i + 1; j < n; j++) {
      if (root_a(i) != root_a(j) && root_b(i) != root_b(j)) {
        ans.push_back({i + 1, j + 1});
        merge_a(i, j);
        merge_b(i, j);
      }
    }
  }
  cout << ans.size() << "\n";
  for (auto x : ans) cout << x.first << " " << x.second << "\n";
}
