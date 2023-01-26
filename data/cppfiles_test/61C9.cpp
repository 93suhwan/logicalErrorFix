#include <bits/stdc++.h>
using namespace std;
void remember() { cout << "Fastest Man Alive!" << ("\n"); }
void flash() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
int32_t main() {
  flash();
  long long T = clock();
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long a[n], b[n];
    map<long long, long long> r, s;
    for (long long i = 0; i < n; i++) {
      cin >> a[i] >> b[i];
      r[a[i]]++;
      s[b[i]]++;
    }
    long long ans = n * (n - 1) * (n - 2) / 6;
    for (long long i = 0; i < n; i++) {
      ans -= (r[a[i]] - 1) * (s[b[i]] - 1);
    }
    cout << ans << ("\n");
  }
  cerr << "TIME: " << (long double)(clock() - T) / CLOCKS_PER_SEC << " sec\n";
  return 0;
}
