#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n, a = 0, b = 0;
  string s;
  cin >> s;
  n = s.size();
  for (int i = 0; i < n; i++) {
    if (i == n - 1) continue;
    if (s[i] == 'a' && s[i + 1] == 'b')
      a++;
    else if (s[i] == 'b' && s[i + 1] == 'a')
      b++;
  }
  if (a == b)
    cout << s;
  else {
    if (a > b) {
      s[0] = 'b';
    } else {
      s[n - 1] = 'a';
    }
    cout << s;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int testcase = 1;
  cin >> testcase;
  for (int i = 1; i <= testcase; i++) {
    solve();
    cout << "\n";
  }
  return 0;
}
