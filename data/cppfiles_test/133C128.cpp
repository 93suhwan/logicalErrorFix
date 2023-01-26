#include <bits/stdc++.h>
using namespace std;
string solve() {
  long long n;
  cin >> n;
  vector<string> p;
  for (long long i = 0; i < n - 2; i++) {
    string a;
    cin >> a;
    p.push_back(a);
  }
  string s;
  if (p[0][0] == 'a')
    s = "a";
  else
    s = "b";
  bool done = false;
  for (long long i = 1; i < n - 2; i++) {
    if (p[i][0] == p[i - 1][1]) {
      s += p[i][0];
      continue;
    }
    s += p[i - 1][1];
    s += p[i][0];
    done = true;
  }
  s += p.back()[1];
  if (done) return s;
  s += s.back();
  return s;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  long long t;
  cin >> t;
  while (t--) cout << solve() << "\n";
}
