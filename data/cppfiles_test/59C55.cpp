#include <bits/stdc++.h>
using namespace std;
long long tc, n;
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> tc;
  while (tc--) {
    cin >> n;
    vector<long long> vec[n + 10];
    for (long long i = 0; i < n; i++) {
      for (long long j = 0; j < 5; j++) {
        long long x;
        cin >> x;
        vec[i].push_back(x);
      }
    }
    for (long long i = 0; i <= 3; i++) {
      for (long long j = i + 1; j <= 4; j++) {
        long long ci = 0, cj = 0;
        for (long long k = 0; k < n; k++) {
          if (vec[k][i] == 0 && vec[k][j] == 0) {
            goto next;
          }
          if (vec[k][i] == 1) ci++;
          if (vec[k][j] == 1) cj++;
        }
        if (ci >= n / 2 && cj >= n / 2) {
          cout << "YES" << '\n';
          goto skip;
        }
      next:;
      }
    }
    cout << "NO" << '\n';
  skip:;
  }
  return 0;
}
