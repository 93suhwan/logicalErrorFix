#include <bits/stdc++.h>
using namespace std;
const int maxn = 2000005;
const int inf = 0x3f3f3f3f;
int a[maxn];
bool vis[maxn];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    int cnt = n / 2;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      vis[a[i]] = 1;
    }
    sort(a + 1, a + 1 + n);
    for (int i = 1; i <= n; i++) {
      for (int j = i + 1; j <= n; j++) {
        if (a[i] == a[j]) continue;
        if (vis[a[i] % a[j]] == 0) continue;
        cout << a[j] << ' ' << a[i] << '\n';
        if (--cnt == 0) break;
      }
      if (cnt == 0) break;
    }
    for (int i = 1; i <= n; i++) {
      vis[a[i]] = 0;
    }
  }
  return 0;
}
