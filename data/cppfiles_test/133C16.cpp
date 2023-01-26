#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string a[n - 2];
    for (int i = 0; i < n - 2; i++) {
      cin >> a[i];
    }
    bool flag = false;
    string p = a[0];
    string s = "";
    s += p[0];
    for (int i = 0; i < n - 3; i++) {
      string l = a[i], r = a[i + 1];
      if (l[1] == r[0]) {
        s = s + l[1];
      } else {
        flag = true;
        s = s + l[1] + r[0];
      }
    }
    p = a[n - 3];
    s = s + p[1];
    if (!flag) {
      s = s + 'a';
    }
    cout << s << endl;
  }
  return 0;
}
