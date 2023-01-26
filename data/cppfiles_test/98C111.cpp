#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int a = s.find("ab");
    if (a >= 0) {
      cout << a + 1 << " " << a + 2 << endl;
    } else {
      int a = s.find("ba");
      if (a >= 0) {
        cout << a + 1 << " " << a + 2 << endl;
      } else {
        cout << "-1 -1" << endl;
      }
    }
  }
  return 0;
}
