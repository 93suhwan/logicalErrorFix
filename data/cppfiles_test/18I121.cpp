#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int n, d, sz = 0;
int a[N];
int vis[N];
bool poss = true;
void dfs(int v) {
  if (!a[v]) return;
  vis[v]++;
  sz++;
  if (vis[v] > 1) {
    poss = false;
    return;
  }
  int nxt = (v - d + n) % n;
  dfs(nxt);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int test = 1;
  cin >> test;
  while (test--) {
    cin >> n >> d;
    for (int i = 0; i < n; i++) cin >> a[i], vis[i] = 0;
    poss = true;
    int ans = 0;
    for (int i = 0; i < n; i++) {
      if (vis[i]) continue;
      sz = 0;
      dfs(i);
      ans = max(ans, sz);
    }
    if (poss)
      cout << ans;
    else
      cout << -1;
    cout << "\n";
  }
  return 0;
}
