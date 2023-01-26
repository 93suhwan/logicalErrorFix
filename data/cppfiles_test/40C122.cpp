#include <bits/stdc++.h>
using namespace std;
vector<int> v[3 * 100005];
int n, m, nr, h[3 * 100005], f[3 * 100005], a[3 * 100005], b[3 * 100005],
    t[3 * 100005], q;
void dfs(int x) {
  for (auto it : v[x])
    if (h[it] == 0) {
      t[it] = x;
      h[it] = h[x] + 1;
      dfs(it);
    }
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int x, y;
    cin >> x >> y;
    v[x].push_back(y);
    v[y].push_back(x);
  }
  cin >> q;
  for (int i = 1; i <= q; i++) {
    cin >> a[i] >> b[i];
    f[a[i]]++;
    f[b[i]]++;
  }
  for (int i = 1; i <= n; i++)
    if (f[i] % 2) nr++;
  if (nr) {
    cout << "NO\n" << nr / 2;
    return 0;
  }
  cout << "YES\n";
  h[1] = 1;
  dfs(1);
  for (int i = 1; i <= q; i++) {
    vector<int> unu;
    vector<int> doi;
    while (h[a[i]] > h[b[i]]) {
      unu.push_back(a[i]);
      a[i] = t[a[i]];
    }
    while (h[a[i]] < h[b[i]]) {
      doi.push_back(b[i]);
      b[i] = t[b[i]];
    }
    while (a[i] != b[i]) {
      unu.push_back(a[i]);
      doi.push_back(b[i]);
      a[i] = t[a[i]];
      b[i] = t[b[i]];
    }
    cout << unu.size() + doi.size() + 1 << '\n';
    for (auto it : unu) cout << it << ' ';
    cout << a[i] << ' ';
    for (int j = doi.size() - 1; j >= 0; j--) cout << doi[j] << ' ';
    cout << '\n';
  }
  return 0;
}
