#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long int n;
  cin >> n;
  vector<string> s;
  for (long long int i = 0; i < n - 2; i++) {
    string x;
    cin >> x;
    s.push_back(x);
  }
  string res = "";
  for (long long int i = 0; i < n - 2; i++) {
    if (i == 0) {
      res += s[0];
      continue;
    }
    if (res[res.size() - 1] != s[i][0])
      res += s[i];
    else
      res += s[i][1];
  }
  if (res.size() != n) {
    if (res[0] == 'a') {
      while (res.size() < n) res += "b";
    } else {
      while (res.size() < n) res += "a";
    }
  }
  cout << res << '\n';
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int test;
  cin >> test;
  while (test--) solve();
  return 0;
}
