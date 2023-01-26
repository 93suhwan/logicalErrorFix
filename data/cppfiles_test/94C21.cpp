#include <bits/stdc++.h>
using namespace std;
long long T, k, n, a[24], las, now, sum;
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> T;
  while (T--) {
    cin >> k >> n;
    n++;
    memset(a, 0, sizeof(a));
    for (long long i = 1; i <= k; ++i) {
      long long f;
      cin >> f;
      a[f] = true;
    }
    if (n <= 9) {
      cout << n << endl;
      continue;
    }
    las = 0;
    now = 9;
    sum = 0;
    for (long long i = 1; i <= 19; ++i)
      if (a[i] == 0) {
        now = now * 10 + 9;
        if (now + sum >= n) {
          cout << n - sum;
          for (long long j = las - 1; j >= 0; j--) cout << '9';
          break;
        }
      } else {
        las = i;
        sum += now;
        now = 9;
        if (sum + now >= n) {
          cout << n - sum;
          for (long long j = i - 1; j >= 0; j--) cout << 9;
          break;
        }
      }
    cout << endl;
  }
}
