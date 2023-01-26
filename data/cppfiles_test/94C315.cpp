#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  long long t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    string a, b;
    a = "";
    b = "";
    if (s.size() == 1) {
      cout << stoi(s) + 1 - 2 << "\n";
      continue;
    }
    for (long long i = 0; i < s.size(); i++) {
      if (i % 2 == 0) {
        a = a + s[i];
      } else {
        b = b + s[i];
      }
    }
    long long aa = stoi(a);
    long long bb = stoi(b);
    cout << (aa + 1) * (bb + 1) - 2 << "\n";
  }
}
