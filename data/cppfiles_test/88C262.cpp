#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n, m;
    cin >> n >> m;
    long long a[n * m];
    vector<pair<int, int> > vc;
    for (long long i = 0; i < n * m; i++) {
      int x;
      cin >> x;
      vc.push_back({x, i});
    }
    sort(vc.begin(), vc.end());
    long long ans = 0;
    for (long long i = 0; i < n * m; i++) {
      if (i % m == 0) {
        continue;
      }
      for (long long o = i - 1; o >= 0; o--) {
        if (vc[i].second > vc[o].second && vc[i].first != vc[o].first) {
          ans++;
        }
        if (o % (m) == 0) {
          break;
        }
      }
    }
    cout << ans << endl;
  }
}
