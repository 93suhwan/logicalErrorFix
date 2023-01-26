#include <bits/stdc++.h>
using namespace std;
const long long INF = 1000000007;
const long long N = 100005;
long long power(long long a[], long long n) {
  auto idx = max_element(a, a + n) - a;
  return max(a[0] + 1, a[idx] - idx + 1);
}
bool possible(vector<pair<long long, long long> > v, long long n,
              long long val) {
  long long i = 0;
  while (i < n) {
    if (v[i].first <= val) {
      val += v[i].second - v[i].first;
      i++;
    } else if (v[i].first > val && i < n) {
      return false;
    }
  }
  return true;
}
bool cmp(pair<long long, long long> p1, pair<long long, long long> p2) {
  if (p1.first != p2.first) return p1.first < p2.first;
  return p2.second > p1.second;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cout.precision(numeric_limits<double>::max_digits10);
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    vector<pair<long long, long long> > v;
    for (long long i = 0; i < n; i++) {
      long long k;
      cin >> k;
      long long a[k];
      for (long long i = 0; i < k; i++) cin >> a[i];
      v.push_back({power(a, k), power(a, k) + k});
    }
    sort(v.begin(), v.end(), cmp);
    long long lo = 0, hi = INF, mid;
    while (hi - lo > 1) {
      mid = (hi + lo) / 2;
      if (possible(v, n, mid))
        hi = mid;
      else
        lo = mid + 1;
    }
    if (possible(v, n, lo))
      cout << lo << '\n';
    else
      cout << hi << '\n';
  }
  return 0;
}
