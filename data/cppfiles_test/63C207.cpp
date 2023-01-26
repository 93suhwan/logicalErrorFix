#include <bits/stdc++.h>
using namespace std;
const char nl = '\n';
const int maxN = 1e5 + 10;
int link1[maxN];
int link2[maxN];
int size1[maxN];
int size2[maxN];
int findx(int x, int k) {
  if (k == 1) {
    while (x != link1[x]) x = link1[x];
    return x;
  } else {
    while (x != link2[x]) x = link2[x];
    return x;
  }
}
bool same(int a, int b, int k) { return findx(a, k) == findx(b, k); }
void unite(int a, int b, int k) {
  if (k == 1) {
    a = findx(a, k);
    b = findx(b, k);
    if (size1[a] < size1[b]) swap(a, b);
    size1[a] += size1[b];
    link1[b] = a;
  } else {
    a = findx(a, k);
    b = findx(b, k);
    if (size2[a] < size2[b]) swap(a, b);
    size2[a] += size2[b];
    link2[b] = a;
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m1, m2;
  cin >> n >> m1 >> m2;
  for (int i = 1; i <= n; i++) {
    link1[i] = link2[i] = i;
    size1[i] = size2[i] = 1;
  }
  for (int i = 0; i < m1; i++) {
    int a, b;
    cin >> a >> b;
    if (!same(a, b, 1)) unite(a, b, 1);
  }
  for (int i = 0; i < m2; i++) {
    int a, b;
    cin >> a >> b;
    if (!same(a, b, 2)) unite(a, b, 2);
  }
  vector<pair<int, int> > ans;
  for (int i = 1; i <= n - 1; i++) {
    for (int j = i + 1; j <= n; j++) {
      if (!same(i, j, 1) && !same(i, j, 2)) {
        ans.push_back({i, j});
        unite(i, j, 1);
        unite(i, j, 2);
      }
    }
  }
  cout << ans.size() << nl;
  for (auto x : ans) cout << x.first << " " << x.second << nl;
}
