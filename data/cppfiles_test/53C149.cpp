#include <bits/stdc++.h>
using namespace std;
bool f, r;
int main() {
  int T;
  cin >> T;
  while (T--) {
    int n;
    char c;
    f = false;
    r = false;
    string str;
    cin >> n >> c >> str;
    for (int i = 0; i < n; i++) {
      if (str[i] != c) {
        f = true;
        break;
      }
    }
    int res = -1;
    for (int i = n / 2; i < n; i++) {
      if (str[i] == c) {
        res = i;
        break;
      }
    }
    if (f) {
      if (res < 0) {
        printf("2\n%d %d\n", n, n - 1);
      } else {
        printf("1\n%d\n", res + 1);
      }
    } else {
      printf("0\n");
    }
  }
  return 0;
}
