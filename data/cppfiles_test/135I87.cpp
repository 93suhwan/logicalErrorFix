#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    long long n, k;
    cin >> n >> k;
    vector<long long> v(n);
    for (auto &i : v) cin >> i;
    sort((v).begin(), (v).end());
    long long i = n - 1;
    long long ans = 0;
    map<long long, long long> mp;
    while (k--) {
      mp[v[i]]++;
      mp[v[i - 1]]++;
      i -= 2;
    }
    long long left = 0;
    for (auto i : mp) {
      left = abs(i.second - left);
    }
    ans += left / 2;
    for (long long j = 0; j <= i; j++) ans += v[j];
    cout << ans << '\n';
  }
  return 0;
}
