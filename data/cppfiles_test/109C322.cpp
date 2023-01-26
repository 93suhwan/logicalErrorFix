#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    char s[110];
    int n, ret = 0, cnt = 0;
    cin >> n;
    cin >> s;
    for (int i = 0; s[i]; i++) {
      ret += s[i] - 48;
      if (s[i] != '0') {
        cnt++;
      }
    }
    if (s[n - 1] != '0') {
      ret += (cnt - 1);
    } else {
      ret += cnt;
    }
    cout << ret << endl;
  }
  return 0;
}
