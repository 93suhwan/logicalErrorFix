#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    string c, d;
    int n;
    cin >> n;
    int s = 0;
    cin >> c >> d;
    for (int i = 0; i < n; i++) {
      if (d[i] == '1') {
        if (c[i] == '0') {
          s++;
        } else if (i != 0 && c[i - 1] == '1') {
          s++;
        } else if (c[i + 1] == '1') {
          s++;
          c[i + 1] = '2';
        }
      }
    }
    cout << s << endl;
  }
  return 0;
}
