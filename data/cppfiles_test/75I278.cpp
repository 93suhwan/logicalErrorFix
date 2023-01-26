#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    vector<pair<long long, long long>> a;
    long long globmax = -1e18;
    long long kk = 0;
    long long total = 0;
    long long ans = 1e18;
    for (long long i = 0; i < n; i++) {
      long long k;
      cin >> k;
      total += k;
      long long poss = INT_MIN;
      for (long long j = 0; j < k; j++) {
        long long y;
        cin >> y;
        poss = max(poss, y - j + 1);
      }
      a.push_back({poss, k});
    }
    sort(a.begin(), a.end());
    ans = a[0].first;
    long long myans = ans;
    for (long long i = 1; i < a.size(); i++) {
      long long req = a[i].second;
      long long newans = ans + a[i - 1].second;
      if (newans >= req) {
        ans = newans;
        continue;
      } else {
        myans = req;
        ans = req + ans + a[i - 1].second;
      }
    }
    cout << myans << endl;
  }
}
