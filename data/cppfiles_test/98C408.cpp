#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  cin.ignore();
  while (t--) {
    string str1, str2;
    cin >> str1 >> str2;
    map<char, int> m;
    for (int i = 0; i < str1.length(); i++) {
      m.insert(pair<char, int>(str1[i], i));
    }
    if (str2.length() == 1) {
      cout << 0 << endl;
      continue;
    }
    int ch = 0;
    for (int i = 1; i < str2.length(); i++) {
      ch = ch + abs(m[str2[i]] - m[str2[i - 1]]);
    }
    cout << ch << endl;
  }
}
