#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    long long n, k;
    cin >> n >> k;
    vector<long long> v;
    long long mini = INT_MAX;
    for (long long i = 0; i < n; i++) {
      long long x;
      cin >> x;
      v.push_back(x);
      mini = min(mini, x);
    }
    sort(v.begin(), v.end());
    long long count = 0;
    for (long long i = 0; i < n; i++) {
      if (mini == v[i]) {
        count++;
      } else
        break;
    }
    long long p = 0;
    long long ans = 0;
    while (p < k) {
      long long z = v.size();
      long long mx = v[z - 1];
      if (k - p >= (z - count)) {
        break;
      }
      if (v[z - 2] != mx) {
        v.pop_back();
        v.pop_back();
      } else if (v[z - 2] == mx) {
        v.pop_back();
        v.pop_back();
        ans += 1;
      }
      p++;
    }
    long long y = 0;
    long long q = 0;
    while (y < ((k - p))) {
      if (v[v.size() - 1] == mini) {
        ans++;
        v.pop_back();
      } else
        v.pop_back();
      v[q] = -1;
      q++;
      y++;
    }
    for (long long i = 0; i < v.size(); i++) {
      if (v[i] == -1) {
        v[i] = 0;
      } else
        ans += v[i];
    }
    cout << ans << endl;
  }
  return 0;
}
