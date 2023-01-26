#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
using namespace std;
const long long INF = 2e18;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long t;
  cin >> t;
  while (t--) {
    long long n, i, k;
    cin >> n >> k;
    long long a[n];
    for (i = 0; i < n; i++) {
      cin >> a[i];
    }
    sort(a, a + n, greater<long long>());
    long long cnt = 2 * k;
    long long ans = 0;
    vector<long long> v;
    for (i = 0; i < cnt; i++) {
      v.push_back(a[i]);
    }
    map<long long, long long> m;
    long long maxocc = 0;
    for (i = 0; i < v.size(); i++) {
      m[v[i]]++;
      maxocc = max(maxocc, m[v[i]]);
    }
    while (cnt < n) {
      ans += a[cnt++];
    }
    ans += maxocc - k;
    cout << ans << "\n";
  }
  return 0;
}
