#include <bits/stdc++.h>
using namespace std;
string s;
int main() {
  int t;
  cin >> t;
  while (t--) {
    for (int i = 1; i <= 8; i++) {
      for (int j = 1; j <= 8; j++) {
        printf("%d %d\n", i, (i & 1) ? j : 9 - j);
        cin >> s;
        if (s == "Done") {
          goto hhh;
        }
      }
    }
  hhh:;
  }
}
