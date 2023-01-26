#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int i[maxn];
void solve() {
  map<int, int> vis;
  int ct = 0;
  int n;
  cin >> n;
  for (int w = 1; w <= n; w++) {
    cin >> i[w];
    if (i[w] <= n) vis[i[w]] = 1;
  }
  sort(i + 1, i + n + 1);
  int begin = 1;
  for (int w = 1; w <= n; w++) {
    if (vis[i[w]] == 0) {
      ct++;
      while (vis[begin] && begin <= n) {
        ++begin;
      }
      if (begin == n + 1) {
        cout << ct << "\n";
        return;
      }
      int a = i[w] - begin, b = begin;
      if (b >= a) {
        cout << "-1\n";
        return;
      }
      vis[begin] = 1;
    }
  }
  cout << ct << "\n";
}
signed main() {
  cin.sync_with_stdio(false);
  int n;
  cin >> n;
  while (n--) solve();
  return 0;
}
