#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int n = s.size();
    int a = 0;
    int b = 0;
    for (int i = 0; i < n; i++) {
      if (i % 2)
        a = a * 10 + s[i] - '0';
      else
        b = b * 10 + s[i] - '0';
    }
    cout << (a + 1) * (b + 1) - 2 << endl;
  }
  return 0;
}
