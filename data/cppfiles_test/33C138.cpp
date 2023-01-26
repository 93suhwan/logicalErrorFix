#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10, M = 512;
int n, a[N], pos[N];
bool vis[M];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  memset(pos, 63, sizeof(pos));
  vis[0] = 1;
  for (int i = 1; i <= n; ++i) {
    pos[a[i]] = min(pos[a[i]], a[i]), vis[a[i]] = 1;
    for (int j = 0; j < M; ++j)
      if (pos[j ^ a[i]] < a[i]) pos[j] = min(pos[j], a[i]), vis[j] = 1;
  }
  int cnt = 0;
  for (int i = 0; i < M; ++i)
    if (vis[i]) ++cnt;
  cout << cnt << '\n';
  for (int i = 0; i < M; ++i)
    if (vis[i]) cout << i << ' ';
  cout << '\n';
}
