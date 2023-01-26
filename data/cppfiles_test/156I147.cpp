#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
bool solve(vector<long long> a, long long k, long long x) {
  int n = a.size();
  long long p = (x + 1) / 2LL;
  x -= p;
  a[0] = a[0] - p;
  for (int i = n - 1; i >= 1; i--) {
    if (x == 0) break;
    x--;
    a[i] = a[0];
  }
  while (x) {
    x--;
    a[0]--;
  }
  long long sum = 0;
  for (int i = 0; i < n; i++) {
    sum += a[i];
  }
  return sum <= k;
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  ;
  int T;
  cin >> T;
  while (T--) {
    long long n;
    long long k;
    cin >> n >> k;
    vector<long long> a(n);
    long long sum = 0;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      sum += a[i];
    }
    if (sum <= k) {
      cout << 0 << endl;
      continue;
    }
    sort(a.begin(), a.end());
    long long lo = 0, hi = (sum - k) + 1, res = -1;
    while (lo <= hi) {
      long long mid = (lo + hi) / 2LL;
      if (solve(a, k, mid)) {
        res = mid;
        hi = mid - 1;
      } else
        lo = mid + 1;
    }
    cout << res << endl;
  }
  return 0;
}
