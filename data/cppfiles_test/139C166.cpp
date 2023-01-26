#include <bits/stdc++.h>
using namespace std;
long long int t, n, i, l, k, j;
void out() {
  ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
  long long int m = 0;
  char s[105];
  cin >> s;
  l = strlen(s);
  if (l % 2 == 1) {
    cout << "NO" << endl;
  } else {
    k = (l / 2) - 1;
    for (i = 0, j = k + 1; i <= k, j <= l - 1; i++, j++) {
      if (s[i] != s[j]) {
        m++;
        break;
      }
    }
    if (m == 0) {
      cout << "YES" << endl;
      ;
    } else {
      cout << "NO" << endl;
      ;
    }
  }
};
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
  cin >> t;
  while (t--) {
    out();
  }
  return 0;
}
