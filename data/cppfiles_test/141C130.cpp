#include <bits/stdc++.h>
using namespace std;
void removing_leading_zeros(string& str) {
  while (str.size() >= 1 and str[str.size() - 1] == '0') str.pop_back();
}
string res(string& s, string& t) {
  string ans = "";
  long long int i = s.size() - 1, j = t.size() - 1;
  while (i >= 0 and j >= 0) {
    if (s[i] <= t[j])
      ans += ((t[j] - s[i]) + '0');
    else {
      if (j == 0 or t[j - 1] != '1') return "-1";
      ans += ((10 + t[j] - '0') - (s[i] - '0')) + '0';
      j--;
    }
    i--, j--;
  }
  if (i >= 0) return "-1";
  while (j >= 0) {
    ans += t[j];
    j--;
  }
  removing_leading_zeros(ans);
  reverse(ans.begin(), ans.end());
  return ans;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t;
  cin >> t;
  while (t--) {
    string a, s;
    cin >> a >> s;
    cout << res(a, s) << "\n";
  }
  return 0;
}
