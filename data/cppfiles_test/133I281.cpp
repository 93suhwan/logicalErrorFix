#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, flag = 0;
    string ch;
    cin >> n;
    string s[20];
    for (int i = 0; i < n - 2; i++) {
      cin >> s[i];
    }
    ch = s[0];
    for (int i = 0; i < n - 2; i++) {
      if (s[i][1] == s[i + 1][0]) {
        ch += s[i + 1][1];
      } else {
        ch += s[i + 1][0];
        flag = 1;
      }
    }
    ch = ch + s[n - 3];
    cout << ch << "\n";
  }
}
