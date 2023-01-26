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
    for (i = 0; i < n; i++) {
      long long x;
      cin >> x;
      v.push_back(x);
    }
    long long sum = accumulate(v.begin(), v.end(), 0 * 1LL);
    long long mean = 2 * sum * 1.00 / n;
    sort(v.begin(), v.end());
    long long count = 0;
    if (2 * sum % n != 0) {
      cout << 0 << endl;
    } else {
      map<long long, long long> m;
      for (long long i = 0; i < n; i++) {
        count += m[v[i]];
        m[mean - v[i]]++;
      }
      cout << count << endl;
    }
  }
  return 0;
}
