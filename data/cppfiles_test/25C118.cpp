#include <bits/stdc++.h>
using namespace std;
void solve() {
  string s, substr;
  cin >> s >> substr;
  int len = s.length();
  int l = substr.length();
  bool f = false;
  for (int i = 0; i < len; i++) {
    string s1 = s.substr(0, i + 1);
    string rev = s.substr(0, i);
    reverse(rev.begin(), rev.end());
    string temp = s1 + rev;
    if (temp.find(substr) != temp.npos) {
      f = true;
      break;
    }
  }
  if (f)
    cout << "YES\n";
  else
    cout << "NO\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
