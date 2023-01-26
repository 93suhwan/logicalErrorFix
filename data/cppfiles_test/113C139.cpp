#include <bits/stdc++.h>
using namespace std;
int main() {
  int T;
  cin >> T;
  while (T--) {
    string x1;
    int p1;
    cin >> x1 >> p1;
    string x2;
    int p2;
    cin >> x2 >> p2;
    if (x1.size() + p1 < x2.size() + p2) {
      cout << "<" << endl;
      continue;
    }
    if (x1.size() + p1 == x2.size() + p2) {
      bool flag = true;
      for (int i = 0; i < x1.size() || i < x2.size(); ++i) {
        int a = 0;
        if (i < x1.size()) a = x1[i] - '0';
        int b = 0;
        if (i < x2.size()) b = x2[i] - '0';
        if (a < b) {
          cout << "<" << endl;
          flag = false;
          break;
        }
        if (a > b) {
          cout << ">" << endl;
          flag = false;
          break;
        }
      }
      if (flag) cout << "=" << endl;
      continue;
    }
    if (x1.size() + p1 > x2.size() + p2) {
      cout << ">" << endl;
      continue;
    }
  }
  return 0;
}
