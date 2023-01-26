#include <bits/stdc++.h>
using namespace std;
long long cnt[35];
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    memset(cnt, 0, sizeof(cnt));
    for (long long i = 1; i <= n; i++) {
      long long a;
      cin >> a;
      for (long long j = 0; j <= 31; j++)
        if (a & (1 << j)) cnt[j]++;
    }
    for (long long i = 1; i <= n; i++) {
      bool f = 1;
      for (long long j = 0; j <= 31; j++)
        if (cnt[j] % i != 0) f = 0;
      if (f) cout << i << " ";
    }
    cout << "\n";
  }
}
