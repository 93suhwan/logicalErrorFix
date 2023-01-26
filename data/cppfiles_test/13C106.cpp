#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    long long n = s.size();
    long long a = 0, b = 0, c = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] == 'A') {
        a++;
      } else if (s[i] == 'B') {
        b++;
      } else {
        c++;
      }
    }
    if (b == 0) {
      cout << "NO" << endl;
      continue;
    }
    if (a == 0 && b == c) {
      cout << "YES" << endl;
      continue;
    }
    if (b == 0 && a == c) {
      cout << "YES" << endl;
      continue;
    }
    if (c == 0 && b == a) {
      cout << "YES" << endl;
      continue;
    }
    if (a + c == b) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
  return 0;
}
