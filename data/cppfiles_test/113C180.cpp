#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int x1, p1, x2, p2;
    cin >> x1 >> p1 >> x2 >> p2;
    string s1 = to_string(x1), s2 = to_string(x2);
    if (s1.size() + p1 > s2.size() + p2)
      cout << ">\n";
    else if (s1.size() + p1 < s2.size() + p2)
      cout << "<\n";
    else {
      while (s1.size() < s2.size()) s1 += '0';
      while (s2.size() < s1.size()) s2 += '0';
      if (s1 < s2)
        cout << "<\n";
      else if (s1 > s2)
        cout << ">\n";
      else
        cout << "=\n";
    }
  }
}
