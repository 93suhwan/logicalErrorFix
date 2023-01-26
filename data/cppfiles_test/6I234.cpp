#include <bits/stdc++.h>
using namespace std;
int n, m, ans;
int dead[210000] = {0};
int ls[210000] = {0}, fs[210000] = {0};
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m;
  int o, u, v, q;
  while (m--) {
    cin >> u >> v;
    if (u > v) swap(u, v);
    fs[u]++, fs[v]++;
    ls[v]++;
  }
  ans = n;
  for (int i = 1; i <= n; i++)
    if (fs[i] && ls[i] != fs[i]) dead[i] = 1, ans--;
  int t = 1;
  cin >> q;
  while (q--) {
    cin >> o;
    if (o == 1) {
      cin >> u >> v;
      if (u > v) swap(u, v);
      fs[u]++, fs[v]++;
      ls[v]++;
      if (fs[u] && ls[u] != fs[u] && !dead[u]) dead[u] = t, ans--;
    }
    if (o == 2) {
      cin >> u >> v;
      if (u > v) swap(u, v);
      fs[u]--, fs[v]--;
      ls[v]--;
      if (fs[u] == ls[u] && dead[u] == t) dead[u] = 0, ans++;
    }
    if (o == 3) {
      t++;
      cout << ans << endl;
    }
  }
  return 0;
}
