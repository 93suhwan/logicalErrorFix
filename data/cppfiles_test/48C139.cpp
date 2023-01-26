#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5e5 + 10;
int a[MAXN];
int f[MAXN];
int find(int x) {
  if (f[x] != x)
    return f[x] = find(f[x]);
  else
    return f[x];
}
int vis[MAXN];
int main() {
  std::ios::sync_with_stdio(false);
  int _;
  cin >> _;
  while (_--) {
    int n;
    cin >> n;
    map<int, int> Map;
    for (int i = 1; i <= n; i++) cin >> a[i];
    int mx = 0;
    for (int i = 1; i <= n; i++) {
      Map[a[i]]++;
      mx = max(mx, Map[a[i]]);
    }
    if (mx > 1) {
      cout << "YES\n";
      continue;
    }
    for (int i = 1; i <= n; i++) {
      f[i] = i;
    }
    for (int i = 1; i <= n; i++) {
      f[a[i]] = find(i);
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
      if (f[i] == i) cnt++;
    }
    cnt = n - cnt;
    if (cnt & 1) {
      cout << "NO\n";
    } else
      cout << "YES\n";
  }
}
