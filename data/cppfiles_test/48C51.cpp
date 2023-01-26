#include <bits/stdc++.h>
using namespace std;
int T, n, b[500005], a[500005], cnt;
map<int, int> tu, pos;
bool fl, vis[500005];
void dfs(int x) {
  vis[x] = 1, cnt++;
  if (!vis[a[x]]) dfs(a[x]);
}
int main() {
  cin >> T;
  while (T--) {
    cin >> n;
    tu.clear(), fl = 0, cnt = 0;
    for (int i = 1; i <= n; i++) cin >> a[i], tu[a[i]]++;
    for (int i = 1; i <= n; i++)
      if (tu[a[i]] > 1) fl = 1;
    if (n == 1 || fl) {
      puts("YES");
      continue;
    }
    for (int i = 1; i <= n; i++) b[i] = a[i];
    sort(b + 1, b + 1 + n);
    for (int i = 1; i <= n; i++) pos[b[i]] = i;
    for (int i = 1; i <= n; i++) a[i] = pos[a[i]], vis[i] = 0;
    for (int i = 1; i <= n; i++)
      if (!vis[i]) dfs(i), cnt--;
    puts(((cnt)&1) ? "NO" : "YES");
  }
}
