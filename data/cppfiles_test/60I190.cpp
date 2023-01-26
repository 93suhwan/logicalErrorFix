#include <bits/stdc++.h>
using namespace std;
signed main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long sum = 0;
    vector<long long> v(n);
    map<long long, long long> mp;
    for (long long i = 0; i < n; i++) {
      cin >> v[i];
      mp[v[i]]++;
      sum += v[i];
    }
    long long k = sum / n;
    k *= 2;
    long long ans = 0;
    for (long long i = 0; i < n; i++) {
      ans += mp[k - v[i]];
      if (k - v[i] == v[i]) {
        ans--;
      }
    }
    cout << ans / 2 << endl;
  }
}
