#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int x1, y1;
    cin >> x1 >> y1;
    int x2, y2;
    cin >> x2 >> y2;
    if (to_string(x1).length() + y1 > to_string(x2).length() + y2) puts(">");
    if (to_string(x1).length() + y1 < to_string(x2).length() + y2) puts("<");
    if (to_string(x1).length() + y1 == to_string(x2).length() + y2) {
      if (y1 > y2) {
        string s = to_string(x1);
        for (int i = 0; i < y1 - y2; i++) {
          s += "0";
        }
        x1 = stoi(s);
        if (x1 > x2)
          puts(">");
        else if (x1 < x2)
          puts("<");
        else
          puts("=");
      } else if (y1 < y2) {
        string s = to_string(x2);
        for (int i = 0; i < y2 - y1; i++) {
          s += "0";
        }
        x2 = stoi(s);
        if (x1 > x2)
          puts(">");
        else if (x1 < x2)
          puts("<");
        else
          puts("=");
      } else {
        if (x1 > x2)
          puts(">");
        else if (x1 < x2)
          puts("<");
        else
          puts("=");
      }
    }
  }
}
