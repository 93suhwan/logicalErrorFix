#include <bits/stdc++.h>
using namespace std;
int a[30];
int solve(string &s) {
  int res = s.length();
  for (int i = 0; i <= res - 1; i++) {
    a[s[i] - 'a']++;
  }
  for (int i = 0; i <= 25; i++) {
    if (a[i] > 2) {
      res = res - (a[i] - 2);
    }
  }
  return res / 2;
}
int main() {
  int t;
  cin >> t;
  string s;
  while (t--) {
    memset(a, 0, sizeof a);
    cin >> s;
    cout << solve(s) << '\n';
  }
}
