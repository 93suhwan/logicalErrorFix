#include <bits/stdc++.h>
using namespace std;
int T;
void solve() {
  string s, t;
  cin >> s >> t;
  int ls = s.length(), lt = t.length();
  bool f = false;
  for (int i = 1; i < lt; i++) {
    int x = i;
    string left = t.substr(0, x);
    int p1 = s.find(left);
    if (p1 == -1) continue;
    string right = t.substr(x);
    reverse(right.begin(), right.end());
    int p2 = s.find(right);
    if (p2 == -1) continue;
    if (p1 + left.size() == p2 + right.size() + 1) {
      f = true;
      break;
    }
  }
  if (s.find(t) != string::npos) f = true;
  reverse(t.begin(), t.end());
  if (s.find(t) != string::npos) f = true;
  if (f)
    puts("YES");
  else
    puts("NO");
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}
