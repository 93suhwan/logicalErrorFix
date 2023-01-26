#include <bits/stdc++.h>
using namespace std;
const long long N = 100001, M = 451, INF = (long long)1e18;
long long store[N][M];
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long q;
  cin >> q;
  while (q--) {
    long long n;
    cin >> n;
    long long ar[n];
    for (long long i = 0; i < n; i++) {
      cin >> ar[i];
      for (long long j = 0; j < M; j++) {
        store[i][j] = -1;
      }
    }
    for (long long j = 0; j < M; j++) {
      store[n][j] = -1;
    }
    long long ps[n + 1];
    ps[0] = 0;
    for (long long i = 0; i < n; i++) {
      ps[i + 1] = ps[i] + ar[i];
    }
    long long ans = 1;
    for (long long i = n - 1; i >= 0; i--) {
      store[i][1] = max(store[i + 1][1], ar[i]);
    }
    for (long long j = 2; j < M; j++) {
      for (long long i = n - 1; i >= 0; i--) {
        if (j + i >= n) continue;
        if (store[j + i][j - 1] == -1) continue;
        if (store[j + i][j - 1] > ps[j + i] - ps[i]) {
          store[i][j] = max({store[i + j][j], ps[j + i] - ps[i], store[i][j]});
          ans = j;
        }
      }
    }
    cout << ans << '\n';
  }
}
