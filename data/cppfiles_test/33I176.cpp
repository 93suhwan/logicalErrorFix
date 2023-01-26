#include <bits/stdc++.h>
using namespace std;
const int maxx = 1005;
long long a[300010], b[300010];
int main() {
  memset(b, 0, sizeof(b));
  int t;
  cin >> t;
  while (t--) {
    long long ans = 0;
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      b[i] = a[i];
    }
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++) {
      if (b[i] == a[n]) {
        ans = a[n] * max(b[i - 1], b[i + 1]);
        cout << ans << endl;
        break;
      }
    }
  }
  return 0;
}
