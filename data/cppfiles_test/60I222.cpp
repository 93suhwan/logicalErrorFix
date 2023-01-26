#include <bits/stdc++.h>
using namespace std;
bool sortbysec(pair<long long, long long> &a, pair<long long, long long> &b) {
  return (a.second < b.second);
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    long long n, i;
    cin >> n;
    vector<long long> v;
    map<long long, long long> m;
    for (i = 0; i < n; i++) {
      long long x;
      cin >> x;
      v.push_back(x);
      m[x]++;
    }
    long long sum = accumulate(v.begin(), v.end(), 0 * 1LL);
    double z = sum * 1.00 / n;
    long long count = 0;
    if (v[0] == v[n - 1]) {
      cout << n * (n - 1) / 2 << endl;
    } else {
      long long sum = z * 2;
      long long ans = 0;
      for (auto it : m) {
        long long x = it.first;
        long long y = sum - x;
        ans += m[x] * m[y];
      }
      cout << ans / 2 << endl;
    }
  }
  return 0;
}
