#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  string a;
  cin >> a;
  int l = a.size();
  if (l % 2 == 0) {
    string s1, s2;
    s1 = a.substr(0, l / 2);
    s2 = a.substr(l / 2, l);
    if (s1 == s2) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  } else {
    cout << "NO" << endl;
  }
  return 0;
}
