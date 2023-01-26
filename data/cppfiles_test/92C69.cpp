#include <bits/stdc++.h>
using namespace std;
using vi = vector<long long>;
using vvi = vector<vi>;
using pii = pair<long long, long long>;
const long long INF = numeric_limits<long long>::max();
void solve() {
  string s;
  cin >> s;
  if (s.front() != s.back()) {
    s.front() = s.back();
  }
  cout << s << "\n";
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long T;
  cin >> T;
  while (T--) solve();
  return 0;
}
