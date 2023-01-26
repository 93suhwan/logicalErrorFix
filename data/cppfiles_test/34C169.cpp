#include <bits/stdc++.h>
using namespace std;
const int maxn = 200005;
long long t, n, k;
long long arr[maxn];
int main() {
  cin >> t;
  while (t--) {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
      cin >> arr[i];
    }
    long long ans = -1e12;
    for (int i = max(1ll, n - 2 * k); i <= n; i++) {
      for (int j = i + 1; j <= n; j++) {
        ans = max(1ll * ans, 1ll * i * j - 1ll * k * (arr[i] | arr[j]));
      }
    }
    cout << ans << endl;
  }
  return 0;
}
