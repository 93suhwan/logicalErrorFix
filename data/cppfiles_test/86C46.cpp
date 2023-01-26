#include <bits/stdc++.h>
using namespace std;
int solve(string s) {
  int ans = count(s.begin(), s.end(), '0');
  bool a = false, b = false;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '1') a = true;
    if (s[i] == '0') b = true;
    if (a & b == 1) {
      a = false;
      b = false;
      ans++;
    }
  }
  return ans;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    string a, b;
    cin >> n >> a >> b;
    int ans = 0;
    string s = "";
    for (int i = 0; i < n; i++) {
      if (a[i] != b[i]) {
        ans += 2 + solve(s);
        s = "";
      } else {
        s += a[i];
      }
    }
    ans += solve(s);
    cout << ans << endl;
  }
  return 0;
}
