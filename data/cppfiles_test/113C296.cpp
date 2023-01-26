#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.precision(15);
  cout << fixed;
  long long t, n, m, ans, i, j, k, l, sz;
  cin >> t;
  while (t--) {
    string a1, a2;
    int p1, p2;
    cin >> a1 >> p1 >> a2 >> p2;
    if (a1.size() + p1 == a2.size() + p2) {
      if (a1.size() > a2.size()) {
        while (a2.size() != a1.size()) a2 += '0';
        if (a1 > a2) {
          cout << ">\n";
        } else if (a1 < a2) {
          cout << "<\n";
        } else
          cout << "=\n";
      } else if (a1.size() < a2.size()) {
        while (a2.size() != a1.size()) a1 += '0';
        if (a1 > a2) {
          cout << ">\n";
        } else if (a1 < a2) {
          cout << "<\n";
        } else
          cout << "=\n";
      } else {
        if (a1 > a2) {
          cout << ">\n";
        } else if (a1 < a2) {
          cout << "<\n";
        } else
          cout << "=\n";
      }
    } else if (a1.size() + p1 > a2.size() + p2) {
      cout << ">"
           << "\n";
    } else {
      cout << "<"
           << "\n";
    }
  }
}
