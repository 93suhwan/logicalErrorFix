#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const int N = 2e5 + 100;
int a[N];
int b[N];
typedef struct node {
  int x, y;
} node;
node c[N];
signed main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
      int x, y;
      cin >> x >> y;
      a[x]++;
      b[y]++;
      c[i].x = x;
      c[i].y = y;
    }
    long long sum = 0;
    long long ans = 1ll * n * (n - 1) * (n - 2) / 6;
    for (int i = 1; i <= n; i++) {
      if (a[c[i].x] >= 2) {
        sum += 1ll * (a[c[i].x] - 1) * (b[c[i].y] - 1);
      }
    }
    for (int i = 1; i <= n; i++) {
      a[i] = b[i] = 0;
    }
    cout << ans - sum << endl;
  }
  return 0;
}
