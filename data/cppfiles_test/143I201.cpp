#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
;
const int sz = 6e5 + 5;
const int N = 1e6;
void solve() {
  long long n;
  cin >> n;
  map<long long, long long> m;
  for (long long i = 0; i < n; i++) {
    long long a;
    cin >> a;
    m[a]++;
  }
  long long cur = 0;
  vector<long long> v;
  long long ex = 0;
  long long f = 0;
  for (long long i = 0; i < n + 1; i++) {
    if (i == cur and f == 0) {
      if (!m[cur]) f = 1;
      cout << m[cur] << ' ';
      m[cur] -= 1;
      for (long long j = 0; j < m[cur]; j++) v.push_back(cur);
      cur++;
    } else {
      if (v.size()) {
        ex += (cur - v.back());
        v.pop_back();
        cout << ex - 1 << ' ';
      } else
        cout << -1 << ' ';
    }
  }
  cout << "\n";
}
int32_t main() {
  {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
  }
  long long T;
  T = 1;
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}
