#include <bits/stdc++.h>
const long long M = 1e9 + 7;
using namespace std;
long long dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};
void test_cases() {
  long long n, k;
  cin >> n >> k;
  vector<long long> a(n);
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  vector<long long> v;
  for (long long i = n - 1, cnt = 0; cnt < 2 * k; i--, cnt++) {
    v.push_back(a[i]);
  }
  reverse(v.begin(), v.end());
  long long ans = 0;
  vector<long long> done(2 * k);
  for (long long i = 0; i < 2 * k; i++) {
    long long ok = 0;
    for (long long j = 0; j < 2 * k; j++) {
      if (!done[j] && (v[j] > v[i])) {
        ans += v[i] / v[j];
        done[j] = 1;
        done[i] = 1;
        ok = 1;
        break;
      }
    }
    if (!ok) {
      long long cnt = count(done.begin(), done.end(), 0);
      ans += cnt / 2;
      break;
    }
  }
  for (long long i = 0; i < n - 2 * k; i++) {
    ans += a[i];
  }
  cout << ans << '\n';
  ;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  ;
  long long t = 1;
  cin >> t;
  while (t--) {
    test_cases();
  }
}
