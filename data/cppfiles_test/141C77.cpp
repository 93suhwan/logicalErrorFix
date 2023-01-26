#include <bits/stdc++.h>
using namespace std;
void solve() {
  string a;
  string s;
  cin >> a >> s;
  int ai = a.length() - 1, si = s.length() - 1;
  string answer = "";
  while (ai >= 0) {
    bool flag1 = false, flag2 = false;
    if (si >= 0) {
      flag1 = true;
      char temp = s[si];
      if (temp >= a[ai]) {
        int x = (int)temp - (int)a[ai];
        answer.push_back((char)('0' + x));
        --ai;
        --si;
        continue;
      }
    }
    if (si - 1 >= 0) {
      flag2 = true;
      if (s[si - 1] != '1') {
        cout << "-1\n";
        return;
      }
      int num = 10 + (int)(s[si] - '0');
      int temp = num - (int)(a[ai] - '0');
      while (temp > 0) {
        answer.push_back((char)(temp % 10 + '0'));
        temp = temp / 10;
      }
      --ai;
      si = si - 2;
    }
    if (!(flag1 && flag2)) {
      cout << "-1\n";
      return;
    }
  }
  while (si >= 0) {
    answer.push_back(s[si]);
    --si;
  }
  bool non_zero = false;
  for (int i = answer.length() - 1; i >= 0; --i) {
    if (answer[i] != '0') {
      cout << answer[i];
      non_zero = true;
    } else {
      if (non_zero) cout << "0";
    }
  }
  cout << endl;
}
int main() {
  long long t;
  cin >> t;
  while (t--) solve();
}
