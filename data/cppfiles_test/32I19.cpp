#include <bits/stdc++.h>
using namespace std;
const long long N = 100001, M = 451, INF = (long long)1e18;
long long store[N][M];
long long ps[N];
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long q;
  cin >> q;
  while (q--) {
    long long n;
    cin >> n;
    long long ar[n];
    long long m = min((long long)sqrt(2 * n) + 2LL, M);
    for (long long i = 0; i < n; i++) {
      cin >> ar[i];
    }
    ps[0] = 0;
    for (long long i = 0; i < n; i++) {
      ps[i + 1] = ps[i] + ar[i];
    }
    long long ans = 1;
    store[n][1] = -1;
    for (long long i = n - 1; i >= 0; i--) {
      store[i][1] = max(store[i + 1][1], ar[i]);
    }
    long long sum = 3;
    for (long long j = 2; j < m; j++) {
      if (n - sum + 1 >= 0) {
        store[n - sum + 1][j] = -1;
      }
      for (long long i = n - sum; i >= 0; i--) {
        store[i][j] = store[i + 1][j];
        if (store[j + i][j - 1] > ps[j + i] - ps[i]) {
          store[i][j] = max(ps[j + i] - ps[i], store[i][j]);
          ans = j;
        }
      }
      sum += (j - 1);
      if (ans != j) {
        break;
      }
    }
    cout << ans << '\n';
  }
}
