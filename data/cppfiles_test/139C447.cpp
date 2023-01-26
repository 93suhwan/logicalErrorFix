#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t != 0) {
    string s;
    cin >> s;
    int mid;
    mid = s.length() / 2;
    if (s.length() % 2 != 0 && s.length() == 1) {
      cout << "NO" << endl;
    } else {
      if (s.substr(0, mid) == s.substr(mid, s.length() - 1)) {
        cout << "YES" << endl;
      } else
        cout << "NO" << endl;
    }
    t--;
  }
  return 0;
}
