#include <bits/stdc++.h>
using namespace std;
long long nc2(long long n) { return n * (n - 1) / 2; }
long long bs(vector<long long>& rem, long long a) {
  long long n = (long long)rem.size() - 1;
  long long l = 0, r = n;
  long long ans = n + 1;
  while (l <= r) {
    long long m = l + (r - l) / 2;
    if (rem[m] > a) {
      ans = min(m, ans);
      r = m - 1;
    } else {
      l = m + 1;
    }
  }
  return n - ans + 1LL;
}
signed main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n, k;
    cin >> n >> k;
    vector<vector<long long>> arr(k, vector<long long>(2, 0));
    vector<long long> vis(2 * n, 0);
    for (long long i = 0; i < k; i++) {
      cin >> arr[i][0] >> arr[i][1];
      arr[i][0]--, arr[i][1]--;
      vis[arr[i][0]] = 1, vis[arr[i][1]] = 1;
    }
    vector<long long> rem;
    for (long long i = 0; i < 2 * n; i++) {
      if (!vis[i]) {
        rem.push_back(i);
      }
    }
    long long ans = nc2(n - k);
    for (auto d : arr) {
      long long r = max(d[0], d[1]);
      long long l = min(d[0], d[1]);
      long long below = bs(rem, l) - bs(rem, r - 1);
      long long above = (long long)rem.size() - below;
      ans += min(above, below);
    }
    for (long long i = 0; i < k; i++) {
      long long p1 = min(arr[i][0], arr[i][1]);
      long long p2 = max(arr[i][0], arr[i][1]);
      for (long long j = i + 1; j < k; j++) {
        long long q1 = arr[j][0];
        long long q2 = arr[j][1];
        if (((q1 > p2 && q1 <= 2 * n) || q1 < p1) && (q2 > p1 && q2 < p2)) {
          ans++;
        } else if (((q2 > p2 && q2 <= 2 * n) || q2 < p1) &&
                   (q1 > p1 && q1 < p2)) {
          ans++;
        }
      }
    }
    cout << ans << "\n";
  }
  return 0;
}
