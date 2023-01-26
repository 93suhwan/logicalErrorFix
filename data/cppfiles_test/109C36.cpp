#include <bits/stdc++.h>
using namespace std;
void test_case() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  int ans = s[n - 1] - '0';
  for (int i = n - 2; i >= 0; i--) {
    if (int(s[i] - '0')) ans += s[i] + 1 - '0';
  }
  cout << ans << '\n';
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) test_case();
  return 0;
}
