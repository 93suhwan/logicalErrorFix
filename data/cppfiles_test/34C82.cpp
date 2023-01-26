#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 5, N = 1 << 13;
int f[N][N], a[maxn], n;
vector<int> pos[N];
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i], pos[a[i]].push_back(i);
  int ans;
  memset(f, 0x3f, sizeof(f));
  int mx = f[0][0];
  f[0][0] = 0;
  for (int i = 1; i <= N - 1; i++) {
    for (int j = 0; j <= N - 1; j++) {
      int getpos = lower_bound(pos[i].begin(), pos[i].end(), f[i - 1][j]) -
                   pos[i].begin();
      if (getpos < pos[i].size())
        f[i][j ^ i] = min(f[i][j ^ i], pos[i][getpos]);
      f[i][j] = min(f[i][j], f[i - 1][j]);
    }
  }
  for (int j = 0; j <= N - 1; j++) ans += f[N - 1][j] != mx;
  cout << (ans) << '\n';
  for (int j = 0; j <= N - 1; j++)
    if (f[N - 1][j] != mx) cout << j << " ";
  cout << '\n';
  return 0;
}
