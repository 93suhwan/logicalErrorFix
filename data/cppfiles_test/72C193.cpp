#include <bits/stdc++.h>
using namespace std;
bool run(int i, string &s, string &ans, int k, unordered_map<int, int> &m,
         bool greater) {
  int n = s.length();
  if (i == n) return true;
  int d = greater ? 0 : s[i] - '0';
  while (d < 10) {
    if (m.find(d) != m.end() || m.size() < k) {
      m[d]++;
      ans[i] = d + '0';
      bool f = run(i + 1, s, ans, k, m, greater || (s[i] - '0' < d));
      if (f) return true;
      m[d]--;
      if (m[d] == 0) m.erase(d);
    }
    d++;
  }
  return false;
}
int solve(int n, int k) {
  unordered_map<int, int> m;
  int x = log10(n);
  x = pow(10, x);
  string s = to_string(n);
  string ans = to_string(x);
  run(0, s, ans, k, m, false);
  return stoi(ans);
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    cout << solve(n, k) << endl;
  }
  return 0;
}
