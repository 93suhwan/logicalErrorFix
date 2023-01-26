#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
int f1[N], f2[N];
void init() {
  for (int i = 0; i < N; i++) f1[i] = i, f2[i] = i;
}
int getf1(int x) {
  if (f1[x] != x) f1[x] = getf1(f1[x]);
  return f1[x];
}
int getf2(int x) {
  if (f2[x] != x) f2[x] = getf2(f2[x]);
  return f2[x];
}
bool merge(int a, int b) {
  int fa1 = getf1(a), fa2 = getf2(a), fb1 = getf1(b), fb2 = getf2(b);
  if (fa1 == fb1 || fa2 == fb2) return 0;
  f1[fa1] = fb1, f2[fa2] = fb2;
  return 1;
}
int main() {
  int n, m1, m2;
  cin >> n >> m1 >> m2;
  init();
  for (int i = 0; i < m1; i++) {
    int u, v;
    cin >> u >> v;
    int fu = getf1(u), fv = getf1(v);
    f1[fu] = fv;
  }
  for (int i = 0; i < m2; i++) {
    int u, v;
    cin >> u >> v;
    int fu = getf2(u), fv = getf2(v);
    f2[fu] = fv;
  }
  vector<pair<int, int> > p;
  int cnt = 0;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) {
      if (i == j) continue;
      if (merge(i, j)) {
        p.push_back({i, j});
        cnt++;
      }
    }
  cout << cnt << endl;
  for (int i = 0; i < p.size(); i++)
    cout << p[i].first << " " << p[i].second << endl;
}
