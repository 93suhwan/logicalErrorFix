#include <bits/stdc++.h>
using namespace std;
#pragma warning(disable : 4996)
const long long N = 2e5 + 5;
const long long mod = 1e9 + 7;
const long long inf = 1e18;
void solve() {
  string s, t;
  cin >> s >> t;
  s += "$";
  t += "$";
  long long si = 0;
  long long ti = 0;
  long long sn = ((long long)s.size());
  long long tn = ((long long)t.size());
  long long d = 0;
  long long w = 1;
  for (long long i = 0; i < ((long long)s.size()); i++) {
    if (s[i] == t[ti] && i % 2 == w) {
      d++;
      ti++;
      w = 1 - w;
    }
  }
  if (d == ((long long)t.size())) {
    cout << "YES";
    return;
  }
  d = 0;
  w = 0;
  ti = 0;
  for (long long i = 0; i < ((long long)s.size()); i++) {
    if (s[i] == t[ti] && i % 2 == w) {
      d++;
      ti++;
      w = 1 - w;
    }
  }
  if (d == ((long long)t.size())) {
    cout << "YES";
    return;
  }
  cout << "NO";
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(0);
  long long t = 0;
  long long test_cases = 1;
  cin >> test_cases;
  while (t++ < test_cases) {
    solve();
    cout << "\n";
  }
  cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs"
       << "\n";
  return 0;
}
