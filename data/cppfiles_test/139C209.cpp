#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int size = s.size();
    if (size % 2 != 0) {
      cout << "NO" << endl;
    } else {
      string sub1, sub2;
      sub1 = s.substr(0, size / 2);
      sub2 = s.substr(size / 2, size);
      if (sub1 == sub2) {
        cout << "YES" << endl;
      } else {
        cout << "NO" << endl;
      }
    }
  }
  return 0;
}
