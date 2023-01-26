#include <bits/stdc++.h>
using namespace std;
int mod = 1000000007;
vector<long long> brr;
vector<pair<long long, long long> > crr;
bool check(long long s) {
  for (long long i = 0; i < brr.size(); i++) {
    if (brr[i] < s) {
      s = s + crr[i].second;
    } else {
      return false;
    }
  }
  return true;
}
void testcases() {
  long long n;
  cin >> n;
  vector<vector<long long> > arr;
  long long k;
  for (long long i = 0; i < n; i++) {
    cin >> k;
    vector<long long> v;
    for (long long j = 0; j < k; j++) {
      long long a;
      cin >> a;
      v.push_back(a);
    }
    arr.push_back(v);
  }
  for (long long i = 0; i < n; i++) {
    long long l = INT_MIN;
    long long p = 0;
    for (auto j : arr[i]) {
      l = max(l, (j - p));
      p++;
    }
    crr.push_back(make_pair(l, arr[i].size()));
  }
  sort(crr.begin(), crr.end());
  for (long long i = 0; i < n; i++) {
    brr.push_back(crr[i].first);
  }
  long long l = 0;
  long long r = 1000000000;
  long long ans = INT_MAX;
  while (l <= r) {
    long long mid = l + (r - l) / 2;
    if (check(mid)) {
      ans = min(ans, mid);
      r = mid - 1;
    } else
      l = mid + 1;
  }
  cout << ans << "\n";
  brr.clear();
  crr.clear();
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t;
  cin >> t;
  long long d = 1;
  while (t--) {
    testcases();
  }
}
