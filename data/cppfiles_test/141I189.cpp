#include <bits/stdc++.h>
using namespace std;
int main(int argc, char **argv) {
  int T;
  cin >> T;
  while (T-- != 0) {
    string a, s;
    cin >> a >> s;
    string b;
    for (int i = (int)a.length() - 1; i >= 0; --i) {
      if (s.empty()) {
        b = "-1";
        break;
      }
      char x = s.back();
      s.pop_back();
      if (x >= a[i]) {
        b += x - a[i] + '0';
        continue;
      }
      if (s.empty()) {
        b = "-1";
        break;
      }
      int y = (s.back() - '0') * 10 + x - '0';
      s.pop_back();
      int diff = y + '0' - a[i];
      if (diff > 9) {
        b = "-1";
        break;
      }
      b += diff + '0';
    }
    if (b != "-1") {
      while (!s.empty()) {
        b += s.back();
        s.pop_back();
      }
      while (!b.empty() && b.back() == '0') {
        b.pop_back();
      }
      if (b.empty()) {
        b = "0";
      }
      reverse(b.begin(), b.end());
    }
    cout << b << "\n";
  }
  return 0;
}
