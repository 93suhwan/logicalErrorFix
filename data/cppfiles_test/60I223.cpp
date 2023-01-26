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
    setprecision(10);
    double mean = sum * 1.00 / n;
    sort(v.begin(), v.end());
    long long count = 0;
    if (v[0] == v[n - 1]) {
      cout << n * (n - 1) / 2 << endl;
    } else {
      i = 0;
      long long j = n - 1;
      while (i < j) {
        long long x = v[i];
        long long y = v[j];
        double p = ((x + y) * 1.00) / 2;
        if (p > mean) {
          j--;
        } else if (p < mean) {
          i++;
          j = n - 1;
        } else if (p == mean) {
          count++;
          j--;
        }
      }
      cout << count << endl;
    }
  }
  return 0;
}
