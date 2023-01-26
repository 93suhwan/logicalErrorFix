#include <bits/stdc++.h>
using namespace std;
char s[100010];
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    cin >> s + 1;
    int z = 0, o = 0, flag;
    for (int i = 1; i <= n; i++) {
      if (s[i] == '0')
        z++;
      else
        o++;
      if (s[i] == '0' && i > n / 2) {
        cout << 1 << " " << i << " " << 1 << " " << i - 1 << endl;
        break;
      } else if (s[i] == '0' && i <= n / 2) {
        cout << i << " " << n << " " << i + 1 << " " << n << endl;
        break;
      }
    }
    if (o == n || z == n) {
      cout << 1 << " " << n - 1 << " " << 2 << " " << n << endl;
    }
  }
  return 0;
}
