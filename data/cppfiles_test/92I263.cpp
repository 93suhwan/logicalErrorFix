#include <bits/stdc++.h>
using namespace std;
void solve() {
  string s;
  cin >> s;
  int a = 0, b = 0;
  int i, j;
  int n = s.size();
  for (i = 1; i < n; ++i) {
    if (s[i] == 'b' && s[i - 1] == 'a') {
      ++a;
    }
    if (s[i] == 'a' && s[i - 1] == 'b') {
      ++b;
    }
  }
  if (a != b) {
    for (i = 1; i < n; ++i) {
      if (s[i] == 'b' && s[i - 1] == 'a') {
        s[i - 1] = 'b';
        break;
      }
      if (s[i] == 'a' && s[i - 1] == 'b') {
        s[i - 1] = 'a';
        break;
      }
    }
  }
  cout << s << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int test_case = 1;
  cin >> test_case;
  while (test_case-- > 0) solve();
  return 0;
}
