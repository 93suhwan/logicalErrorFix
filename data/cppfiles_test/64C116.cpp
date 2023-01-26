#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 1;
int n, u, v, m1, m2, r1[maxn], r2[maxn], vs[maxn], us[maxn];
int fr(int *rt, int i) {
  if (rt[i] == i)
    return i;
  else
    return rt[i] = fr(rt, rt[i]);
}
void un(int *rt, int i, int j) { rt[fr(rt, i)] = fr(rt, j); }
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> m1 >> m2;
  for (int i = 0; i <= n; i++) {
    r1[i] = i;
    r2[i] = i;
  }
  for (int i = 0; i < m1; i++) {
    cin >> u >> v;
    int rtu = fr(r1, u), rtv = fr(r1, v);
    if (rtu > rtv)
      r1[rtu] = rtv;
    else
      r1[rtv] = rtu;
  }
  for (int i = 0; i < m2; i++) {
    cin >> u >> v;
    int rtu = fr(r2, u), rtv = fr(r2, v);
    if (rtu > rtv)
      r2[rtu] = rtv;
    else
      r2[rtv] = rtu;
  }
  int count = 0;
  for (int i = 2; i <= n; i++) {
    if (fr(r1, i) != 1 && fr(r2, i) != 1) {
      un(r1, i, 1);
      un(r2, i, 1);
      us[count] = 1;
      vs[count++] = i;
    }
  }
  for (int i = 2, j = 2; i <= n && j <= n;) {
    while (fr(r1, i) == 1 && i <= n) i++;
    while (fr(r2, j) == 1 && j <= n) j++;
    if (i <= n && j <= n) {
      us[count] = i;
      vs[count++] = j;
      un(r1, i, 1);
      un(r2, j, 1);
    }
  }
  cout << count << endl;
  for (int t = 0; t < count; t++) {
    cout << us[t] << ' ' << vs[t] << endl;
  }
  return 0;
}
