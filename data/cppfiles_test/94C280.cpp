#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    string s, s1, s2;
    long long a, b;
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
      if (i % 2)
        s2 += s[i];
      else
        s1 += s[i];
    }
    a = stoi(s1);
    if (!s2.empty()) {
      b = stoi(s2);
      cout << (a + 1) * (b + 1) - 2 << '\n';
    } else
      cout << a - 1 << '\n';
  }
  return 0;
}
