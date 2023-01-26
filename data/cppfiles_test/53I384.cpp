#include <bits/stdc++.h>
using namespace std;
const long double inf = 1e18;
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.precision(15);
  long long t;
  cin >> t;
  while (t--) {
    long long n, k;
    cin >> n >> k;
    vector<long long> a(n);
    for (long long i = 0; i < n; ++i) cin >> a[i];
    long long res = 0;
    for (long long i = 1; i < n; ++i)
      if (a[i] < a[i - 1]) res++;
    if (res <= k - 1)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
}
