#include <bits/stdc++.h>
using namespace std;
const long long N = 2e5 + 5;
map<long long, long long> mpa, mpb;
long long a[N], b[N];
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long T;
  cin >> T;
  long long n;
  while (T--) {
    cin >> n;
    mpa.clear();
    mpb.clear();
    for (long long i = 1; i <= n; i++) {
      cin >> a[i] >> b[i];
      mpa[a[i]]++;
      mpb[b[i]]++;
    }
    long long ans = (n - 2) * (n - 1) * n / 6;
    for (long long i = 1; i <= n; i++) {
      ans -= (mpa[a[i]] - 1) * (mpb[b[i]] - 1);
    }
    cout << ans << endl;
  }
  return 0;
}
