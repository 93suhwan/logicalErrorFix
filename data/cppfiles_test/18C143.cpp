#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long t, n, d;
  cin >> t;
  while (t--) {
    cin >> n >> d;
    vector<long long> a(n);
    for (long long i = 0; i < n; i++) {
      cin >> a[i];
    }
    vector<long long> used(n, 0);
    vector<vector<long long>> kek;
    for (long long i = 0; i < n; i++) {
      if (used[i] == 1) continue;
      long long cur = i;
      kek.push_back({});
      while (used[cur] != 1) {
        used[cur] = 1;
        kek.back().push_back(a[cur]);
        cur = (cur - d + n) % n;
      }
    }
    long long lol, MX = 0, mx;
    for (auto line : kek) {
      lol = -1;
      for (long long j = 0; j < line.size(); j++) {
        if (line[j] == 0) {
          lol = j;
        }
      }
      if (lol == -1) {
        break;
      }
      mx = 0;
      long long cur = (lol + 1) % line.size();
      long long cnt = 0;
      while (cur != lol) {
        if (line[cur] == 1) {
          cnt++;
        } else {
          mx = max(mx, cnt);
          cnt = 0;
        }
        cur = (cur + 1) % line.size();
      }
      mx = max(mx, cnt);
      MX = max(MX, mx);
    }
    if (lol == -1) {
      cout << -1 << "\n";
    } else {
      cout << MX << "\n";
    }
  }
}
