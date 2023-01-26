#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    string a, b, c;
    cin >> a;
    for (int i = 0; i < a.size(); i++) {
      if (i % 2) {
        b += a[i];
      } else {
        c += a[i];
      }
    }
    int qq = 0, qqq = 0;
    if (b.size() > 0) qq = stoi(b);
    if (c.size() > 0) qqq = stoi(c);
    cout << (qq + 1) * (qqq + 1) - 2 << '\n';
  }
  return 0;
}
