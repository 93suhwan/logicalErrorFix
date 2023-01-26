#include <bits/stdc++.h>
using namespace std;
int n, a[200003], b[200003], m[200003], T, idx[200003], XXX, res[200003],
    ans[200003], qaq[200003];
vector<int> v[2000003], V;
bool cmp(int X, int Y) {
  return max(a[v[XXX][X]] - m[v[XXX][X]], 0) * 200004ll + X <=
         max(a[v[XXX][Y]] - m[v[XXX][Y]], 0) * 200004ll + Y;
}
int solve(int x) {
  for (int i = 0; i < v[x].size(); i++) idx[i] = i;
  XXX = x;
  sort(idx, idx + v[x].size(), cmp);
  int l = 0, r = 2147483647, cnt = 0, tl, tr;
  for (int i = 0; i < v[x].size(); i++) {
    tl = max(l, max(a[v[x][idx[i]]] - m[v[x][idx[i]]], 0));
    tr = min(r, a[v[x][idx[i]]] + min(0, b[v[x][idx[i]]] - m[v[x][idx[i]]]));
    if (tl > tr) {
      ans[cnt++] = l;
      l = max(a[v[x][idx[i]]] - m[v[x][idx[i]]], 0);
      r = a[v[x][idx[i]]] + min(0, b[v[x][idx[i]]] - m[v[x][idx[i]]]);
    } else
      l = tl, r = tr;
    res[v[x][idx[i]]] = cnt;
  }
  ans[cnt++] = l;
  for (int i = 0; i < v[x].size(); i++)
    qaq[v[x][idx[i]]] = ans[res[v[x][idx[i]]]];
  return cnt;
}
int main() {
  cin >> T;
  while (T--) {
    cin >> n;
    V.clear();
    for (int i = 0; i < n; i++) {
      scanf("%d%d%d", a + i, b + i, m + i);
      v[a[i] + b[i] - m[i]].push_back(i);
      V.push_back(a[i] + b[i] - m[i]);
    }
    sort(V.begin(), V.end());
    V.erase(unique(V.begin(), V.end()), V.end());
    int ANS = 0;
    for (int i = 0; i < V.size(); i++) ANS += solve(V[i]);
    cout << ANS << endl;
    for (int i = 0; i < n; i++)
      printf("%d %d\n", a[i] - qaq[i], m[i] - a[i] + qaq[i]);
    for (int i = 0; i < n; i++) v[a[i] + b[i] - m[i]].clear();
  }
}
