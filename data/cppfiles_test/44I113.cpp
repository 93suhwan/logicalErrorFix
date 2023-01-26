#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t > 0) {
    int s;
    int s2;
    cin >> s;
    cin >> s2;
    if (s == 0 && s2 == 0) {
      cout << "0"
           << "\n";
    } else if (s == s2) {
      cout << "1"
           << "\n";
    } else if ((s - s2) == 1 || (s2 - s) == 1) {
      cout << "-1"
           << "\n";
    } else {
      cout << "2"
           << "\n";
    }
    t--;
  }
}
