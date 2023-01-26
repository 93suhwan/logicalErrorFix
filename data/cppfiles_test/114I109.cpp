#include <bits/stdc++.h>
using namespace std;
const int maxn = 2000005;
const int inf = 0x3f3f3f3f;
int n, a[maxn];
bool vis[maxn];
bool cmp(int a, int b) { return a > b; }
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int T;
  cin >> T;
  while (T--) {
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      vis[a[i]] = 1;
    }
    sort(a + 1, a + 1 + n, cmp);
    int num = n / 2;
    for (int i = 1; i <= n; i++) {
      for (int j = i + 1; j <= n; j++) {
        if (a[i] != a[j] && vis[a[j] % a[i]]) {
          cout << a[i] << ' ' << a[j] << '\n';
          if (--num == 0) break;
        }
      }
      if (num == 0) break;
    }
    for (int i = 1; i <= n; i++) {
      vis[a[i]] = 0;
    }
  }
  return 0;
}
