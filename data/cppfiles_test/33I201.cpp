#include <bits/stdc++.h>
using namespace std;
const int maxx = 1005;
long long a[300010], b[300010];
int main() {
  memset(b, 0, sizeof(b));
  freopen("in.txt", "r", stdin);
  int t;
  cin >> t;
  while (t--) {
    long long ans = 0, ans2 = 0;
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      b[i] = a[i];
    }
    sort(a + 1, a + n + 1);
    for (int j = n; j >= 1; j--) {
      for (int i = 1; i <= n; i++) {
        if (b[i] == a[j]) {
          ans2 = a[j] * max(b[i - 1], b[i + 1]);
          if (ans < ans2) ans = ans2;
        }
      }
    }
    cout << ans << endl;
  }
  return 0;
}
