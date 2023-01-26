#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    string x1, x2;
    int p1, p2;
    cin >> x1;
    cin >> p1;
    cin >> x2;
    cin >> p2;
    int mn = min(p1, p2);
    p1 -= mn;
    p2 -= mn;
    if (p1 >= 7) {
      cout << ">" << endl;
    } else if (p2 >= 7) {
      cout << "<" << endl;
    } else {
      while (p1--) {
        x1.push_back('0');
      }
      while (p2--) {
        x2.push_back('0');
      }
      if ((stoll(x1)) > (stoll(x2))) {
        cout << ">"
             << "\n";
      } else if ((stoll(x1)) < (stoll(x2))) {
        cout << "<"
             << "\n";
      } else {
        cout << "="
             << "\n";
      }
    }
  }
}
