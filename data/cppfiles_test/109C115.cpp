#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t != 0) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
      if ((s[i] - 48) != 0 && i != n - 1) {
        cnt += s[i] - 48 + 1;
      } else if ((s[i] - 48) == 0 && i != n - 1) {
      } else {
        cnt += s[i] - 48;
      }
    }
    cout << cnt << endl;
    t--;
  }
  return 0;
}
