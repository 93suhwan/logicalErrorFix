#include <bits/stdc++.h>
using namespace std;
string findDiff(string str1, string str2) {
  string str = "";
  int n1 = str1.length(), n2 = str2.length();
  int diff = n1 - n2;
  int carry = 0;
  for (int i = n2 - 1; i >= 0; i--) {
    int sub = ((str1[i + diff] - '0') - (str2[i] - '0') - carry);
    if (sub < 0) {
      sub = sub + 10;
      carry = 1;
    } else
      carry = 0;
    str.push_back(sub + '0');
  }
  for (int i = n1 - n2 - 1; i >= 0; i--) {
    if (str1[i] == '0' && carry) {
      str.push_back('9');
      continue;
    }
    int sub = ((str1[i] - '0') - carry);
    if (i > 0 || sub > 0) str.push_back(sub + '0');
    carry = 0;
  }
  reverse(str.begin(), str.end());
  return str;
}
void solve() {
  string a, s, s1;
  cin >> a >> s;
  string ans;
  int j = a.length() - 1, i;
  for (i = s.length() - 1; i >= 0 && j >= 0;) {
    if (i < j) {
      cout << -1 << endl;
      return;
    }
    if (int(s[i]) >= int(a[j])) {
      ans = to_string(int(s[i] - a[j])) + ans;
      i--;
    } else {
      s1 = "";
      int l = (int(s[i - 1]) - 48) * 10;
      l += (int(s[i]) - 48);
      int diff = l - (int(a[j]) - 48);
      if (diff >= 10) {
        cout << "-1" << endl;
        return;
      } else {
        ans = to_string(diff) + ans;
      }
      i -= 2;
    }
    j--;
  }
  if (i >= 0) ans = s.substr(0, i + 1) + ans;
  int h;
  for (h = 0; h < ans.length(); h++) {
    if (ans[h] != '0') break;
  }
  string ans1 = "";
  for (int h1 = h; h1 < ans.length(); h1++) ans1 += ans[h1];
  cout << ans1 << endl;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
