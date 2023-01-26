#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int qq = 1;
  cin >> qq;
  for (int qqq = 0; qqq < qq; qqq++) {
    string a, b, s;
    cin >> a >> s;
    reverse(a.begin(), a.end());
    reverse(s.begin(), s.end());
    bool answer = true;
    int j = 0;
    for (int i = 0; i < a.size(); i++) {
      if (j >= s.size()) {
        answer = false;
        break;
      }
      if (s[j] >= a[i]) {
        b += '0' + s[j] - a[i];
        j++;
      } else {
        if (j + 1 < s.size() && s[j + 1] == '1') {
          b += '0' + s[j] + 10 - a[i];
          j += 2;
        } else {
          answer = false;
          break;
        }
      }
    }
    if (j != s.size()) {
      for (; j < s.size(); j++) {
        b += s[j];
      }
    }
    for (int i = b.size() - 1; i >= 0; i--) {
      if (b[i] != '0') {
        b.resize(i + 1);
        break;
      }
    }
    reverse(b.begin(), b.end());
    if (answer)
      cout << b;
    else
      cout << -1;
    cout << endl;
  }
  return 0;
}
