#include <bits/stdc++.h>
using namespace std;
char seq[30], a[60];
string t;
int main() {
  int T;
  cin >> T;
  while (T--) {
    scanf("%s", &seq);
    scanf("%s", &a);
    int las = 0;
    int ans = 0;
    for (int i = 0; i < strlen(a); i++) {
      int j;
      for (j = 0; j < strlen(seq); j++) {
        if (seq[j] == a[i]) break;
      }
      if (i == 0)
        las = j;
      else {
        ans += abs(j - las);
        las = j;
      }
    }
    cout << ans << endl;
  }
  return 0;
}
