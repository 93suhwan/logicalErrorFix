#include <bits/stdc++.h>
using namespace std;
const long long MAX = 3e5 + 5;
const long long M = 1e6 + 5;
const int MOD = 1e9 + 7;
const double pi = 3.141592653589793238;
void solve() {
  int n;
  cin >> n;
  string s = "";
  string s1;
  cin >> s1;
  s = s + s1;
  for (int i = 1; i < n - 2; i++) {
    string s2;
    cin >> s2;
    int l = s.length();
    if (s[l - 1] == s2[0]) {
      s += s2[1];
    } else {
      s += s2;
    }
  }
  if (s.length() < n) {
    s += 'a';
  }
  cout << s << "\n";
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
