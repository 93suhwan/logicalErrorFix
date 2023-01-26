#include <bits/stdc++.h>
using namespace std;
bool l, r;
int main() {
  int T;
  cin >> T;
  while (T--) {
    int n;
    char c;
    l = false;
    r = false;
    string str;
    cin >> n >> c >> str;
    for (int i = 0; i < n; i++) {
      if ((i < n - 1) && str[i] != c) l = true;
      if (i == n - 1 && str[i] != c) r = true;
    }
    if (l && r)
      printf("2\n%d %d\n", n - 1, n);
    else if ((!l) && r)
      printf("1\n%d\n", n - 1);
    else if (l && (!r))
      printf("1\n%d\n", n);
    else if ((!l) && (!r))
      printf("0\n");
  }
  return 0;
}
