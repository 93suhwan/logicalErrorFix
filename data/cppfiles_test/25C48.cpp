#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e18;
const long long A = 200005;
const long long mod = 1000000007;
bool comp(long long a, long long b) { return a > b; }
long long n, k, tt = 1;
string s, t;
bool rec(int i, int j, int dir) {
  if (j == k) return 1;
  if (i < 0 || j < 0) return 0;
  if (i == n) return 0;
  if (s[i] != t[j]) return 0;
  if (dir == 1) {
    return rec(i + 1, j + 1, 1) || rec(i - 1, j + 1, -1);
  }
  return (rec(i + dir, j + 1, -1));
}
void solve() {
  cin >> s >> t;
  n = s.size();
  k = t.size();
  for (int i = 0; i < n; i++) {
    if (rec(i, 0, -1) || rec(i, 0, 1)) {
      cout << "Yes"
           << "\n";
      return;
    }
  }
  cout << "No"
       << "\n";
  return;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  ;
  long long t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
