#include <bits/stdc++.h>
using namespace std;
int n, m1, m2;
int f1[200000];
int f2[200000];
int p1[100000], p2[100000], len1, len2;
void init() {
  for (int i = 1; i <= n; i++) f1[i] = i, f2[i] = i;
}
int find1(int x) {
  if (x == f1[x]) return x;
  f1[x] = find1(f1[x]);
  return f1[x];
}
int find2(int x) {
  if (x == f2[x]) return x;
  f2[x] = find2(f2[x]);
  return f2[x];
}
void Union1(int x, int y) {
  int fx = find1(x), fy = find1(y);
  if (fx != fy) f1[fx] = fy;
  return;
}
void Union2(int x, int y) {
  int fx = find2(x), fy = find2(y);
  if (fx != fy) f2[fx] = fy;
  return;
}
int main() {
  cin >> n >> m1 >> m2;
  init();
  int u, v;
  int len = 0, ans[200000][2];
  for (int i = 1; i <= m1; i++) {
    cin >> u >> v;
    Union1(u, v);
  }
  for (int i = 1; i <= m2; i++) {
    cin >> u >> v;
    Union2(u, v);
  }
  for (int i = 2; i <= n; i++) {
    if (find1(i) != find1(1) && find2(i) != find2(1)) {
      ans[++len][0] = 1;
      ans[len][1] = i;
      Union1(1, i);
      Union2(1, i);
    }
  }
  for (int i = 2; i <= n; i++) {
    if (find1(i) == find1(1)) p1[++len1] = i;
    if (find2(i) == find2(1)) p2[++len2] = i;
  }
  while (len1 > 0 && len2 > 0) {
    if (find2(p1[len1]) == find2(1))
      len1--;
    else if (find1(p2[len2]) == find1(1))
      len2--;
    else {
      ans[++len][0] = p1[len1];
      ans[len][1] = p2[len2];
      Union1(p1[len1], p2[len2]);
      Union2(p1[len1], p2[len2]);
    }
  }
  cout << len << endl;
  for (int i = 1; i <= len; i++) cout << ans[i][0] << ' ' << ans[i][1] << endl;
}
