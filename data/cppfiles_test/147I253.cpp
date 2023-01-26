#include <bits/stdc++.h>
using namespace std;
void in_it_code() {}
int main() {
  in_it_code();
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int a = s.size();
    if (a == 2) {
      if (s[0] == 'E' && s[1] == 'E') {
        cout << "YES" << endl;
      } else if (s[0] == 'N' && s[1] == 'N') {
        cout << "YES" << endl;
      } else {
        cout << "NO" << endl;
      }
    } else {
      cout << "YES" << endl;
    }
  }
  return 0;
}
