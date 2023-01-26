#include <bits/stdc++.h>
using namespace std;
const long long N = 1e6 + 5;
long long n, d, a[N];
signed main() {
  long long t;
  cin >> t;
  while (t--) {
    cin >> n >> d;
    long long ans = 0;
    for (long long i = 0; i < n; ++i) cin >> a[i];
    priority_queue<pair<long long, long long>,
                   vector<pair<long long, long long> >,
                   greater<pair<long long, long long> > >
        q;
    for (long long i = 0; i < n; ++i) {
      if (a[i] == 0) q.push(make_pair(0, i));
    }
    while (!q.empty()) {
      pair<long long, long long> s = q.top();
      q.pop();
      long long x = (s.second + d) % n;
      if (a[x] == 0)
        continue;
      else {
        a[x] = 0;
        q.push(make_pair(s.first + 1, x));
        ans = max(s.first + 1, ans);
      }
    }
    bool flag = 1;
    for (long long i = 0; i < n; ++i) {
      if (a[i] == 1) flag = 0;
    }
    if (flag)
      cout << ans << endl;
    else
      cout << "-1" << endl;
  }
  return 0;
}
