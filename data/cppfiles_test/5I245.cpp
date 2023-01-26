#include <bits/stdc++.h>
using namespace std;
char c[1000000], d[1000000];
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int s = 0;
    for (int i = 1; i <= n; i++) {
      cin >> c[i];
    }
    for (int i = 1; i <= n; i++) {
      cin >> d[i];
      if (d[i] == '1') {
        if (c[i] == '0') {
          s++;
        } else if (c[i - 1] == '1') {
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
