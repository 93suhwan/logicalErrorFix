#include <bits/stdc++.h>
using namespace std;
long long mod = 1e9 + 7;
long long mxl = 1e5 + 7;
signed main() {
  long long tt;
  cin >> tt;
  while (tt--) {
    long long n;
    cin >> n;
    vector<long long> v(n);
    long long sum = 0;
    map<long long, long long> mp;
    for (int i = 0; i < n; ++i) {
      cin >> v[i];
      sum += v[i];
      mp[v[i]]++;
    }
    sum = (2 * sum / n);
    long long count = 0;
    for (int i = 0; i < n; ++i) {
      count += mp[sum - v[i]];
      if ((sum - v[i]) == v[i]) count -= 1;
    }
    cout << count / 2 << "\n";
  }
  return 0;
}
