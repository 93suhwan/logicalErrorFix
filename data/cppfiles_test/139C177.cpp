#include <bits/stdc++.h>
using namespace std;
const int64_t mod = 1e9 + 7, INF = 1e18L + 5, N = 2e5 + 5;
const string yes = "YES", no = "NO";
void pavvo() {
  string s;
  cin >> s;
  int64_t n = s.size();
  string t = s.substr(0, n / 2);
  string p = s.substr(n / 2, n);
  ;
  cout << ((t == p) ? yes : no) << '\n';
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int64_t T = 1;
  cin >> T;
  for (int64_t test = 1; test <= T; ++test) {
    pavvo();
  }
  cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC
       << "ms\n";
  return 0;
}
