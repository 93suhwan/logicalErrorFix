#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long m;
    cin >> m;
    set<long long> s;
    for (long long i = 1; i <= n; i++) s.insert(i);
    for (long long i = 0; i < m; i++) {
      long long a;
      cin >> a;
      long long b;
      cin >> b;
      long long c;
      cin >> c;
      s.erase(b);
    }
    long long k = *(s.begin());
    for (long long i = 1; i <= n; i++) {
      if (k == i) continue;
      cout << k << ' ' << i << endl;
    }
  }
  return 0;
}
