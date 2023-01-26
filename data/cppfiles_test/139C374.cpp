#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    string s;
    int m = 0;
    cin >> s;
    if ((s.size() % 2) != 0) {
      cout << "NO" << endl;
      continue;
    }
    for (int l = 0; l < s.size() / 2; l++) {
      if (s[l] != s[l + s.size() / 2]) {
        m++;
      }
    }
    if (m == 0) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
    m = 0;
  }
}
