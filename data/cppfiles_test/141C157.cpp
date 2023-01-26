#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    string a, s;
    cin >> a >> s;
    long l1 = a.length();
    long l2 = s.length();
    long i = l1 - 1;
    long j = l2 - 1;
    string ans;
    bool flag = true;
    while (i >= 0 && j >= 0) {
      long val1 = a[i] - '0';
      long val2 = s[j] - '0';
      if (val1 <= val2) {
        long diff = val2 - val1;
        ans.push_back((char)('0' + diff));
        i--, j--;
      } else {
        j--;
        val2 += (10 * ((long)(s[j] - '0')));
        long diff = val2 - val1;
        if (diff > 9 || diff < 0) {
          flag = false;
          break;
        }
        ans.push_back((char)('0' + diff));
        i--, j--;
      }
    }
    if (!flag) {
      cout << -1 << endl;
      continue;
    }
    if (i >= 0) {
      flag = false;
    }
    if (!flag) {
      cout << -1 << endl;
      continue;
    }
    while (j >= 0) {
      ans.push_back(s[j--]);
    }
    while (ans.back() == '0') {
      ans.pop_back();
    }
    reverse(ans.begin(), ans.end());
    cout << ans << endl;
  }
}
