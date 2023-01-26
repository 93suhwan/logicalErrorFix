#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 11;
int n, a[N], pos[N];
vector<int> li[5011];
int solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    li[a[i]].push_back(i);
  }
  for (int i = 0; i < 8192; i++) pos[i] = n + 1;
  pos[0] = 0;
  for (int x = 1; x <= 5000; x++) {
    if (li[x].size() == 0) continue;
    for (int y = 0; y < 8192; y++) {
      int z = x ^ y;
      if (pos[z] == n + 1 || pos[y] <= li[x][0]) {
        continue;
      }
      int id =
          lower_bound(li[x].begin(), li[x].end(), pos[z] + 1) - li[x].begin();
      if (id == li[x].size()) continue;
      pos[y] = min(pos[y], li[x][id]);
    }
  }
  int res = 0;
  for (int i = 0; i < 8192; i++)
    if (pos[i] <= n) res++;
  cout << res << '\n';
  for (int i = 0; i < 8192; i++)
    if (pos[i] <= n) cout << i << ' ';
  return 0;
}
int main() {
  int ntest = 1;
  while (ntest--) {
    solve();
  }
}
