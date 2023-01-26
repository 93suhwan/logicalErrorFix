#include <bits/stdc++.h>
using namespace std;
void result() {
  int g;
  cin >> g;
  int sum = 0;
  string s;
  cin >> s;
  string s_cp = s;
  sort(s_cp.begin(), s_cp.end());
  for (int i = 0; i < s.length(); i++) {
    if (s[i] != s_cp[i]) sum++;
  }
  cout << sum << endl;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    result();
  }
  return 0;
}
