#include <bits/stdc++.h>
using ll = long long;
using namespace std;
int main() {
  int caseNo;
  cin >> caseNo;
  while (caseNo--) {
    int n;
    cin >> n;
    vector<string> s(n - 2);
    for (int i = 0; i < s.size(); i++) cin >> s[i];
    string ans = s[0];
    for (int i = 1; i < s.size(); i++) {
      if (s[i][0] == s[i - 1][1])
        ans += s[i][1];
      else
        ans += s[i];
    }
    if (ans.length() < n) ans += "a";
    cout << ans << endl;
  }
}
