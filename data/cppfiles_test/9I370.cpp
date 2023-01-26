#include <bits/stdc++.h>
using namespace std;
void func() {
  string s;
  cin >> s;
  sort(s.begin(), s.end());
  int ans = 0;
  for (int i = 0, j = s.length() - 1; i <= j; i++, j--) {
    if (s[i] != s[j])
      ans++;
    else
      break;
  }
  if (ans == 0 and s.length() >= 2) ans = 1;
  cout << ans << "\n";
}
int main() {
  int t = 1;
  cin >> t;
  while (t--) {
    func();
  }
  return 0;
}
