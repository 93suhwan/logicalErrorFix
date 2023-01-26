#include <bits/stdc++.h>
using namespace std;
long long solve() {
  long long n;
  cin >> n;
  set<long long> over;
  std::vector<pair<long long, pair<long long, long long> > > v;
  long long a[n];
  long long b[n];
  long long c[n];
  for (int i = 0; i < n; ++i) {
    long long x, y;
    cin >> x >> y;
    a[i] = x;
    b[i] = y;
    v.push_back(make_pair(abs(y - x), make_pair(x, y)));
  }
  sort(v.begin(), v.end());
  long long cnt = 0;
  for (auto x : v) {
    long long l = x.second.first;
    long long r = x.second.second;
    if (l == r && over.count(l) == 0) {
      cout << l << " " << r << " " << l << "\n";
      over.insert(l);
      cnt++;
    } else {
      bool found = false;
      long long ans = 0;
      for (int i = l; i <= r; ++i) {
        if (over.count(i) == 0) {
          if (found == true) {
            found = false;
            break;
          }
          ans = i;
          found = true;
          over.insert(i);
        }
      }
      if (found == true) {
        cnt++;
        cout << l << " " << r << " " << ans << "\n";
      }
    }
  }
  return 0;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t = 1;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    solve();
    cout << "\n";
  }
  return 0;
}
