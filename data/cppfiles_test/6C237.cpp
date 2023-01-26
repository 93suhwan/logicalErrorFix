#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
const int N = 200010, INF = 0x3f3f3f3f;
int T, ans;
void solve() {
  int n, m;
  cin >> n >> m;
  map<int, int> l[n + 1];
  for (int i = 1; i <= n; i++) l[i][-i]++;
  while (m--) {
    int a, b;
    cin >> a >> b;
    l[a][-b]++;
    l[b][-a]++;
  }
  cin >> m;
  int op, a, b;
  for (int i = 1; i <= n; i++)
    if (l[i].begin()->first == -i) ans++;
  while (m--) {
    cin >> op;
    if (op == 1) {
      cin >> a >> b;
      int k1 = l[a].begin()->first, k2 = l[b].begin()->first;
      l[a][-b]++;
      l[b][-a]++;
      int k11 = l[a].begin()->first, k22 = l[b].begin()->first;
      if (k1 == -a && k11 != -a)
        ans--;
      else if (k11 == -a && k1 != -a)
        ans++;
      if (k2 == -b && k22 != -b)
        ans--;
      else if (k22 == -b && k2 != -b)
        ans++;
    } else if (op == 2) {
      cin >> a >> b;
      int k1 = l[a].begin()->first, k2 = l[b].begin()->first;
      l[a].erase(l[a].find(-b));
      l[b].erase(l[b].find(-a));
      int k11 = l[a].begin()->first, k22 = l[b].begin()->first;
      if (k1 == -a && k11 != -a)
        ans--;
      else if (k11 == -a && k1 != -a)
        ans++;
      if (k2 == -b && k22 != -b)
        ans--;
      else if (k22 == -b && k2 != -b)
        ans++;
    } else if (op == 3) {
      cout << ans << '\n';
    }
  }
}
int main(void) {
  clock_t c1 = clock();
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  T = 1;
  while (T--) solve();
end:
  cerr << "Time Used:" << clock() - c1 << "ms" << '\n';
  return 0;
}
