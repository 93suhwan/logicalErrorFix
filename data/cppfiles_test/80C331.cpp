#include <bits/stdc++.h>
using namespace std;
int t, n;
char str[20005];
int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> t;
  while (t--) {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n >> str + 1;
    int len = strlen(str + 1);
    bool zai = false;
    for (int i = 1; i <= len; i++) {
      if (str[i] == '0') {
        if (i <= (len / 2)) {
          cout << i << " " << len << " " << i + 1 << " " << len << endl;
        } else {
          cout << 1 << " " << i << " " << 1 << " " << i - 1 << endl;
        }
        zai = true;
        break;
      }
    }
    if (!zai) {
      cout << 1 << " " << len / 2 << " " << 2 << " " << len / 2 + 1 << endl;
    }
  }
  return 0;
}
