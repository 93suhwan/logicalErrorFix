#include <bits/stdc++.h>
using namespace std;
constexpr long long MOD = 1e9 + 7;
constexpr long double EPS = 0.0 + 1e-6;
void YES() {
  cout << "YES"
       << "\n";
}
void NO() {
  cout << "NO"
       << "\n";
}
bool search(const string& s, long long i, const string& t, long long j,
            bool going_left, bool going_right, bool can_turn_left) {
  if (j >= t.size()) return false;
  if (i < 0 or i >= s.size()) return false;
  if (s[i] != t[j]) return false;
  if (s[i] == t[j] and j + 1 == t.size()) return true;
  if (going_right and search(s, i + 1, t, j + 1, false, true, true))
    return true;
  if (going_right and can_turn_left and
      search(s, i - 1, t, j + 1, true, false, false))
    return true;
  if (going_left and search(s, i - 1, t, j + 1, true, false, false))
    return true;
  return false;
}
void solve() {
  string s;
  cin >> s;
  string t;
  cin >> t;
  for (long long i = 0; i < s.size(); ++i) {
    if (search(s, i, t, 0, false, true, true)) return YES();
  }
  NO();
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
