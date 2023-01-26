#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int l1 = 0;
    int l2 = 0;
    int r1 = 0;
    int r2 = 0;
    for (int i = 0; i < s.length(); i++) {
      if (s[i] == '0') {
        l1 = i + 1;
        l2 = i + 2;
        r1 = s.length();
        r2 = s.length();
        break;
      }
    }
    if (r1 - l1 + 1 >= s.length() / 2 && r2 - l2 + 1 >= s.length() / 2) {
      cout << l2 << " " << r2 << " " << l1 << " " << r1 << "\n";
      continue;
    }
    for (int i = s.length() - 1; i >= 0; i--) {
      if (s[i] == '0') {
        r1 = i + 1;
        r2 = i;
        l1 = 1;
        l2 = 1;
        break;
      }
    }
    if (r1 - l1 + 1 >= s.length() / 2 && r2 - l2 + 1 >= s.length() / 2) {
      cout << l1 << " " << r1 << " " << l2 << " " << r2 << "\n";
      continue;
    }
    cout << "hi";
  }
}
