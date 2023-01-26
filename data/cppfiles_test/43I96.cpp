#include <bits/stdc++.h>
using namespace std;
const int N = 300000 + 10;
int fa[N];
pair<int, int> val[N];
int get(int x) {
  if (x == fa[x]) return x;
  int t = get(fa[x]);
  val[x].first ^= val[fa[x]].first;
  val[x].second |= val[fa[x]].second;
  return fa[x] = t;
}
int main() {
  int n, q;
  cin >> n >> q;
  for (int i = 1; i <= n; i++) fa[i] = i, val[i] = {0, 0};
  while (q--) {
    int u, v, w;
    cin >> u >> v >> w;
    int fu = get(u), fv = get(v);
    if (fu != fv) {
      fa[fu] = fv;
      val[fu] = {w, 0};
      cout << "YES" << endl;
    } else {
      if (val[u].second || val[v].second ||
          val[u].first ^ val[v].first ^ w != 1)
        cout << "NO" << endl;
      else {
        val[u].second = val[v].second = 1;
        cout << "YES" << endl;
      }
    }
  }
}
