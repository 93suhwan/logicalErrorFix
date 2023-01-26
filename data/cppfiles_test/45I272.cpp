#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
void solve() {
  long long n;
  cin >> n;
  long long e = 0, o = 0;
  std::vector<long long> v(n);
  for (long long i = 0; i < n; i++) {
    cin >> v[i];
    v[i] = v[i] % 2;
    if (v[i] == 0) {
      e++;
    } else
      o++;
  }
  if (abs(e - o) > 1) {
    cout << -1 << endl;
    return;
  } else if (n == 1) {
    cout << 0 << endl;
    return;
  }
  long long ans1 = 0;
  stack<long long> s;
  long long j = 0;
  for (long long i = j; i < n; i++) {
    if (s.empty()) {
      s.push(v[i]);
    } else {
      if (s.top() != v[i]) {
        ans1 += s.size() - 1;
        s.pop();
      } else {
        while (1) {
          if (s.top() != v[i]) {
            ans1 += s.size() - 1;
            s.pop();
            break;
          }
          if (i == n) {
            break;
          }
          s.push(v[i]);
          i++;
        }
      }
    }
  }
  cout << ans1 << endl;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
