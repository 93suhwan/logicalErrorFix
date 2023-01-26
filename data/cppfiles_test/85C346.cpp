#include <bits/stdc++.h>
using namespace std;
void solve() {
  string s;
  cin >> s;
  int sum = 0;
  for (int i = 1; i < s.size(); i++) {
    if (s[i] == '1' && s[i - 1] == '0') {
      sum++;
    }
  }
  if (s[s.size() - 1] == '0') {
    sum++;
  }
  if (sum > 2) {
    cout << 2 << endl;
    return;
  }
  cout << sum << endl;
  return;
}
int main() {
  int test;
  cin >> test;
  while (test--) {
    solve();
  }
  return 0;
}
