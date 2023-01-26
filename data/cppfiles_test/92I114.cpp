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
    int poss1 = 0;
    for (i = 1; i < n; ++i) {
      if (s[i] != s[i - 1]) {
        break;
      }
      poss1++;
    }
    int poss2 = 0;
    for (i = n - 2; i >= 0; --i) {
      if (s[i] != s[i + 1]) {
        break;
      }
      poss2++;
    }
    if (poss1 < poss2) {
      for (i = 1; i < n; ++i) {
        if (s[i] != s[i - 1]) {
          s[i - 1] = s[i];
          break;
        }
        if (s[i - 1] == 'a')
          s[i - 1] = 'b';
        else
          s[i - 1] = 'a';
      }
    } else {
      for (i = n - 2; i >= 0; --i) {
        if (s[i] != s[i + 1]) {
          s[i + 1] = s[i];
          break;
        }
        if (s[i + 1] == 'a')
          s[i + 1] = 'b';
        else
          s[i + 1] = 'a';
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
