#include <bits/stdc++.h>
using namespace std;
int p1[1001], p2[1001], d1[1001], d2[1001];
void make_set(int v) {
  p1[v] = v;
  d1[v] = 0;
  p2[v] = v;
  d2[v] = 0;
}
int find_set1(int v) {
  if (v == p1[v]) return v;
  return p1[v] = find_set1(p1[v]);
}
int find_set2(int v) {
  if (v == p2[v]) return v;
  return p2[v] = find_set2(p2[v]);
}
void union_sets1(int a, int b) {
  a = find_set1(a);
  b = find_set1(b);
  if (a != b) {
    if (d1[a] < d1[b]) swap(a, b);
    p1[b] = a;
    if (d1[a] == d1[b]) d1[a]++;
  }
}
void union_sets2(int a, int b) {
  a = find_set2(a);
  b = find_set2(b);
  if (a != b) {
    if (d2[a] < d2[b]) swap(a, b);
    p2[b] = a;
    if (d2[a] == d2[b]) d2[a]++;
  }
}
int main() {
  int n, m1, m2;
  cin >> n >> m1 >> m2;
  for (int k = 1; k <= n; k++) make_set(k);
  for (int k = 1; k <= m1; k++) {
    int x, y;
    cin >> x >> y;
    union_sets1(x, y);
  }
  for (int k = 1; k <= m2; k++) {
    int x, y;
    cin >> x >> y;
    union_sets2(x, y);
  }
  vector<pair<int, int> > ans;
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      int x1, x2, x3, x4;
      x1 = find_set1(i);
      x2 = find_set1(j);
      x3 = find_set2(i);
      x4 = find_set2(j);
      if (x1 != x2 && x3 != x4) {
        union_sets1(i, j);
        union_sets2(i, j);
        ans.push_back({i, j});
      }
    }
  }
  cout << ans.size() << "\n";
  for (int k = 0; k < ans.size(); k++) {
    cout << ans[k].first << ' ' << ans[k].second << "\n";
  }
  return 0;
}
