#include <bits/stdc++.h>
using namespace std;
int gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
int lcm(long long a, long long b) { return a * b / gcd(a, b); }
bool TSTC = 1;
const int INF = 1e9;
int solve() {
  int n;
  cin >> n;
  vector<string> a(n - 2);
  for (auto &x : a) cin >> x;
  string answer = a[0];
  for (int i = 1; i < n - 2; ++i) {
    if (answer[answer.size() - 1] != a[i][0])
      answer += a[i];
    else
      answer += a[i][1];
  }
  if (answer.size() != n) answer += "a";
  cout << answer << "\n";
  return 0;
}
int32_t main() {
  cin.tie(0);
  cin.sync_with_stdio(0);
  int TET = 1;
  if (TSTC) cin >> TET;
  for (int i = 1; i <= TET; i++) {
    solve();
  }
  return 0;
}
