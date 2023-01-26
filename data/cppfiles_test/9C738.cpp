#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    int a[100];
    cin >> s;
    memset(a, 0, sizeof(a));
    for (int i = 0; i < s.size(); i++) {
      int tt = s[i] - 96;
      a[tt]++;
    }
    int len = s.size();
    for (int i = 1; i <= 26; i++) {
      if (a[i] > 2) {
        len = len - a[i] + 2;
      }
    }
    cout << len / 2 << endl;
  }
  return 0;
}
