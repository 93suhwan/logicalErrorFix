#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, n, cnt;
  cin >> t;
  while (t--) {
    cin >> n;
    string s;
    cin >> s;
    cnt = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] != '0') {
        cnt += s[i] - '0';
        if (i != n - 1) cnt++;
      }
    }
    cout << cnt << endl;
  }
  return 0;
}
