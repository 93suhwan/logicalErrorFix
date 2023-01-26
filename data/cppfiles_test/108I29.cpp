#include <bits/stdc++.h>
using namespace std;
signed main(signed argc, const char *argv[]) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    string ans(n, '0');
    vector<pair<long long, long long>> ab(n);
    map<pair<long long, long long>, long long> ind;
    for (long long i = 0; i < n; i++) {
      cin >> ab[i].first;
    }
    for (long long i = 0; i < n; i++) {
      cin >> ab[i].second;
    }
    for (long long i = 0; i < n; i++) {
      ind[ab[i]] = i;
    }
    sort((ab).begin(), (ab).end());
    vector<long long> pmax(n), smax(n + 1);
    pmax[0] = ab[0].second;
    for (long long i = 1; i < n; i++) {
      pmax[i] = max(pmax[i - 1], ab[i].second);
    }
    smax[n - 1] = ab[n - 1].second;
    for (long long i = n - 2; i >= 0; i--) {
      smax[i] = max(smax[i + 1], ab[i].second);
    }
    for (long long i = 0; i < n; i++) {
      if (pmax[i] > smax[i + 1]) {
        ans[ind[ab[i]]] = '1';
      }
    }
    cout << ans << '\n';
  }
}
