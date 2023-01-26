#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) {
    long long n, k;
    cin >> n >> k;
    vector<long long> v(n + 1, 1000000000000000);
    for (long long i = 0; i < n; i++) {
      cin >> v[i];
    }
    vector<pair<long long, long long>> p(n + 1);
    for (long long i = 0; i < n; i++) {
      p[i].first = v[i];
      p[i].second = i;
    }
    p[n].first = 1000000000000000000;
    p[n].second = n;
    sort(p.begin(), p.end());
    long long ans = 0;
    for (long long i = 0; i <= n - 1; i++) {
      if (p[i + 1].first != v[p[i].second + 1]) ans++;
    }
    if (ans <= k) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
  return 0;
}
