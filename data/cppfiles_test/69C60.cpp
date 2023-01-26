#include <bits/stdc++.h>
using namespace std;
vector<string> pre;
int f(string s, string t) {
  int n = s.length(), m = t.length(), i = 0, j = 0, cnt = 0;
  while (i < n and j < m) {
    if (s[i] == t[j]) {
      cnt++;
      j++;
    }
    i++;
  }
  return n - cnt + m - cnt;
}
void solve() {
  long long int n, ans = 1e9;
  cin >> n;
  string no = to_string(n);
  for (auto s : pre) {
    ans = min((long long int)f(no, s), ans);
  }
  cout << ans;
}
int main() {
  long long int t = 1;
  cin >> t;
  for (long long int i = 1; i <= 2e18; i *= 2) {
    pre.push_back(to_string(i));
  }
  while (t--) {
    solve();
    cout << "\n";
  }
  return 0;
}
