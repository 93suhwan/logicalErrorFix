#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int count1 = 0, count2 = 0, unknown1 = 0, unknown2 = 0;
    for (int i = 0; i < s.length(); i++) {
      int remaining = 9 - i, remaining1, remaining2;
      if (i % 2 == 0) {
        s[i] == '1' ? count1++ : s[i] == '?' && unknown1++;
        remaining1 = remaining / 2;
        remaining2 = remaining - remaining1;
      } else {
        s[i] == '1' ? count2++ : s[i] == '?' && unknown2++;
        remaining2 = remaining / 2;
        remaining1 = remaining - remaining2;
      }
      if (count1 + unknown1 > count2 + remaining2) {
        cout << i + 1 << '\n';
        break;
      } else if (count2 + unknown2 > count1 + remaining1) {
        cout << i + 1 << '\n';
        break;
      }
      if (i == 9) {
        cout << 10 << '\n';
      }
    }
  }
}
