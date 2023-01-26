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
  for (int i = 0; i < 8192; i++) pos[i] = -1;
  pos[0] = 0;
  for (int x = 1; x <= 5000; x++) {
    if (li[x].size() == 0) continue;
    for (int y = 0; y < 8192; y++) {
      if (pos[y] > -1) {
        continue;
      }
      int z = x ^ y;
      if (pos[z] == -1) {
        continue;
      }
      pos[y] =
          lower_bound(li[x].begin(), li[x].end(), pos[z] + 1) - li[x].begin();
      if (pos[y] == li[x].size())
        pos[y] = -1;
      else
        pos[y] = li[x][pos[y]];
    }
  }
  int res = 0;
  for (int i = 0; i < 8192; i++)
    if (pos[i] != -1) res++;
  cout << res << '\n';
  for (int i = 0; i < 8192; i++)
    if (pos[i] != -1) cout << i << ' ';
  return 0;
}
int main() {
  int ntest = 1;
  while (ntest--) {
    solve();
  }
}
