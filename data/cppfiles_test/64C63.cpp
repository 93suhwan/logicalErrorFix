#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
struct node {
  int u, v;
};
node e[N];
int pre1[N], pre2[N], d1[N], d2[N];
int find1(int x) {
  if (x == pre1[x])
    return x;
  else
    return pre1[x] = find1(pre1[x]);
}
int find2(int x) {
  if (x == pre2[x])
    return x;
  else
    return pre2[x] = find2(pre2[x]);
}
int main() {
  ios::sync_with_stdio(0);
  int n, m1, m2;
  cin >> n >> m1 >> m2;
  for (int i = 1; i <= n; i++) pre1[i] = pre2[i] = i;
  for (int i = 1; i <= m1; i++) {
    int u, v;
    cin >> u >> v;
    int fa = find1(u);
    int fb = find1(v);
    pre1[fa] = fb;
  }
  for (int i = 1; i <= m2; i++) {
    int u, v;
    cin >> u >> v;
    int fa = find2(u);
    int fb = find2(v);
    pre2[fa] = fb;
  }
  int cnt = 0, idx1 = 0, idx2 = 0;
  int fa1 = find1(1), fa2 = find2(1);
  for (int i = 2; i <= n; i++) {
    int fb1 = find1(i), fb2 = find2(i);
    if (fb1 != fa1 && fb2 != fa2) {
      e[++cnt].u = 1, e[cnt].v = i;
      pre1[fb1] = fa1;
      pre2[fb2] = fa2;
    }
  }
  for (int i = 1; i <= n; i++) {
    if (find1(i) != fa1) {
      d1[++idx1] = i;
      pre1[find1(i)] = fa1;
    }
  }
  for (int i = 1; i <= n; i++) {
    if (find2(i) != fa2) {
      d2[++idx2] = i;
      pre2[find2(i)] = fa2;
    }
  }
  for (int i = 1; i <= min(idx1, idx2); i++)
    e[++cnt].u = d1[i], e[cnt].v = d2[i];
  cout << cnt << '\n';
  for (int i = 1; i <= cnt; i++) cout << e[i].u << ' ' << e[i].v << '\n';
  return 0;
}
