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
    int flag = 0;
    for (int i = 1; i <= n; i++) {
      if (s[i] == '0' && i > n / 2) {
        cout << 1 << " " << i - 1 << " " << 1 << " " << i << endl;
        break;
      } else if (s[i] == '0' && i <= n / 2) {
        cout << i << " " << n << " " << i + 1 << " " << n << endl;
        break;
      }
    }
  }
  return 0;
}
