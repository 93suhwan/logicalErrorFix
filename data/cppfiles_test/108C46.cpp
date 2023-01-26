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
    vector<long long> pmax(n);
    vector<long long> smin(n + 1);
    smin[n] = LLONG_MAX;
    for (long long i = 0; i < n; i++) {
      pmax[i] = ab[i].second;
      if (i) pmax[i] = max(pmax[i], pmax[i - 1]);
    }
    for (long long i = n - 1; i >= 0; i--) {
      smin[i] = min(smin[i + 1], ab[i].second);
    }
    long long l = n - 1;
    for (long long i = n - 2; i >= 0; --i) {
      if (pmax[i] > smin[i + 1]) {
        l = i;
      } else {
        break;
      }
    }
    for (long long i = l; i < n; i++) {
      ans[ind[ab[i]]] = '1';
    }
    cout << ans << '\n';
  }
}
