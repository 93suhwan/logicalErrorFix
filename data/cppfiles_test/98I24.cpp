#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  cin.ignore();
  while (t--) {
    string str1, str2;
    int ch = 0;
    cin >> str1 >> str2;
    if (str2.length() == 1) {
      cout << 0 << endl;
      continue;
    }
    for (int i = 1; i < str2.length(); i++) {
      ch = ch + abs(str2[i] - str2[i - 1]);
    }
    cout << ch << endl;
  }
}
